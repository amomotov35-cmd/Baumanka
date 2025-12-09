// #include <iostream>
// #include <fstream>
// #include <string>

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::ifstream file1("file1.txt");
//     std::ifstream file2("file2.txt");
    
//     if (!file1.is_open() || !file2.is_open()) {
//         std::cerr << "Ошибка открытия файлов!" << std::endl;
//         return 1;
//     }
    
//     bool identical = true;
//     std::string line1, line2;
//     int lineNumber = 1;
    
//     while (std::getline(file1, line1) && std::getline(file2, line2)) {
//         if (line1 != line2) {
//             identical = false;
//             std::cout << "Файлы различаются в строке " << lineNumber << std::endl;
//             break;
//         }
//         lineNumber++;
//     }
    
//     if (identical && (std::getline(file1, line1) || std::getline(file2, line2))) {
//         identical = false;
//         std::cout << "Файлы различаются: разное количество строк" << std::endl;
//     }
    
//     if (identical) {
//         std::cout << "Файлы идентичны." << std::endl;
//     }
    
//     file1.close();
//     file2.close();
//     return 0;
// }