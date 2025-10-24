// #include <iostream> 
// #include <vector> 
// #include <algorithm>
// #include <numeric> 
// #include <random>
// #include <iomanip>

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::vector<double> v;
//     std::default_random_engine generator;
//     std::uniform_real_distribution<double> distribution(-100.0, 100.0);
//     for (int i = 0; i < 20; ++i) {
//         v.push_back(distribution(generator));
//     }
//     std::cout << "Сгенерированные температуры: ";
//     for (const double& temp : v) {
//         std::cout << std::fixed << std::setprecision(2) << temp << " ";
//     }
//     std::cout << std::endl;
//     v.erase(std::remove_if(v.begin(), v.end(),
//         [](double temp) { return temp < -50.0 || temp > 50.0; }),
//         v.end());
//     if (v.empty()) {
//         std::cout << "Все температуры были удалены из-за выхода за пределы диапазона." << std::endl;
//     }
//     auto min_max = std::minmax_element(v.begin(), v.end());
//     double average = std::accumulate(v.begin(), v.end(), 0.0) / v.size();
//     std::cout << "Минимальная температура: " << *min_max.first << "\n";
//     std::cout << "Максимальная температура: " << *min_max.second << "\n";
//     std::cout << "Средняя температура: " << std::fixed << std::setprecision(2) << average << "\n";    
//     bool all_above_minus_ten = std::all_of(v.begin(), v.end(),
//         [](double temp) { return temp > -10.0; });
//     if (all_above_minus_ten) {
//         std::cout << "Все температуры превышают -10 градусов." << std::endl;
//     }
//     else {
//         std::cout << "Не все температуры превышают -10 градусов." << std::endl;
//     }
//     return 0; 
// }
