// #include <iostream> 
// #include <vector> 
// #include <algorithm>
// #include <numeric> 
// #include <random>
// #include <iomanip>

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::vector<int> v;
//     std::default_random_engine generator;
//     std::uniform_int_distribution<int> distribution(-10, 10);
//     for (int i = 0; i < 20; ++i) {
//         v.push_back(distribution(generator));
//     }
//     std::cout << "Сгенерированные числа: ";
//     for (const int& x : v) {
//         std::cout << x << " ";
//     }
//     std::cout << std::endl;
//     auto it = std::find(v.begin(), v.end(), 7);
//     if (it != v.end()) {
//         std::cout << "Число 7 найдено в векторе." << std::endl;
//     }
//     else {
//         std::cout << "Число 7 не найдено в векторе." << std::endl;
//     }
//     std::sort(v.begin(), v.end());
//     auto last = std::unique(v.begin(), v.end());
//     v.erase(last, v.end()); 
//     std::cout << "Оставшиеся элементы после удаления повторяющихся: ";
//     for (const int& num : v) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }