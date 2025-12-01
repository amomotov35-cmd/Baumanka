// #include <iostream>
// #include <fstream>
// #include <string>

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::ifstream sourceFile("source.txt");
//     std::ofstream destFile("copy.txt");
    
//     if (!sourceFile.is_open()) {
//         std::cerr << "Ошибка открытия исходного файла!" << std::endl;
//         return 1;
//     }
    
//     if (!destFile.is_open()) {
//         std::cerr << "Ошибка создания файла для копирования!" << std::endl;
//         return 1;
//     }
    
//     int lineCount = 0;
//     std::string line;
    
//     while (std::getline(sourceFile, line)) {
//         destFile << line << std::endl;
//         lineCount++;
//     }
    
//     std::cout << "Файл успешно скопирован." << std::endl;
//     std::cout << "Количество скопированных строк: " << lineCount << std::endl;
    
//     sourceFile.close();
//     destFile.close();
//     return 0;
// }