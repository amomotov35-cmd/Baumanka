// #include <iostream>
// #include <fstream>
// #include <string>
// #include <sstream>
// #include <map>
// #include <vector>
// #include <iomanip>
// #include <numeric>

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::ifstream logFile("power_log.txt");
//     std::ofstream reportFile("energy_report.txt");
    
//     if (!logFile.is_open()) {
//         std::cerr << "Ошибка открытия файла power_log.txt!" << std::endl;
//         return 1;
//     }
    
//     if (!reportFile.is_open()) {
//         std::cerr << "Ошибка создания файла energy_report.txt!" << std::endl;
//         return 1;
//     }
    
//     std::map<std::string, std::vector<double>> deviceData;
    
//     std::string line;
//     while (std::getline(logFile, line)) {
//         std::istringstream iss(line);
//         std::string timestamp, deviceName;
//         double power;
        
//         if (iss >> timestamp >> deviceName >> power) {
//             deviceData[deviceName].push_back(power);
//         }
//     }
    
//     reportFile << std::fixed << std::setprecision(2);
    
//     for (const auto& [device, measurements] : deviceData) {
//         int count = measurements.size();
//         double total = std::accumulate(measurements.begin(), measurements.end(), 0.0);
//         double average = total / count;
        
//         reportFile << device << ": measurements = " << count 
//                   << ", total = " << total << " kWh"
//                   << ", average = " << average << " kW" << std::endl;
//     }
    
//     std::cout << "Анализ завершён. Результаты сохранены в energy_report.txt" << std::endl;
    
//     logFile.close();
//     reportFile.close();
//     return 0;
// }