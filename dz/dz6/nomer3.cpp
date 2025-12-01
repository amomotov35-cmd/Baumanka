// #include <iostream>
// #include <memory>

// void fillArray(std::unique_ptr<int[]>& arr, int n) {
//     for (int i = 0; i < n; ++i) {
//         arr[i] = i * i;
//     }
// }

// int main(){
//     setlocale(LC_ALL, "rus");
//     int n;
//     std::cout << "Введите размер массива: ";
//     std::cin >> n;
    
//     auto arr = std::make_unique<int[]>(n);
//     fillArray(arr, n);
    
//     std::cout << "Массив квадратов: ";
//     for (int i = 0; i < n; ++i) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;
    
//     return 0;
// }