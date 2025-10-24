// #include <iostream>
// #include <cstring>
// #include <cctype>

// int main() {
//     setlocale(LC_ALL, "rus"); 
//     char str[100];
//     std::cout << "Введите строку: ";
//     std::cin.getline(str, 100);
//     int readIndex = 0; 
//     int writeIndex = 0; 
//     while (str[readIndex] != '\0') 
//     { 
//         if (!isdigit(str[readIndex])) {
//             str[writeIndex] = str[readIndex];
//             writeIndex++; 
//             readIndex++;
//         }
//         str[writeIndex] = '\0';
//         std::cout << "Результат: " << str << std::endl;
//         return 0; 
//     }
// }