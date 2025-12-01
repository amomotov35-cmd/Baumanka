// #include <iostream>
// #include <fstream>
// #include <string>

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::ifstream file("text.txt");
    
//     if (!file.is_open()) {
//         std::cerr << "Ошибка открытия файла!" << std::endl;
//         return 1;
//     }
    
//     int wordCount = 0;
//     std::string word;
    
//     while (file >> word) {
//         wordCount++;
//     }
    
//     std::cout << "Количество слов в файле: " << wordCount << std::endl;
    
//     file.close();
//     return 0;
// }