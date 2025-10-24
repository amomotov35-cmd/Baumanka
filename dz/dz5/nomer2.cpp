// #include <iostream>
// #include <cstring>

// int main() {
//     setlocale(LC_ALL, "rus");

//     char str[100];
//     std::cout << "Введите строку: ";
//     std::cin.getline(str, 100);

//     int count = 0;
//     bool found[256] = { false };
//     for (int i = 0; i < strlen(str); ++i) {
//         char currentChar = str[i];
//         if (currentChar == ' ') {
//             continue;
//         }
//         if (!found[currentChar]) {
//             found[currentChar] = true;
//             count++;
//         }
//     }

//     std::cout << "Количество различных символов: " << count << std::endl;

//     return 0;
// }