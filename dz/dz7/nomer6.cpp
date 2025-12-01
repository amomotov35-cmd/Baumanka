// #include <iostream>
// #include <fstream>
// #include <string>

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::ofstream outputFile("output.txt");
    
//     if (!outputFile.is_open()) {
//         std::cerr << "Ошибка создания файла!" << std::endl;
//         return 1;
//     }
    
//     std::cout << "Введите строки (пустая строка завершает ввод):" << std::endl;
//     std::string line;
    
//     std::cin.ignore();
    
//     while (true) {
//         std::getline(std::cin, line);
//         if (line.empty()) {
//             break;
//         }
//         outputFile << line << std::endl;
//     }
    
//     std::cout << "Данные записаны в файл output.txt." << std::endl;
    
//     outputFile.close();
//     return 0;
// }