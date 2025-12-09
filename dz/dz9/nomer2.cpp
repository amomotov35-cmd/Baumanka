// #include <iostream>
// #include <memory>

// int main() {
//     setlocale(LC_ALL, "rus");
//     int n;
//     std::cout << "Введите размер массива: ";
//     std::cin >> n;
//     auto arr = std::make_unique<int[]>(n);
//     for (int i = 0; i < n; ++i) {
//         arr[i] = i + 1;
//     }
//     std::cout << "Массив: ";
//     for (int i = 0; i < n; ++i) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;
    
//     return 0;
// }