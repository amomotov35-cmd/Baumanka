// #include <iostream>
// #include <fstream>
// #include <string>
// #include <sstream>
// #include <map>
// #include <vector>
// #include <algorithm>
// #include <iomanip>
// #include <numeric>

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::ifstream inputFile("temperature_data.txt");
//     std::ofstream reportFile("report.txt");
    
//     if (!inputFile.is_open()) {
//         std::cerr << "Ошибка открытия файла temperature_data.txt!" << std::endl;
//         return 1;
//     }
    
//     if (!reportFile.is_open()) {
//         std::cerr << "Ошибка создания файла report.txt!" << std::endl;
//         return 1;
//     }
    
//     std::map<std::string, std::vector<double>> sensorData;
    
//     std::string line;
//     while (std::getline(inputFile, line)) {
//         std::istringstream iss(line);
//         std::string sensorName;
//         double temperature;
        
//         if (iss >> sensorName >> temperature) {
//             sensorData[sensorName].push_back(temperature);
//         }
//     }
    
//     for (const auto& [sensor, temperatures] : sensorData) {
//         if (temperatures.empty()) continue;
        
//         auto minElement = std::min_element(temperatures.begin(), temperatures.end());
//         auto maxElement = std::max_element(temperatures.begin(), temperatures.end());
//         double sum = std::accumulate(temperatures.begin(), temperatures.end(), 0.0);
//         double average = sum / temperatures.size();
        
//         reportFile << std::fixed << std::setprecision(1);
//         reportFile << sensor << ": min = " << *minElement 
//                   << ", max = " << *maxElement 
//                   << ", avg = " << average << std::endl;
//     }
    
//     std::cout << "Отчёт о температурных данных сохранён в report.txt" << std::endl;
    
//     inputFile.close();
//     reportFile.close();
//     return 0;
// }