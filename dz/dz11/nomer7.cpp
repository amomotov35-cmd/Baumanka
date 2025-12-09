// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>
// #include <sstream>
// #include <iomanip>
// #include <algorithm>
// #include <numeric>

// struct Product {
//     int id;
//     std::string name;
//     std::string category;
//     double price;
//     int quantity;
// };

// std::vector<Product> readProductsCSV(const std::string& filename) {
//     std::vector<Product> products;
//     std::ifstream file(filename);
    
//     if (!file.is_open()) {
//         std::cerr << "Ошибка открытия файла: " << filename << std::endl;
//         return products;
//     }
    
//     std::string line;
//     std::getline(file, line);
    
//     while (std::getline(file, line)) {
//         std::stringstream ss(line);
//         std::string token;
//         Product p;
        
//         std::getline(ss, token, ',');
//         p.id = std::stoi(token);
        
//         std::getline(ss, p.name, ',');
//         std::getline(ss, p.category, ',');
        
//         std::getline(ss, token, ',');
//         p.price = std::stod(token);
        
//         std::getline(ss, token, ',');
//         p.quantity = std::stoi(token);
        
//         products.push_back(p);
//     }
    
//     file.close();
//     return products;
// }

// int main() {
//     setlocale(LC_ALL, "rus");

//     auto products = readProductsCSV("products.csv");
    
//     std::cout << "=== Список товаров ===\n";
//     std::cout << std::setw(3) << "ID" << " | "
//               << std::setw(20) << "Название" << " | "
//               << std::setw(15) << "Категория" << " | "
//               << std::setw(10) << "Цена" << " | "
//               << std::setw(10) << "Количество" << std::endl;
//     std::cout << std::string(70, '-') << std::endl;
    
//     for (const auto& p : products) {
//         std::cout << std::setw(3) << p.id << " | "
//                   << std::setw(20) << p.name << " | "
//                   << std::setw(15) << p.category << " | "
//                   << std::fixed << std::setprecision(2) << std::setw(10) << p.price << " | "
//                   << std::setw(10) << p.quantity << std::endl;
//     }
    
//     int totalQuantity = 0;
//     double totalValue = 0;
    
//     for (const auto& p : products) {
//         totalQuantity += p.quantity;
//         totalValue += p.price * p.quantity;
//     }
    
//     auto minPriceProduct = *std::min_element(products.begin(), products.end(),
//         [](const Product& a, const Product& b) { return a.price < b.price; });
    
//     auto maxPriceProduct = *std::max_element(products.begin(), products.end(),
//         [](const Product& a, const Product& b) { return a.price < b.price; });
    
//     std::cout << "\n=== Статистика ===\n";
//     std::cout << "Общее количество товаров на складе: " << totalQuantity << std::endl;
//     std::cout << "Суммарная стоимость всех товаров: " << std::fixed << std::setprecision(2) 
//               << totalValue << " руб." << std::endl;
//     std::cout << "Самый дешевый товар: " << minPriceProduct.name << " (" 
//               << minPriceProduct.price << " руб.)" << std::endl;
//     std::cout << "Самый дорогой товар: " << maxPriceProduct.name << " (" 
//               << maxPriceProduct.price << " руб.)" << std::endl;
    
//     return 0;
// }