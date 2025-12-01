// #include <iostream>
// #include <fstream>

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::ifstream file("numbers.txt");
    
//     if (!file.is_open()) {
//         std::cerr << "Ошибка открытия файла!" << std::endl;
//         return 1;
//     }
    
//     int count = 0;
//     int sum = 0;
//     int number;
    
//     while (file >> number) {
//         sum += number;
//         count++;
//     }
    
//     double average = (count > 0) ? static_cast<double>(sum) / count : 0;
    
//     std::cout << "Количество чисел: " << count << std::endl;
//     std::cout << "Сумма: " << sum << std::endl;
//     std::cout << "Среднее: " << average << std::endl;
    
//     file.close();
//     return 0;
// }