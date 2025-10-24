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
//     std::uniform_int_distribution<int> distribution(0, 180);
//     for (int i = 0; i < 50; ++i) {
//         v.push_back(distribution(generator));
//     }
//     std::cout << "Сгенерированная скорость: ";
//     for (const int& x : v) {
//         std::cout << x << " ";
//     }
//     std::cout << std::endl;
//     v.erase(std::remove_if(v.begin(), v.end(),
//         [](int x) { return x > 120; }),
//         v.end());
//     std::cout << "После удаления скорости >120: ";
//       for (int x : v) std::cout << x << " ";
//     if (v.empty()) {
//         std::cout << "Все скорости были удалены из-за превышения 120." << std::endl;
//         return 0;
//     }
//     int average_speed = std::accumulate(v.begin(), v.end(), 0) / v.size();
//     std::cout << "Средняя скорость: " << std::fixed << std::setprecision(2) << average_speed << std::endl;
//     bool all_positive = std::all_of(v.begin(), v.end(), [](int x) { return x > 0.0; });
//     if (all_positive) {
//         std::cout << "Автомобиль всегда двигался." << std::endl;
//     }
//     else {
//         std::cout << "Автомобиль останавливался." << std::endl;
//     }
//     std::vector<int> top_speeds = v; 
//     std::sort(top_speeds.rbegin(), top_speeds.rend()); 
//     std::cout << "10 максимальных значений скорости: ";
//     for (size_t i = 0; i < std::min<size_t>(10, top_speeds.size()); ++i) {
//         std::cout << std::fixed << std::setprecision(2) << top_speeds[i] << " ";
//     }
//     std::cout << std::endl;
//     return 0; 
// }