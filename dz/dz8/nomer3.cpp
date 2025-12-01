// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>
// #include <sstream>

// bool splitLogFile(const std::string& inputFile, int maxLinesPerPart) {
//     std::ifstream sourceFile(inputFile);
    
//     if (!sourceFile.is_open()) {
//         std::cerr << "Ошибка открытия файла: " << inputFile << std::endl;
//         return false;
//     }
    
//     std::vector<std::string> partFiles;
//     std::string line;
//     int lineCount = 0;
//     int partNumber = 1;
//     std::ofstream currentPart;
    
//     while (std::getline(sourceFile, line)) {
//         if (lineCount % maxLinesPerPart == 0) {
//             if (currentPart.is_open()) {
//                 currentPart.close();
//             }
            
//             std::stringstream partName;
//             partName << "log_part" << partNumber << ".txt";
//             partFiles.push_back(partName.str());
            
//             currentPart.open(partName.str());
//             if (!currentPart.is_open()) {
//                 std::cerr << "Ошибка создания файла: " << partName.str() << std::endl;
//                 return false;
//             }
            
//             partNumber++;
//         }
        
//         currentPart << line << "\n";
//         lineCount++;
//     }
    
//     if (currentPart.is_open()) {
//         currentPart.close();
//     }
    
//     sourceFile.close();
    
//     std::ofstream indexFile("log_index.txt");
//     indexFile << "=== Индекс разделенного лог-файла ===\n";
//     indexFile << "Исходный файл: " << inputFile << "\n";
//     indexFile << "Всего строк: " << lineCount << "\n";
//     indexFile << "Количество частей: " << partFiles.size() << "\n";
//     indexFile << "Максимальное количество строк в части: " << maxLinesPerPart << "\n\n";
//     indexFile << "Список частей:\n";
    
//     for (size_t i = 0; i < partFiles.size(); ++i) {
//         indexFile << i + 1 << ". " << partFiles[i] << "\n";
//         std::ifstream part(partFiles[i]);
//         int partLineCount = 0;
//         std::string tempLine;
//         while (std::getline(part, tempLine)) {
//             partLineCount++;
//         }
//         indexFile << "   Строк: " << partLineCount << "\n";
//         part.close();
//     }
    
//     indexFile.close();
    
//     std::cout << "Лог-файл разделен на " << partFiles.size() << " частей.\n";
//     return true;
// }

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::ofstream testLog("application.log");
//     for (int i = 1; i <= 50; ++i) {
//         testLog << "[INFO] Запись в логе №" << i << ": Тестовое сообщение\n";
//     }
//     testLog.close();
    
//     splitLogFile("application.log", 15);
//     return 0;
// }