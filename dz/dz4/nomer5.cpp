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
//     auto max_it = std::max_element(v.begin(), v.end());
//     auto min_it = std::min_element(v.begin(), v.end());
//      std::cout << "Максимум: " << *max_it << "\n";
//      std::cout << "Минимум: " << *min_it << "\n";
//      double average = std::accumulate(v.begin(), v.end(), 0.0) / v.size();
//      std::cout << "Среднее значение: " << std::setprecision(2) << std::fixed << average << "\n";
//          double median;
//          size_t size = v.size();
//          if (size % 2 == 0) {
//              median = (v[size / 2 - 1] + v[size / 2]) / 2.0;
//          }
//          else {
//               median = v[size / 2];
//          }
//          std::cout << "Медиана: " << median << "\n";
//     return 0;
// }