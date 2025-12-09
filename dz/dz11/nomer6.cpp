// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>
// #include <iomanip>
// #include <cstdlib>
// #include <ctime>

// struct Product {
//     int id;
//     std::string name;
//     std::string category;
//     double price;
//     int quantity;
// };

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::srand(std::time(nullptr));
    
//     std::vector<std::string> categories = {
//         "Электроника", "Аксессуары", "Одежда", "Книги", 
//         "Бытовая техника", "Спорт", "Красота"
//     };
    
//     std::vector<std::string> names = {
//         "Ноутбук", "Мышь", "Клавиатура", "Монитор", "Телефон",
//         "Наушники", "Футболка", "Джинсы", "Книга", "Чайник",
//         "Утюг", "Мяч", "Крем", "Шампунь", "Рюкзак"
//     };
    
//     std::ofstream csvFile("products.csv");
//     csvFile << "id,name,category,price,quantity\n";
    
//     for (int i = 1; i <= 20; ++i) {
//         Product p;
//         p.id = i;
//         p.name = names[std::rand() % names.size()] + " " + 
//                 std::to_string(100 + std::rand() % 900);
//         p.category = categories[std::rand() % categories.size()];
//         p.price = 100 + std::rand() % 9900;
//         p.quantity = 1 + std::rand() % 100;
        
//         csvFile << p.id << ","
//                 << p.name << ","
//                 << p.category << ","
//                 << std::fixed << std::setprecision(2) << p.price << ","
//                 << p.quantity << "\n";
//     }
    
//     csvFile.close();
    
//     std::ifstream checkFile("products.csv");
//     std::string line;
//     int lineCount = 0;
//     while (std::getline(checkFile, line)) {
//         lineCount++;
//     }
    
//     std::cout << "Файл products.csv создан.\n";
//     std::cout << "Количество строк: " << lineCount << std::endl;
//     std::cout << "Количество товаров: " << lineCount - 1 << std::endl;
    
//     return 0;
// }