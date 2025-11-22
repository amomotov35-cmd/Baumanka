#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

struct Product {
    string name;
    int quantity;
    double price;
    
    Product(const string& n = "", int q = 0, double p = 0.0) 
        : name(n), quantity(q), price(p) {}
};

void writeToOutput(const string& message) {
    ofstream outputFile("output.txt", ios::app);
    if (outputFile.is_open()) {
        outputFile << message << endl;
        outputFile.close();
    }
}

vector<Product> readProductsFromFile() {
    vector<Product> products;
    ifstream inputFile("orders.txt");
    
    if (inputFile.is_open()) {
        Product product;
        while (inputFile >> ws && getline(inputFile, product.name, ',') &&
               inputFile >> product.quantity >> ws >> product.price) {
            products.push_back(product);
        }
        inputFile.close();
    }
    
    return products;
}

void writeProductsToFile(const vector<Product>& products) {
    ofstream outputFile("orders.txt");
    
    if (outputFile.is_open()) {
        for (const auto& product : products) {
            outputFile << product.name << "," << product.quantity << " " << product.price << endl;
        }
        outputFile.close();
    }
}

void addProducts() {
    ofstream file("orders.txt", ios::app);
    
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    
    cout << "Введите данные о товарах (для завершения введите пустую строку в названии):" << endl;
    writeToOutput("Добавление новых товаров:");
    
    while (true) {
        string name;
        int quantity;
        double price;
        
        cout << "Название товара: ";
        getline(cin, name);
        
        if (name.empty()) {
            break;
        }
        
        cout << "Количество единиц: ";
        cin >> quantity;
        
        cout << "Цена за единицу: ";
        cin >> price;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        file << name << "," << quantity << " " << price << endl;
        
        string message = "Добавлен товар: " + name + ", количество: " + to_string(quantity) + 
                        ", цена: " + to_string(price);
        writeToOutput(message);
        
        cout << "Товар добавлен!" << endl;
    }
    
    file.close();
}

void searchProduct() {
    string searchName;
    cout << "Введите название товара для поиска: ";
    getline(cin, searchName);
    
    vector<Product> products = readProductsFromFile();
    bool found = false;
    
    writeToOutput("Поиск товара: " + searchName);
    
    for (const auto& product : products) {
        if (product.name == searchName) {
            cout << "Найден товар: " << product.name 
                 << ", количество: " << product.quantity 
                 << ", цена: " << product.price << endl;
            
            string message = "Результат поиска: " + product.name + ", количество: " + 
                           to_string(product.quantity) + ", цена: " + to_string(product.price);
            writeToOutput(message);
            
            found = true;
        }
    }
    
    if (!found) {
        cout << "Товар не найден!" << endl;
        writeToOutput("Товар не найден!");
    }
}

bool compareByName(const Product& a, const Product& b) {
    return a.name < b.name;
}

bool compareByQuantity(const Product& a, const Product& b) {
    return a.quantity < b.quantity;
}

bool compareByPrice(const Product& a, const Product& b) {
    return a.price < b.price;
}

void sortProducts() {
    vector<Product> products = readProductsFromFile();
    
    if (products.empty()) {
        cout << "Нет данных для сортировки!" << endl;
        return;
    }
    
    cout << "Выберите критерий сортировки:" << endl;
    cout << "1 - по названию" << endl;
    cout << "2 - по количеству" << endl;
    cout << "3 - по цене" << endl;
    
    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    switch (choice) {
        case 1:
            sort(products.begin(), products.end(), compareByName);
            writeToOutput("Сортировка по названию");
            break;
        case 2:
            sort(products.begin(), products.end(), compareByQuantity);
            writeToOutput("Сортировка по количеству");
            break;
        case 3:
            sort(products.begin(), products.end(), compareByPrice);
            writeToOutput("Сортировка по цене");
            break;
        default:
            cout << "Неверный выбор!" << endl;
            return;
    }
    
    cout << "Отсортированные товары:" << endl;
    cout << setw(20) << left << "Название" 
         << setw(10) << "Количество" 
         << setw(10) << "Цена" << endl;
    
    writeToOutput("Отсортированные товары:");
    
    for (const auto& product : products) {
        cout << setw(20) << left << product.name 
             << setw(10) << product.quantity 
             << setw(10) << product.price << endl;
             
        string message = product.name + ", количество: " + to_string(product.quantity) + 
                        ", цена: " + to_string(product.price);
        writeToOutput(message);
    }
    
    writeProductsToFile(products);
}

