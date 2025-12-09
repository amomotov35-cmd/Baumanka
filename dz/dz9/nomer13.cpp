// #include <iostream>
// #include <memory>
// #include <vector>
// #include <string>
// #include <algorithm>

// int main() {
//     setlocale(LC_ALL, "rus");
//     auto part1 = std::make_unique<std::string>("Sensor data:");
//     auto part2 = std::make_unique<std::string>("Voltage stable.");
//     auto part3 = std::make_unique<std::string>("System nominal.");
    
//     std::vector<std::unique_ptr<std::string>> reportParts;
//     reportParts.push_back(std::move(part1));
//     reportParts.push_back(std::move(part2));
//     reportParts.push_back(std::move(part3));
    
//     auto concatParts = [](const std::vector<std::unique_ptr<std::string>>& parts) -> std::string {
//         std::string result;
//         for (const auto& part : parts) {
//             if (!result.empty()) result += "\n";
//             result += *part;
//         }
//         return result;
//     };
    
//     auto countWord = [](const std::string& text, const std::string& word) -> int {
//         int count = 0;
//         size_t pos = 0;
//         while ((pos = text.find(word, pos)) != std::string::npos) {
//             ++count;
//             pos += word.length();
//         }
//         return count;
//     };
    
//     std::string report = concatParts(reportParts);
//     int dataCount = countWord(report, "data");
    
//     std::cout << "Отчёт:\n" << report << "\n\n";
//     std::cout << "Слово \"data\" встречается " << dataCount << " раз" << std::endl;
    
//     return 0;
// }