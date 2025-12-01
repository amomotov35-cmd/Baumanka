// #include <iostream>
// #include <fstream>

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::ifstream file("input.txt");
    
//     if (!file.is_open()) {
//         std::cerr << "Ошибка открытия файла!" << std::endl;
//         return 1;
//     }
    
//     int charCount = 0;
//     char ch;
    
//     while (file.get(ch)) {
//         charCount++;
//     }
    
//     std::cout << "Количество символов в файле: " << charCount << std::endl;
    
//     file.close();
//     return 0;
// }