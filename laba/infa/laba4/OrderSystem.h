#ifndef ORDERSYSTEM_H
#define ORDERSYSTEM_H

#include <pqxx/pqxx>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <string>
#include <ctime>

// Шаблонный класс Pair
template<typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(T1 f, T2 s) : first(f), second(s) {}

    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }

    void setFirst(T1 f) { first = f; }
    void setSecond(T2 s) { second = s; }

    void display() const {
        std::cout << "(" << first << ", " << second << ")";
    }
};

// Базовый класс Product
class Product {
protected:
    int id;
    std::string name;
    double price;
public:
    Product(int id, const std::string& name, double price);
    virtual ~Product() {}

    virtual void display() const;
    virtual std::string getType() const { return "Basic"; }

    int getId() const { return id; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }

    void setName(const std::string& name) { this->name = name; }
    void setPrice(double price) { this->price = price; }
};

// Производный класс DigitalProduct
class DigitalProduct : public Product {
private:
    std::string downloadLink;
    std::string licenseKey;
public:
    DigitalProduct(int id, const std::string& name, double price,
        const std::string& downloadLink, const std::string& licenseKey);

    void display() const override;
    std::string getType() const override { return "Digital"; }

    std::string getDownloadLink() const { return downloadLink; }
    std::string getLicenseKey() const { return licenseKey; }
};

// Производный класс PhysicalProduct
class PhysicalProduct : public Product {
private:
    double weight;
    std::string dimensions;
    std::string shippingMethod;
public:
    PhysicalProduct(int id, const std::string& name, double price,
        double weight, const std::string& dimensions,
        const std::string& shippingMethod);

    void display() const override;
    std::string getType() const override { return "Physical"; }

    double getWeight() const { return weight; }
    std::string getDimensions() const { return dimensions; }
    std::string getShippingMethod() const { return shippingMethod; }
};

// Класс Order
class Order {
private:
    int orderId;
    std::string orderDate;
public:
    Order(int orderId, const std::string& orderDate);

    void display() const;

    int getOrderId() const { return orderId; }
    std::string getOrderDate() const { return orderDate; }
};

// Класс OrderItem
class OrderItem {
private:
    int orderItemId;
    int orderId;
    int productId;
    int quantity;
    double totalPrice;
public:
    OrderItem(int orderItemId, int orderId, int productId, int quantity, double totalPrice);

    void display() const;

    int getOrderItemId() const { return orderItemId; }
    int getOrderId() const { return orderId; }
    int getProductId() const { return productId; }
    int getQuantity() const { return quantity; }
    double getTotalPrice() const { return totalPrice; }
};

// Главный класс системы
class OrderSystem {
private:
    std::unique_ptr<pqxx::connection> conn;
    std::ofstream logFile;

    void log(const std::string& message);
    std::string getCurrentDateTime();

public:
    OrderSystem(const std::string& connStr);
    ~OrderSystem();

    bool connect();
    void close();

    // Операции с товарами
    void addProduct(const std::string& name, double price);
    void addDigitalProduct(const std::string& name, double price,
        const std::string& downloadLink, const std::string& licenseKey);
    void addPhysicalProduct(const std::string& name, double price,
        double weight, const std::string& dimensions,
        const std::string& shippingMethod);
    void displayAllProducts();
    std::vector<std::shared_ptr<Product>> getAllProducts();

    // Операции с заказами
    void addOrder(const std::string& date = "");
    void addOrderItem(int orderId, int productId, int quantity);
    void displayAllOrders();
    void displayOrderItems(int orderId);

    // Аналитические запросы
    void getRevenueByProduct();
    void getTopSellingProducts();
    void getAverageOrderValue();
    void getOrderCountByProduct();

    // Утилиты
    bool productExists(int productId);
    bool orderExists(int orderId);
    double getProductPrice(int productId);
};

#endif