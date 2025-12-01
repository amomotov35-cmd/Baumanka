// #include <iostream>
// #include <memory>
// #include <iomanip>

// int main() {
//     setlocale(LC_ALL, "rus");
//     int n, m;
//     std::cout << "Введите N и M: ";
//     std::cin >> n >> m;
    
//     auto arr = std::make_unique<int[]>(n * m);
    
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             arr[i * m + j] = i * j;
//         }
//     }
//     std::cout << "Таблица произведений:" << std::endl;
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             std::cout << std::setw(4) << arr[i * m + j];
//         }
//         std::cout << std::endl;
//     }
    
//     return 0;
// }