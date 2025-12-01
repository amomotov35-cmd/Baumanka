// #include <iostream>
// #include <memory>
// #include <vector>
// #include <algorithm>
// #include <numeric>
// #include <iomanip>

// int main() {
//     setlocale(LC_ALL, "rus");
//     int n;
//     std::cout << "Введите количество измерений: ";
//     std::cin >> n;
    
//     std::vector<double> signals(n);
//     std::cout << "Введите " << n << " значений: ";
//     for (int i = 0; i < n; ++i) {
//         std::cin >> signals[i];
//     }
    
//     auto dynArray = std::make_unique<double[]>(n);
//     std::copy(signals.begin(), signals.end(), dynArray.get());
    
//     auto mean = [](const std::unique_ptr<double[]>& arr, int size) -> double {
//         double sum = 0;
//         for (int i = 0; i < size; ++i) {
//             sum += arr[i];
//         }
//         return sum / size;
//     };
    
//     auto normalize = [](std::unique_ptr<double[]>& arr, int size, double maxVal) {
//         if (maxVal == 0) return;
//         for (int i = 0; i < size; ++i) {
//             arr[i] /= maxVal;
//         }
//     };
    
//     auto copyBack = [](const std::unique_ptr<double[]>& src, std::vector<double>& dst, int size) {
//         dst.resize(size);
//         for (int i = 0; i < size; ++i) {
//             dst[i] = src[i];
//         }
//     };
    
//     double avg = mean(dynArray, n);
//     double maxVal = *std::max_element(signals.begin(), signals.end());
    
//     normalize(dynArray, n, maxVal);
//     copyBack(dynArray, signals, n);
    
//     std::cout << std::fixed << std::setprecision(2);
//     std::cout << "Исходные данные: ";
//     for (const auto& val : signals) {
//         std::cout << val << " ";
//     }
//     std::cout << "\nСреднее значение: " << avg << std::endl;
    
//     std::cout << std::fixed << std::setprecision(3);
//     std::cout << "Нормализованные сигналы: ";
//     for (int i = 0; i < n; ++i) {
//         std::cout << dynArray[i] << " ";
//     }
//     std::cout << std::endl;
    
//     return 0;
// }