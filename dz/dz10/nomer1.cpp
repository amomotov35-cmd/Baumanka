// #include <iostream>

// union Variant {
//     int intValue;
//     double doubleValue;
//     char charValue;
// };

// int main() {
//     setlocale(LC_ALL, "rus");
//     Variant data;
//     char choice;
    
//     std::cout << "Выберите тип данных (i - целое число, d - число с плавающей запятой, c - символ): ";
//     std::cin >> choice;
    
//     switch (choice) {
//         case 'i':
//             std::cout << "Введите целое число: ";
//             std::cin >> data.intValue;
//             std::cout << "Вы ввели: " << data.intValue << std::endl;
//             break;
//         case 'd':
//             std::cout << "Введите число с плавающей запятой: ";
//             std::cin >> data.doubleValue;
//             std::cout << "Вы ввели: " << data.doubleValue << std::endl;
//             break;
//         case 'c':
//             std::cout << "Введите символ: ";
//             std::cin >> data.charValue;
//             std::cout << "Вы ввели: " << data.charValue << std::endl;
//             break;
//         default:
//             std::cout << "Неверный выбор." << std::endl;
//     }
    
//     return 0;
// }