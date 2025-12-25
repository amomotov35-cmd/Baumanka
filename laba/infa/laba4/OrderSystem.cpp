#include <iostream>
#include <pqxx/pqxx>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>
#include <ctime>

// ==================== ШАБЛОННЫЙ КЛАСС ====================
template<typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(T1 f, T2 s) : first(f), second(s) {}

    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }

    void display() const {
        std::cout << first << " -> " << second;
    }
};

// ==================== БАЗОВЫЙ КЛАСС PRODUCT ====================
class Product {
protected:
    int id;
    std::string name;
    double price;
public:
    Product(int id, const std::string& name, double price)
        : id(id), name(name), price(price) {
    }

    virtual ~Product() {}

    virtual void display() const {
        std::cout << "ID: " << id << " | " << name
            << " | Price: $" << std::fixed << std::setprecision(2) << price;
    }

    virtual std::string getType() const { return "Basic"; }

    int getId() const { return id; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }
};

// ==================== ЦИФРОВОЙ ПРОДУКТ (ПОЛИМОРФИЗМ) ====================
class DigitalProduct : public Product {
private:
    std::string downloadLink;
    std::string licenseType;
public:
    DigitalProduct(int id, const std::string& name, double price,
        const std::string& link, const std::string& license)
        : Product(id, name, price), downloadLink(link), licenseType(license) {
    }

    void display() const override {
        Product::display();
        std::cout << " | Type: Digital | License: " << licenseType
            << " | Download: " << downloadLink;
    }

    std::string getType() const override { return "Digital"; }
};

// ==================== ФИЗИЧЕСКИЙ ПРОДУКТ (ПОЛИМОРФИЗМ) ====================
class PhysicalProduct : public Product {
private:
    double weight;
    std::string dimensions;
public:
    PhysicalProduct(int id, const std::string& name, double price,
        double weight, const std::string& dimensions)
        : Product(id, name, price), weight(weight), dimensions(dimensions) {
    }

    void display() const override {
        Product::display();
        std::cout << " | Type: Physical | Weight: " << weight
            << "kg | Dimensions: " << dimensions;
    }

    std::string getType() const override { return "Physical"; }
};

// ==================== ОСНОВНАЯ СИСТЕМА ====================
class OrderSystem {
private:
    std::unique_ptr<pqxx::connection> conn;
    std::ofstream logFile;

    void log(const std::string& message) {
        if (logFile.is_open()) {
            time_t now = time(0);
            char buf[80];
            struct tm timeinfo;
            localtime_s(&timeinfo, &now);
            strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &timeinfo);
            logFile << "[" << buf << "] " << message << std::endl;
        }
    }

    std::string getCurrentTime() {
        time_t now = time(0);
        char buf[80];
        struct tm timeinfo;
        localtime_s(&timeinfo, &now);
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &timeinfo);
        return buf;
    }

public:
    OrderSystem(const std::string& host, const std::string& user,
        const std::string& password) {
        std::string connStr = "dbname=sales_db user=" + user + " password=" + password +
            " host=" + host + " port=5432";

        std::cout << "Connecting to database..." << std::endl;
        try {
            conn = std::make_unique<pqxx::connection>(connStr);
            logFile.open("order_system.log", std::ios::app);

            if (conn->is_open()) {
                std::cout << "✓ Connected to database successfully!" << std::endl;
                log("System started at " + getCurrentTime());
            }
            else {
                std::cerr << "✗ Failed to connect to database!" << std::endl;
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Connection error: " << e.what() << std::endl;
        }
    }

    ~OrderSystem() {
        if (logFile.is_open()) {
            log("System stopped at " + getCurrentTime());
            logFile.close();
        }
    }

    bool isConnected() const {
        return conn && conn->is_open();
    }

    // ==================== ОПЕРАЦИИ С ТОВАРАМИ ====================
    void addBasicProduct() {
        std::string name;
        double price;

        std::cout << "\n=== Add Basic Product ===" << std::endl;
        std::cout << "Product name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Price: $";
        std::cin >> price;

        try {
            pqxx::work txn(*conn);
            std::string sql = "INSERT INTO products (name, price) VALUES (" +
                txn.quote(name) + ", " + txn.quote(price) + ") RETURNING id";

            pqxx::result res = txn.exec(sql);
            txn.commit();

            int newId = res[0][0].as<int>();
            std::cout << "✓ Product added! ID: " << newId << std::endl;
            log("Added basic product: " + name + " (ID: " + std::to_string(newId) + ")");
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void addDigitalProduct() {
        std::string name, downloadLink, licenseType;
        double price;

        std::cout << "\n=== Add Digital Product ===" << std::endl;
        std::cout << "Product name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Price: $";
        std::cin >> price;
        std::cin.ignore();
        std::cout << "Download link: ";
        std::getline(std::cin, downloadLink);
        std::cout << "License type: ";
        std::getline(std::cin, licenseType);

        try {
            pqxx::work txn(*conn);
            std::string sql = "INSERT INTO products (name, price) VALUES (" +
                txn.quote(name + " [Digital]") + ", " + txn.quote(price) + ") RETURNING id";

            pqxx::result res = txn.exec(sql);
            txn.commit();

            int newId = res[0][0].as<int>();
            std::cout << "✓ Digital product added! ID: " << newId << std::endl;
            log("Added digital product: " + name + " (ID: " + std::to_string(newId) + ")");
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void addPhysicalProduct() {
        std::string name, dimensions;
        double price, weight;

        std::cout << "\n=== Add Physical Product ===" << std::endl;
        std::cout << "Product name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Price: $";
        std::cin >> price;
        std::cout << "Weight (kg): ";
        std::cin >> weight;
        std::cin.ignore();
        std::cout << "Dimensions (LxWxH): ";
        std::getline(std::cin, dimensions);

        try {
            pqxx::work txn(*conn);
            std::string sql = "INSERT INTO products (name, price) VALUES (" +
                txn.quote(name + " [Physical]") + ", " + txn.quote(price) + ") RETURNING id";

            pqxx::result res = txn.exec(sql);
            txn.commit();

            int newId = res[0][0].as<int>();
            std::cout << "✓ Physical product added! ID: " << newId << std::endl;
            log("Added physical product: " + name + " (ID: " + std::to_string(newId) + ")");
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void displayAllProducts() {
        try {
            pqxx::work txn(*conn);
            pqxx::result res = txn.exec("SELECT * FROM products ORDER BY id");

            std::cout << "\n=== All Products ===" << std::endl;
            std::cout << std::string(70, '=') << std::endl;
            std::cout << std::left << std::setw(5) << "ID"
                << std::setw(30) << "Name"
                << std::setw(10) << "Price" << std::endl;
            std::cout << std::string(70, '-') << std::endl;

            for (const auto& row : res) {
                std::cout << std::left << std::setw(5) << row["id"].as<int>()
                    << std::setw(30) << row["name"].c_str()
                    << "$" << std::fixed << std::setprecision(2)
                    << row["price"].as<double>() << std::endl;
            }

            log("Displayed all products");
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    // ==================== ОПЕРАЦИИ С ЗАКАЗАМИ ====================
    void addOrder() {
        std::string date;
        std::cout << "\n=== Add New Order ===" << std::endl;
        std::cout << "Order date (YYYY-MM-DD) or Enter for today: ";
        std::cin.ignore();
        std::getline(std::cin, date);

        try {
            pqxx::work txn(*conn);
            std::string sql;
            if (date.empty()) {
                sql = "INSERT INTO orders (order_date) VALUES (CURRENT_DATE) RETURNING order_id";
            }
            else {
                sql = "INSERT INTO orders (order_date) VALUES (" + txn.quote(date) + ") RETURNING order_id";
            }

            pqxx::result res = txn.exec(sql);
            txn.commit();

            int orderId = res[0][0].as<int>();
            std::cout << "✓ Order created! Order ID: " << orderId << std::endl;
            log("Created order #" + std::to_string(orderId));
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void addOrderItem() {
        int orderId, productId, quantity;

        std::cout << "\n=== Add Item to Order ===" << std::endl;
        std::cout << "Order ID: ";
        std::cin >> orderId;
        std::cout << "Product ID: ";
        std::cin >> productId;
        std::cout << "Quantity: ";
        std::cin >> quantity;

        try {
            // Получаем цену товара
            pqxx::work txn(*conn);
            pqxx::result priceRes = txn.exec(
                "SELECT price FROM products WHERE id = " + txn.quote(productId)
            );

            if (priceRes.empty()) {
                std::cerr << "✗ Product not found!" << std::endl;
                return;
            }

            double price = priceRes[0]["price"].as<double>();
            double totalPrice = price * quantity;

            // Добавляем позицию в заказ
            std::string sql =
                "INSERT INTO order_items (order_id, product_id, quantity, total_price) VALUES (" +
                txn.quote(orderId) + ", " + txn.quote(productId) + ", " +
                txn.quote(quantity) + ", " + txn.quote(totalPrice) + ")";

            txn.exec(sql);
            txn.commit();

            std::cout << "✓ Item added to order! Total: $" << totalPrice << std::endl;
            log("Added item to order #" + std::to_string(orderId) +
                " - Product #" + std::to_string(productId) +
                " x" + std::to_string(quantity));
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void displayAllOrders() {
        try {
            pqxx::work txn(*conn);
            pqxx::result res = txn.exec(
                "SELECT o.order_id, o.order_date, "
                "COUNT(oi.order_item_id) as items, "
                "SUM(oi.total_price) as total "
                "FROM orders o "
                "LEFT JOIN order_items oi ON o.order_id = oi.order_id "
                "GROUP BY o.order_id, o.order_date "
                "ORDER BY o.order_id"
            );

            std::cout << "\n=== All Orders ===" << std::endl;
            std::cout << std::string(60, '=') << std::endl;
            std::cout << std::left << std::setw(10) << "Order ID"
                << std::setw(15) << "Date"
                << std::setw(10) << "Items"
                << std::setw(15) << "Total" << std::endl;
            std::cout << std::string(60, '-') << std::endl;

            for (const auto& row : res) {
                std::cout << std::left << std::setw(10) << row["order_id"].as<int>()
                    << std::setw(15) << row["order_date"].c_str()
                    << std::setw(10) << row["items"].as<int>()
                    << "$" << std::fixed << std::setprecision(2)
                    << row["total"].as<double>() << std::endl;
            }

            log("Displayed all orders");
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    // ==================== АНАЛИТИЧЕСКИЕ ЗАПРОСЫ ====================
    void revenueByProduct() {
        try {
            pqxx::work txn(*conn);
            pqxx::result res = txn.exec(
                "SELECT p.name, SUM(oi.total_price) as revenue, SUM(oi.quantity) as sold "
                "FROM products p "
                "JOIN order_items oi ON p.id = oi.product_id "
                "GROUP BY p.id, p.name "
                "ORDER BY revenue DESC"
            );

            std::cout << "\n=== Revenue by Product ===" << std::endl;
            std::cout << std::string(70, '=') << std::endl;
            std::cout << std::left << std::setw(30) << "Product"
                << std::setw(20) << "Revenue"
                << std::setw(15) << "Units Sold" << std::endl;
            std::cout << std::string(70, '-') << std::endl;

            std::vector<Pair<std::string, double>> revenuePairs; // Используем шаблонный класс

            for (const auto& row : res) {
                std::string name = row["name"].c_str();
                double revenue = row["revenue"].as<double>();
                int sold = row["sold"].as<int>();

                revenuePairs.push_back(Pair<std::string, double>(name, revenue));

                std::cout << std::left << std::setw(30) << name
                    << "$" << std::fixed << std::setprecision(2) << std::setw(19) << revenue
                    << std::setw(15) << sold << std::endl;
            }

            // Демонстрация работы с шаблонным классом
            if (!revenuePairs.empty()) {
                std::cout << "\nTop revenue product: ";
                revenuePairs[0].display();
                std::cout << std::endl;
            }

            log("Generated revenue report");
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void topSellingProducts() {
        try {
            pqxx::work txn(*conn);
            pqxx::result res = txn.exec(
                "SELECT p.name, SUM(oi.quantity) as total_sold "
                "FROM products p "
                "JOIN order_items oi ON p.id = oi.product_id "
                "GROUP BY p.id, p.name "
                "ORDER BY total_sold DESC "
                "LIMIT 3"
            );

            std::cout << "\n=== Top 3 Selling Products ===" << std::endl;
            std::cout << std::string(50, '=') << std::endl;
            std::cout << std::left << std::setw(5) << "Rank"
                << std::setw(30) << "Product"
                << std::setw(15) << "Units Sold" << std::endl;
            std::cout << std::string(50, '-') << std::endl;

            int rank = 1;
            for (const auto& row : res) {
                std::cout << std::left << std::setw(5) << rank++
                    << std::setw(30) << row["name"].c_str()
                    << std::setw(15) << row["total_sold"].as<int>() << std::endl;
            }

            log("Generated top selling products report");
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void averageOrderValue() {
        try {
            pqxx::work txn(*conn);
            pqxx::result res = txn.exec(
                "SELECT AVG(order_total) as avg_value FROM ("
                "SELECT SUM(total_price) as order_total "
                "FROM order_items "
                "GROUP BY order_id"
                ") as order_totals"
            );

            double avgValue = res[0]["avg_value"].as<double>();
            std::cout << "\n=== Average Order Value ===" << std::endl;
            std::cout << std::string(30, '=') << std::endl;
            std::cout << "Average: $" << std::fixed << std::setprecision(2) << avgValue << std::endl;

            log("Average order value: $" + std::to_string(avgValue));
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void orderCountByProduct() {
        try {
            pqxx::work txn(*conn);
            pqxx::result res = txn.exec(
                "SELECT p.name, COUNT(DISTINCT oi.order_id) as order_count "
                "FROM products p "
                "LEFT JOIN order_items oi ON p.id = oi.product_id "
                "GROUP BY p.id, p.name "
                "ORDER BY order_count DESC"
            );

            std::cout << "\n=== Order Count by Product ===" << std::endl;
            std::cout << std::string(50, '=') << std::endl;
            std::cout << std::left << std::setw(30) << "Product"
                << std::setw(20) << "Order Count" << std::endl;
            std::cout << std::string(50, '-') << std::endl;

            for (const auto& row : res) {
                std::cout << std::left << std::setw(30) << row["name"].c_str()
                    << std::setw(20) << row["order_count"].as<int>() << std::endl;
            }

            log("Generated order count report");
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    // ==================== ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА ====================
    void demoPolymorphism() {
        std::cout << "\n=== Polymorphism Demo ===" << std::endl;
        std::cout << std::string(50, '=') << std::endl;

        // Создаем разные типы продуктов
        Product* basic = new Product(1, "Basic Product", 19.99);
        Product* digital = new DigitalProduct(2, "E-Book", 9.99,
            "https://download.com/ebook", "Standard License");
        Product* physical = new PhysicalProduct(3, "Gadget", 49.99, 0.5, "10x5x2 cm");

        // Вектор указателей на базовый класс
        std::vector<Product*> products;
        products.push_back(basic);
        products.push_back(digital);
        products.push_back(physical);

        // Демонстрация полиморфизма
        std::cout << "Displaying products using polymorphism:" << std::endl;
        for (Product* product : products) {
            product->display();
            std::cout << " | Type: " << product->getType() << std::endl;
        }

        // Очистка памяти
        delete basic;
        delete digital;
        delete physical;

        std::cout << "\nPolymorphism demo completed!" << std::endl;
    }
};

// ==================== МЕНЮ ====================
void displayMenu() {
    std::cout << "\n=== ORDER MANAGEMENT SYSTEM ===" << std::endl;
    std::cout << "1. Add Basic Product" << std::endl;
    std::cout << "2. Add Digital Product" << std::endl;
    std::cout << "3. Add Physical Product" << std::endl;
    std::cout << "4. View All Products" << std::endl;
    std::cout << "5. Create New Order" << std::endl;
    std::cout << "6. Add Item to Order" << std::endl;
    std::cout << "7. View All Orders" << std::endl;
    std::cout << "8. Revenue by Product" << std::endl;
    std::cout << "9. Top Selling Products" << std::endl;
    std::cout << "10. Average Order Value" << std::endl;
    std::cout << "11. Order Count by Product" << std::endl;
    std::cout << "12. Demo Polymorphism" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Enter choice: ";
}

int main() {
    std::cout << "=== ORDER MANAGEMENT SYSTEM ===" << std::endl;
    std::cout << "Please enter database credentials:" << std::endl;

    std::string host, user, password;
    std::cout << "Host [localhost]: ";
    std::getline(std::cin, host);
    if (host.empty()) host = "localhost";

    std::cout << "Username [postgres]: ";
    std::getline(std::cin, user);
    if (user.empty()) user = "postgres";

    std::cout << "Password: ";
    std::getline(std::cin, password);

    // Создаем систему
    OrderSystem system(host, user, password);

    if (!system.isConnected()) {
        std::cerr << "\n✗ Failed to connect to database!" << std::endl;
        std::cerr << "Please ensure:" << std::endl;
        std::cerr << "1. PostgreSQL is running" << std::endl;
        std::cerr << "2. Database 'sales_db' exists (run init_database.exe first)" << std::endl;
        std::cerr << "3. Credentials are correct" << std::endl;
        std::cout << "\nPress Enter to exit...";
        std::cin.get();
        return 1;
    }

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: system.addBasicProduct(); break;
        case 2: system.addDigitalProduct(); break;
        case 3: system.addPhysicalProduct(); break;
        case 4: system.displayAllProducts(); break;
        case 5: system.addOrder(); break;
        case 6: system.addOrderItem(); break;
        case 7: system.displayAllOrders(); break;
        case 8: system.revenueByProduct(); break;
        case 9: system.topSellingProducts(); break;
        case 10: system.averageOrderValue(); break;
        case 11: system.orderCountByProduct(); break;
        case 12: system.demoPolymorphism(); break;
        case 0: std::cout << "Goodbye!" << std::endl; break;
        default: std::cout << "Invalid choice!" << std::endl;
        }

    } while (choice != 0);

    return 0;
}