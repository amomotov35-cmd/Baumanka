// #include <iostream>
// #include <cstring>

// bool containsAllCharacters(const char* A, const char* B) {
//     for (int i = 0; B[i] != '\0'; i++) {
//         bool found = false; 
//         for (int j = 0; A[j] != '\0'; j++) {
//             if (A[j] == B[i]) {
//                 found = true; 
//                 break; 
//             }
//         }
//         if (!found) {
//             return false; 
//         }
//     }
//     return true; 
// }

// int main() {
//     setlocale(LC_ALL, "rus"); 
//     char A[100], B[100];
//     std::cout << "Введите строку A: ";
//     std::cin.getline(A, 100);
//     std::cout << "Введите строку B: ";
//     std::cin.getline(B, 100);
//     if (containsAllCharacters(A, B)) {
//         std::cout << "Да" << std::endl; 
//     }
//     else {
//         std::cout << "Нет" << std::endl; 
//     }
//     return 0; 
// }