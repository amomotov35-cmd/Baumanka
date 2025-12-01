// #include <iostream>
// #include <fstream>
// #include <string>

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::ifstream inputFile("input.txt");
    
//     if (inputFile.fail()) {
//         std::cerr << "Ошибка: файл input.txt не найден!" << std::endl;
//         return 1;
//     }
    
//     std::cout << "Содержимое файла:" << std::endl;
//     std::string line;
//     while (std::getline(inputFile, line)) {
//         std::cout << line << std::endl;
//     }
    
//     inputFile.close();
//     return 0;
// }