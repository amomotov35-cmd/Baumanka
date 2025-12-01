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
//     auto allProducts = readProductsCSV("products.csv");
    
//     auto expensive_filter = [](const Product& p) { return p.price > 5000; };
//     auto electronics_filter = [](const Product& p) { return p.category == "Электроника"; };
//     auto quantity_filter = [](const Product& p) { return p.quantity > 10; };
    
//     std::vector<Product> filteredProducts;
    
//     std::copy_if(allProducts.begin(), allProducts.end(), 
//                 std::back_inserter(filteredProducts), expensive_filter);
    
//     writeProductsCSV("filtered_products.csv", filteredProducts);
    
//     std::cout << "Всего товаров: " << allProducts.size() << std::endl;
//     std::cout << "Отфильтрованных товаров: " << filteredProducts.size() << std::endl;
    
//     std::cout << "\nОтфильтрованные товары (дороже 5000 руб.):\n";
//     for (const auto& p : filteredProducts) {
//         std::cout << p.id << ". " << p.name << " - " << p.price << " руб.\n";
//     }
    
//     return 0;
// }