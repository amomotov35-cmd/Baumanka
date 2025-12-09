// #include <iostream>
// #include <memory>

// std::unique_ptr<int[]> createArray(int n) {
//     auto arr = std::make_unique<int[]>(n);
//     for (int i = 0; i < n; ++i) {
//         arr[i] = i + 1;
//     }
//     return arr;
// }

// int main() {
//     setlocale(LC_ALL, "rus");
//     int n;
//     std::cout << "Введите размер массива: ";
//     std::cin >> n;
    
//     auto arr = createArray(n);
    
//     std::cout << "Элементы массива: ";
//     for (int i = 0; i < n; ++i) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;
    
//     return 0;
// }