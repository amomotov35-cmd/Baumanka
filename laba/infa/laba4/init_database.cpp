#include <iostream>
#include <pqxx/pqxx>
#include <string>

class DatabaseInitializer {
private:
    std::string host = "localhost";
    std::string port = "5432";
    std::string user = "postgres";
    std::string password;

    void getPassword() {
        std::cout << "Enter PostgreSQL password for user '" << user << "': ";
        std::cin >> password;
    }

public:
    void initialize() {
        std::cout << "=== PostgreSQL Database Initializer ===" << std::endl;
        std::cout << "This program will create the sales_db database and tables." << std::endl;
        std::cout << "Make sure PostgreSQL service is running!" << std::endl << std::endl;

        getPassword();

        try {
            // Шаг 1: Подключение к серверу PostgreSQL
            std::string connStr = "dbname=postgres user=" + user + " password=" + password +
                " host=" + host + " port=" + port;
            std::cout << "Connecting to PostgreSQL server..." << std::endl;

            pqxx::connection conn(connStr);
            if (!conn.is_open()) {
                std::cerr << "Failed to connect to PostgreSQL!" << std::endl;
                return;
            }
            std::cout << "Connected to PostgreSQL successfully!" << std::endl;

            // Шаг 2: Проверка и создание базы данных
            {
                std::cout << "Checking if database 'sales_db' exists..." << std::endl;
                pqxx::nontransaction ntxn(conn);

                pqxx::result res = ntxn.exec(
                    "SELECT 1 FROM pg_database WHERE datname = 'sales_db'"
                );

                if (res.empty()) {
                    std::cout << "Creating database 'sales_db'..." << std::endl;
                    ntxn.exec("CREATE DATABASE sales_db");
                    std::cout << "✓ Database 'sales_db' created successfully!" << std::endl;
                }
                else {
                    std::cout << "✓ Database 'sales_db' already exists." << std::endl;
                }
            }

            // Шаг 3: Подключение к новой базе данных и создание таблиц
            std::cout << std::endl << "Connecting to 'sales_db'..." << std::endl;
            std::string salesDbStr = "dbname=sales_db user=" + user + " password=" + password +
                " host=" + host + " port=" + port;

            pqxx::connection connSales(salesDbStr);
            if (!connSales.is_open()) {
                std::cerr << "Failed to connect to sales_db!" << std::endl;
                return;
            }
            std::cout << "Connected to sales_db successfully!" << std::endl;

            // Создание таблиц в транзакции
            {
                pqxx::work txn(connSales);
                std::cout << "Creating tables..." << std::endl;

                // Удаляем таблицы если они существуют (для чистого запуска)
                txn.exec("DROP TABLE IF EXISTS order_items CASCADE");
                txn.exec("DROP TABLE IF EXISTS orders CASCADE");
                txn.exec("DROP TABLE IF EXISTS products CASCADE");

                // Создаем таблицы
                txn.exec(R"(
                    CREATE TABLE products (
                        id SERIAL PRIMARY KEY,
                        name VARCHAR(255) NOT NULL,
                        price DECIMAL(10, 2) NOT NULL CHECK (price >= 0)
                    )
                )");

                txn.exec(R"(
                    CREATE TABLE orders (
                        order_id SERIAL PRIMARY KEY,
                        order_date DATE NOT NULL DEFAULT CURRENT_DATE
                    )
                )");

                txn.exec(R"(
                    CREATE TABLE order_items (
                        order_item_id SERIAL PRIMARY KEY,
                        order_id INTEGER NOT NULL,
                        product_id INTEGER NOT NULL,
                        quantity INTEGER NOT NULL CHECK (quantity > 0),
                        total_price DECIMAL(10, 2) NOT NULL CHECK (total_price >= 0),
                        FOREIGN KEY (order_id) REFERENCES orders(order_id) ON DELETE CASCADE,
                        FOREIGN KEY (product_id) REFERENCES products(id) ON DELETE CASCADE
                    )
                )");

                // Создаем индексы
                txn.exec("CREATE INDEX idx_order_date ON orders(order_date)");
                txn.exec("CREATE INDEX idx_product_id ON order_items(product_id)");

                // Вставляем тестовые данные
                std::cout << "Inserting test data..." << std::endl;

                txn.exec(R"(
                    INSERT INTO products (name, price) VALUES
                    ('Ноутбук', 1500.00),
                    ('Смартфон', 800.00),
                    ('Наушники', 150.00),
                    ('Клавиатура', 75.00),
                    ('Мышь', 45.00)
                )");

                txn.exec(R"(
                    INSERT INTO orders (order_date) VALUES
                    ('2024-01-15'),
                    ('2024-01-16'),
                    ('2024-01-17')
                )");

                txn.exec(R"(
                    INSERT INTO order_items (order_id, product_id, quantity, total_price) VALUES
                    (1, 1, 1, 1500.00),
                    (1, 3, 2, 300.00),
                    (2, 2, 1, 800.00),
                    (2, 4, 1, 75.00),
                    (2, 5, 2, 90.00),
                    (3, 3, 3, 450.00)
                )");

                txn.commit();
                std::cout << "✓ Tables created successfully!" << std::endl;
                std::cout << "✓ Test data inserted successfully!" << std::endl;
            }

            std::cout << std::endl << "==========================================" << std::endl;
            std::cout << "DATABASE INITIALIZATION COMPLETED SUCCESSFULLY!" << std::endl;
            std::cout << "You can now run the main Order Management System." << std::endl;
            std::cout << "==========================================" << std::endl;

        }
        catch (const pqxx::sql_error& e) {
            std::cerr << "SQL Error: " << e.what() << std::endl;
            std::cerr << "Query: " << e.query() << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
};

int main() {
    DatabaseInitializer initializer;
    initializer.initialize();

    // Пауза перед выходом
    std::cout << std::endl << "Press Enter to exit...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}