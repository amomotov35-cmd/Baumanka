// #include <iostream>
// #include <cstring>
// #include <cctype>
// int main() {
//     setlocale(LC_ALL, "rus"); 
//     char str[100]; 
//     std::cout << "Введите строку: ";
//     std::cin.getline(str, 100); 

//     int vowelsCount = 0; 
//     int consonantsCount = 0; 
//     for (int i = 0; str[i] != '\0'; i++) {
//         char currentChar = tolower(str[i]); 
//         if (isalpha(currentChar)) {
//             if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' ||
//                 currentChar == 'o' || currentChar == 'u' || currentChar == 'y') {
//                 vowelsCount++; 
//             }
//             else {
//                 consonantsCount++; 
//             }
//         }
//     }
//     std::cout << "Гласных: " << vowelsCount << std::endl;
//     std::cout << "Согласных: " << consonantsCount << std::endl;
//     return 0; 
// }