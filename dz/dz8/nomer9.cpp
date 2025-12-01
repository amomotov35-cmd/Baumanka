// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>
// #include <sstream>
// #include <algorithm>

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

// void writeProductsCSV(const std::string& filename, const std::vector<Product>& products) {
//     std::ofstream file(filename);
//     file << "id,name,category,price,quantity\n";
    
//     for (const auto& p : products) {
//         file << p.id << ","
//              << p.name << ","
//              << p.category << ","
//              << p.price << ","
//              << p.quantity << "\n";
//     }
    
//     file.close();
// }

// int main() {
//     setlocale(LC_ALL, "rus");
//     auto products = readProductsCSV("products.csv");
    
//     std::cout << "Выберите критерий сортировки:\n";
//     std::cout << "1. По цене (от дешевых к дорогим)\n";
//     std::cout << "2. По цене (от дорогих к дешевым)\n";
//     std::cout << "3. По названию (А-Я)\n";
//     std::cout << "4. По количеству (больше-меньше)\n";
//     std::cout << "Ваш выбор: ";
    
//     int choice;
//     std::cin >> choice;
    
//     switch (choice) {
//         case 1: {
//             auto price_asc = [](const Product& a, const Product& b) { return a.price < b.price; };
//             std::sort(products.begin(), products.end(), price_asc);
//             break;
//         }
//         case 2: {
//             auto price_desc = [](const Product& a, const Product& b) { return a.price > b.price; };
//             std::sort(products.begin(), products.end(), price_desc);
//             break;
//         }
//         case 3: {
//             auto name_asc = [](const Product& a, const Product& b) { return a.name < b.name; };
//             std::sort(products.begin(), products.end(), name_asc);
//             break;
//         }
//         case 4: {
//             auto quantity_desc = [](const Product& a, const Product& b) { return a.quantity > b.quantity; };
//             std::sort(products.begin(), products.end(), quantity_desc);
//             break;
//         }
//     }
    
//     writeProductsCSV("sorted_products.csv", products);
    
//     std::cout << "Данные отсортированы и сохранены в sorted_products.csv\n";
    
//     std::cout << "\nПервые 5 товаров после сортировки:\n";
//     for (size_t i = 0; i < std::min(size_t(5), products.size()); ++i) {
//         const auto& p = products[i];
//         std::cout << p.id << ". " << p.name << " - " << p.price << " руб., " 
//                   << p.quantity << " шт.\n";
//     }
    
//     return 0;
// }