void addSingleProduct() {
    ofstream file("orders.txt", ios::app);
    
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    
    string name;
    int quantity;
    double price;
    
    cout << "Введите данные о новом товаре:" << endl;
    cout << "Название товара: ";
    getline(cin, name);
    
    cout << "Количество единиц: ";
    cin >> quantity;
    
    cout << "Цена за единицу: ";
    cin >> price;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    file << name << "," << quantity << " " << price << endl;
    file.close();
    
    string message = "Добавлен новый товар: " + name + ", количество: " + 
                    to_string(quantity) + ", цена: " + to_string(price);
    writeToOutput(message);
    
    cout << "Товар успешно добавлен!" << endl;
}

void displayProductsByPrice() {
    double maxPrice;
    cout << "Введите максимальную цену: ";
    cin >> maxPrice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    vector<Product> products = readProductsFromFile();
    bool found = false;
    
    cout << "Товары с ценой до " << maxPrice << ":" << endl;
    writeToOutput("Запрос товаров с ценой до: " + to_string(maxPrice));
    
    for (const auto& product : products) {
        if (product.price <= maxPrice) {
            cout << "Товар: " << product.name 
                 << ", количество: " << product.quantity 
                 << ", цена: " << product.price << endl;
                 
            string message = "Найден товар: " + product.name + ", количество: " + 
                           to_string(product.quantity) + ", цена: " + to_string(product.price);
            writeToOutput(message);
            
            found = true;
        }
    }
    
    if (!found) {
        cout << "Товары не найдены!" << endl;
        writeToOutput("Товары не найдены!");
    }
}


void displayAllProducts() {
    vector<Product> products = readProductsFromFile();
    
    if (products.empty()) {
        cout << "Нет данных о товарах!" << endl;
        return;
    }
    
    cout << "Все товары:" << endl;
    cout << setw(20) << left << "Название" 
         << setw(10) << "Количество" 
         << setw(10) << "Цена" << endl;
    
    writeToOutput("Вывод всех товаров:");
    
    for (const auto& product : products) {
        cout << setw(20) << left << product.name 
             << setw(10) << product.quantity 
             << setw(10) << product.price << endl;
             
        string message = product.name + ", количество: " + to_string(product.quantity) + 
                        ", цена: " + to_string(product.price);
        writeToOutput(message);
    }
}

void showMenu() {
    cout << "\n=== Меню управления заказами ===" << endl;
    cout << "1 - Добавить несколько товаров" << endl;
    cout << "2 - Поиск товара по названию" << endl;
    cout << "3 - Сортировка товаров" << endl;
    cout << "4 - Добавить один товар" << endl;
    cout << "5 - Вывод товаров по цене" << endl;
    cout << "6 - Вывод всех товаров" << endl;
    cout << "0 - Выход" << endl;
    cout << "Выберите действие: ";
}

int main() {
    
    ofstream clearFile("output.txt");
    clearFile.close();
    
    int choice;
    
    do {
        showMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (choice) {
            case 1:
                addProducts();
                break;
            case 2:
                searchProduct();
                break;
            case 3:
                sortProducts();
                break;
            case 4:
                addSingleProduct();
                break;
            case 5:
                displayProductsByPrice();
                break;
            case 6:
                displayAllProducts();
                break;
            case 0:
                cout << "Выход из программы..." << endl;
                writeToOutput("Завершение работы программы");
                break;
            default:
                cout << "Неверный выбор!" << endl;
        }
        
    } while (choice != 0);
    
    return 0;
}