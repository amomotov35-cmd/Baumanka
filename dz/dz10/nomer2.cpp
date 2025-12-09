// #include <iostream>
// #include <fstream>
// #include <string>

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::ifstream file("data.txt");
    
//     if (!file.is_open()) {
//         std::cerr << "Ошибка открытия файла!" << std::endl;
//         return 1;
//     }
    
//     int lineCount = 0;
//     std::string line;
    
//     while (std::getline(file, line)) {
//         lineCount++;
//     }
    
//     std::cout << "Количество строк в файле: " << lineCount << std::endl;
    
//     file.close();
//     return 0;
// }