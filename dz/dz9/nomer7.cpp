// #include <iostream>
// #include <memory>
// #include <cstring>
// #include <vector>

// bool isVowel(char c) {
//     c = std::tolower(c);
//     return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
//            c == 'а' || c == 'е' || c == 'и' || c == 'о' || c == 'у'; // для русского
// }

// int main() {
//       setlocale(LC_ALL, "rus");
//     std::string input;
//     std::cout << "Введите строку: ";
//     std::getline(std::cin, input);
    
//     auto arr = std::make_unique<char[]>(input.size() + 1);
//     std::strcpy(arr.get(), input.c_str());
    
//     int vowels = 0, consonants = 0;
//     for (size_t i = 0; i < input.size(); ++i) {
//         char c = std::tolower(arr[i]);
//         if (std::isalpha(c)) {
//             if (isVowel(c)) {
//                 ++vowels;
//             } else {
//                 ++consonants;
//             }
//         }
//     }
    
//     std::cout << "Гласных: " << vowels << "\nСогласных: " << consonants << std::endl;
    
//     auto vowelsArr = std::make_unique<char[]>(vowels + 1);
//     int index = 0;
//     for (size_t i = 0; i < input.size(); ++i) {
//         if (isVowel(std::tolower(arr[i]))) {
//             vowelsArr[index++] = arr[i];
//         }
//     }
//     vowelsArr[vowels] = '\0';
    
//     std::cout << "Гласные буквы: " << vowelsArr.get() << std::endl;
    
//     return 0;
// }