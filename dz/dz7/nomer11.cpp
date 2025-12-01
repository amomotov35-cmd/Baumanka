// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <algorithm>
// #include <numeric>
// #include <iomanip>

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::ifstream dataFile("vibration_log.txt");
//     std::ofstream reportFile("vibration_report.txt");
    
//     if (!dataFile.is_open()) {
//         std::cerr << "Ошибка открытия файла vibration_log.txt!" << std::endl;
//         return 1;
//     }
    
//     if (!reportFile.is_open()) {
//         std::cerr << "Ошибка создания файла vibration_report.txt!" << std::endl;
//         return 1;
//     }
    
//     std::vector<double> amplitudes;
//     double value;
    
//     while (dataFile >> value) {
//         amplitudes.push_back(value);
//     }
    
//     auto filterValues = [](const std::vector<double>& data, double threshold) {
//         std::vector<double> filtered;
//         std::copy_if(data.begin(), data.end(), std::back_inserter(filtered),
//                     [threshold](double v) { return v > threshold; });
//         return filtered;
//     };
    
//     auto calculateAverage = [](const std::vector<double>& data) {
//         if (data.empty()) return 0.0;
//         double sum = std::accumulate(data.begin(), data.end(), 0.0);
//         return sum / data.size();
//     };
    
//     auto findMinMax = [](const std::vector<double>& data) {
//         if (data.empty()) return std::make_pair(0.0, 0.0);
//         auto minElement = std::min_element(data.begin(), data.end());
//         auto maxElement = std::max_element(data.begin(), data.end());
//         return std::make_pair(*minElement, *maxElement);
//     };
    
//     std::vector<double> filtered = filterValues(amplitudes, 0.05);
//     double average = calculateAverage(amplitudes);
//     auto [minVal, maxVal] = findMinMax(filtered.empty() ? amplitudes : filtered);
    
    
//     reportFile << std::fixed << std::setprecision(4);
//     reportFile << "Количество измерений: " << amplitudes.size() << std::endl;
    
//     reportFile << "Фильтрованные значения (>0.05): ";
//     for (size_t i = 0; i < filtered.size(); ++i) {
//         reportFile << filtered[i];
//         if (i < filtered.size() - 1) reportFile << " ";
//     }
//     reportFile << std::endl;
    
//     reportFile << "Среднее значение: " << average << std::endl;
//     reportFile << "Минимум: " << minVal << std::endl;
//     reportFile << "Максимум: " << maxVal << std::endl;
    
//     std::cout << "Анализ вибрационных данных завершён. Отчёт сохранён в vibration_report.txt" << std::endl;
    
//     dataFile.close();
//     reportFile.close();
//     return 0;
// }