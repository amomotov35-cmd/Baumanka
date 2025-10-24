// #include <iostream> 
// #include <vector> 
// #include <algorithm>
// #include <random>

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
//     v.erase(std::remove_if(v.begin(), v.end(), [](int x) { 
//         return x < 0; 
//         }), v.end());
//     std::cout << "После удаления отрицательных: ";
//     for (int x : v) std::cout << x << " ";
//     return 0;
// }