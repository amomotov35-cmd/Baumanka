#include "OrderSystem.h"
#include <iostream>
#include <limits>

void displayMenu() {
    std::cout << "\n=== Order Management System ===" << std::endl;
    std::cout << "1. Add Basic Product" << std::endl;
    std::cout << "2. Add Digital Product" << std::endl;
    std::cout << "3. Add Physical Product" << std::endl;
    std::cout << "4. View All Products" << std::endl;
    std::cout << "5. Add Order" << std::endl;
    std::cout << "6. Add Item to Order" << std::endl;
    std::cout << "7. View All Orders" << std::endl;
    std::cout << "8. View Order Items" << std::endl;
    std::cout << "9. Revenue by Product" << std::endl;
    std::cout << "10. Top Selling Products" << std::endl;
    std::cout << "11. Average Order Value" << std::endl;
    std::cout << "12. Order Count by Product" << std::endl;
    std::cout << "13. Demo Template Class" << std::endl;
    std::cout << "14. Demo Polymorphism" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

void demoTemplateClass() {
    std::cout << "\n=== Template Class Demo ===" << std::endl;

    // Использование шаблонного класса Pair
    Pair<std::string, int> productSales("Laptop", 150);
    std::cout << "Product Sales Pair: ";
    productSales.display();
    std::cout << std::endl;

    Pair<std::string, double> productRevenue("Laptop", 225000.50);
    std::cout << "Product Revenue Pair: ";
    productRevenue.display();
    std::cout << std::endl;

    // Массив пар для хранения данных о продажах
    std::vector<Pair<std::string, int>> salesData;
    salesData.push_back(Pair<std::string, int>("Laptop", 150));
    salesData.push_back(Pair<std::string, int>("Phone", 300));
    salesData.push_back(Pair<std::string, int>("Headphones", 500));

    std::cout << "\nSales Data:" << std::endl;
    for (const auto& pair : salesData) {
        std::cout << "Product: " << pair.getFirst()
            << ", Units Sold: " << pair.getSecond() << std::endl;
    }
}

void demoPolymorphism() {
    std::cout << "\n=== Polymorphism Demo ===" << std::endl;

    // Создание разных типов продуктов
    Product* basicProduct = new Product(1, "Basic Item", 19.99);
    Product* digitalProduct = new DigitalProduct(2, "E-Book", 9.99,
        "https://download.com/ebook", "LIC-12345");
    Product* physicalProduct = new PhysicalProduct(3, "Gadget", 49.99, 0.5,
        "10x5x2 cm", "Express Shipping");

    // Демонстрация полиморфизма
    std::vector<Product*> products;
    products.push_back(basicProduct);
    products.push_back(digitalProduct);
    products.push_back(physicalProduct);

    std::cout << "Displaying all products using polymorphism:" << std::endl;
    for (Product* product : products) {
        product->display();  // Вызовется правильная версия display()
    }

    // Очистка памяти
    delete basicProduct;
    delete digitalProduct;
    delete physicalProduct;
}

int main() {
    // Строка подключения к PostgreSQL
    // Замените параметры на свои
    std::string connStr = "dbname=sales_db user=postgres password=your_password host=localhost port=5432";

    OrderSystem system(connStr);

    if (!system.connect()) {
        std::cerr << "Failed to connect to database!" << std::endl;
        return 1;
    }

    std::cout << "Connected to database successfully!" << std::endl;

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        // Очистка буфера ввода
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            std::string name;
            double price;

            std::cout << "Enter product name: ";
            std::getline(std::cin, name);
            std::cout << "Enter product price: ";
            std::cin >> price;
            std::cin.ignore();

            system.addProduct(name, price);
            break;
        }
        case 2: {
            std::string name, downloadLink, licenseKey;
            double price;

            std::cout << "Enter digital product name: ";
            std::getline(std::cin, name);
            std::cout << "Enter price: ";
            std::cin >> price;
            std::cin.ignore();
            std::cout << "Enter download link: ";
            std::getline(std::cin, downloadLink);
            std::cout << "Enter license key: ";
            std::getline(std::cin, licenseKey);

            system.addDigitalProduct(name, price, downloadLink, licenseKey);
            break;
        }
        case 3: {
            std::string name, dimensions, shippingMethod;
            double price, weight;

            std::cout << "Enter physical product name: ";
            std::getline(std::cin, name);
            std::cout << "Enter price: ";
            std::cin >> price;
            std::cout << "Enter weight (kg): ";
            std::cin >> weight;
            std::cin.ignore();
            std::cout << "Enter dimensions: ";
            std::getline(std::cin, dimensions);
            std::cout << "Enter shipping method: ";
            std::getline(std::cin, shippingMethod);

            system.addPhysicalProduct(name, price, weight, dimensions, shippingMethod);
            break;
        }
        case 4:
            system.displayAllProducts();
            break;
        case 5: {
            std::string date;
            std::cout << "Enter order date (YYYY-MM-DD) or press