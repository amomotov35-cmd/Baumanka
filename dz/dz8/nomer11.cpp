// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <numeric>
// #include <iomanip>

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::ifstream dataFile("sensor_data.txt");
//     std::ofstream filteredFile("filtered_sensor_data.txt");
    
//     std::vector<double> temperatures;
//     std::vector<double> filteredTemperatures;
//     double value;
    
//     while (dataFile >> value) {
//         temperatures.push_back(value);
//     }
    
//     dataFile.close();
    
//     auto valid_temperature = [](double temp) { return temp >= -50 && temp <= 50; };
    
//     std::copy_if(temperatures.begin(), temperatures.end(), 
//                 std::back_inserter(filteredTemperatures), valid_temperature);
    
//     for (const auto& temp : filteredTemperatures) {
//         filteredFile << std::fixed << std::setprecision(2) << temp << "\n";
//     }
    
//     filteredFile.close();
    
//     if (!filteredTemperatures.empty()) {
//         double sum = std::accumulate(filteredTemperatures.begin(), filteredTemperatures.end(), 0.0);
//         double average = sum / filteredTemperatures.size();
        
//         auto min_element = std::min_element(filteredTemperatures.begin(), filteredTemperatures.end());
//         auto max_element = std::max_element(filteredTemperatures.begin(), filteredTemperatures.end());
        
//         std::cout << "=== Результаты обработки данных датчиков ===\n";
//         std::cout << "Всего измерений: " << temperatures.size() << std::endl;
//         std::cout << "Корректных измерений: " << filteredTemperatures.size() << std::endl;
//         std::cout << "Некорректных измерений: " << temperatures.size() - filteredTemperatures.size() << std::endl;
//         std::cout << "Средняя температура: " << std::fixed << std::setprecision(2) << average << "°C\n";
//         std::cout << "Минимальная температура: " << *min_element << "°C\n";
//         std::cout << "Максимальная температура: " << *max_element << "°C\n";
//     } else {
//         std::cout << "Нет корректных данных для анализа.\n";
//     }
    
//     return 0;
// }