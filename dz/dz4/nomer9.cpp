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
//     std::uniform_int_distribution<int> distribution(-20, 120);
//     for (int i = 0; i < 20; ++i) {
//         v.push_back(distribution(generator));
//     }
//     std::cout << "Сгенерированная мощность в кВт: ";
//     for (const int& x : v) {
//         std::cout << x << " ";
//     }
//     std::cout << std::endl;  
//     std::sort(v.begin(), v.end());
//     v.erase(std::remove_if(v.begin(), v.end(),
//         [](int x) { return x < 0; }),
//         v.end());
//     std::cout << "После удаления ошибок датчика: ";
//       for (int x : v) std::cout << x << " ";
//     if (v.empty()) {
//         std::cout << "Все мощности были удалены из-за не превешения 0 ." << std::endl;
//         return 0;
//     }
//     int average_speed = std::accumulate(v.begin(), v.end(), 0) / v.size();
//     std::cout << "Средняя мощность: " << std::fixed << std::setprecision(2) << average_speed << std::endl;
//     bool all_positive = std::all_of(v.begin(), v.end(), [](int x) { return x > 10 && x < 90; });
//     if (all_positive) {
//         std::cout << "Двигатель всё время работал в предела от 10 до 90 кВт." << std::endl;
//     }
//     else {
//         std::cout << "Двигатель не всё время работал в пределах от 10 до 90 кВт." << std::endl;
//     }
//     auto max_it = std::max_element(v.begin(), v.end());
//     auto min_it = std::min_element(v.begin(), v.end());
//     std::cout << "Максимум: " << *max_it << "\n";
//     std::cout << "Минимум: " << *min_it << "\n";
//     std::vector<int> top_speeds = v; 
//     std::sort(top_speeds.rbegin(), top_speeds.rend());
//     double median;
//     size_t size = v.size();
//     if (size % 2 == 0) {
//      median = (v[size / 2 - 1] + v[size / 2]) / 2.0;
//     }
//     else {
//      median = v[size / 2];
//     }
//     std::cout << "Медиана: " << median << "\n";
//     return 0; 
// }