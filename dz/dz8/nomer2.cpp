// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>

// bool editConfigFile(const std::string& filename, const std::string& key, 
//                     const std::string& newValue) {
//     std::fstream file(filename, std::ios::in | std::ios::out);
    
//     if (!file.is_open()) {
//         std::cerr << "Ошибка открытия файла: " << filename << std::endl;
//         return false;
//     }
    
//     std::vector<std::string> lines;
//     std::string line;
//     bool found = false;
    
//     while (std::getline(file, line)) {
//         lines.push_back(line);
//     }
    
//     for (auto& currentLine : lines) {
//         if (currentLine.find(key + "=") == 0) {
//             size_t equalsPos = currentLine.find('=');
//             if (equalsPos != std::string::npos) {
//                 currentLine = key + "=" + newValue;
//                 found = true;
//                 break;
//             }
//         }
//     }
    
//     if (!found) {
//         std::cout << "Параметр '" << key << "' не найден.\n";
//         return false;
//     }
    
//     file.close();
//     file.open(filename, std::ios::out | std::ios::trunc);
    
//     for (size_t i = 0; i < lines.size(); ++i) {
//         file << lines[i];
//         if (i < lines.size() - 1) {
//             file << "\n";
//         }
//     }
    
//     std::cout << "Параметр '" << key << "' изменен на: " << newValue << std::endl;
//     return true;
// }

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::ofstream testFile("config.txt");
//     testFile << "server_ip=192.168.1.1\n";
//     testFile << "port=8080\n";
//     testFile << "timeout=30\n";
//     testFile << "max_connections=100\n";
//     testFile.close();
    
//     editConfigFile("config.txt", "timeout", "60");
    
//     std::ifstream showFile("config.txt");
//     std::string line;
//     while (std::getline(showFile, line)) {
//         std::cout << line << std::endl;
//     }
    
//     return 0;
// }