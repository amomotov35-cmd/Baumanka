// #include <iostream>
// #include <memory>
// #include <iomanip>

// double calculateAverage(const std::unique_ptr<double[]>& arr, int size) {
//     double sum = 0;
//     for (int i = 0; i < size; ++i) {
//         sum += arr[i];
//     }
//     return sum / size;
// }

// int main() {
//     setlocale(LC_ALL, "rus");
//     const int SIZE = 5;
    
//     auto temperatures = std::make_unique<double[]>(SIZE);
//     auto pressures = std::make_unique<double[]>(SIZE);
//     auto humidities = std::make_unique<double[]>(SIZE);
    
//     temperatures[0] = 20.5; temperatures[1] = 21.0; temperatures[2] = 22.3;
//     temperatures[3] = 19.8; temperatures[4] = 20.2;
    
//     pressures[0] = 760.0; pressures[1] = 758.5; pressures[2] = 762.3;
//     pressures[3] = 759.1; pressures[4] = 760.8;
    
//     humidities[0] = 45.0; humidities[1] = 47.5; humidities[2] = 43.2;
//     humidities[3] = 48.1; humidities[4] = 46.3;
    
//     double tempAvg = calculateAverage(temperatures, SIZE);
//     double pressAvg = calculateAverage(pressures, SIZE);
//     double humidAvg = calculateAverage(humidities, SIZE);
    
//     std::cout << std::left << std::setw(20) << "Параметр" 
//               << std::setw(20) << "Среднее значение" << std::endl;
//     std::cout << std::string(40, '-') << std::endl;
//     std::cout << std::left << std::setw(20) << "Температура" 
//               << std::setw(20) << tempAvg << std::endl;
//     std::cout << std::left << std::setw(20) << "Давление" 
//               << std::setw(20) << pressAvg << std::endl;
//     std::cout << std::left << std::setw(20) << "Влажность" 
//               << std::setw(20) << humidAvg << std::endl;
    
//     return 0;
// }