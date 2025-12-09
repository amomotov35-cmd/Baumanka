// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::ifstream bookFile("book.txt");
//     std::ofstream resultFile("search_results.txt");
    
//     if (!bookFile.is_open()) {
//         std::cerr << "Ошибка: не удалось открыть файл book.txt" << std::endl;
//         return 1;
//     }
    
//     std::string searchWord;
//     std::cout << "Введите слово для поиска: ";
//     std::cin >> searchWord;
    
//     std::vector<std::pair<int, int>> positions;
//     std::string line;
//     int lineNumber = 0;
//     int totalOccurrences = 0;
    
//     while (std::getline(bookFile, line)) {
//         lineNumber++;
//         size_t pos = 0;
//         while ((pos = line.find(searchWord, pos)) != std::string::npos) {
//             positions.push_back({lineNumber, static_cast<int>(pos + 1)});
//             totalOccurrences++;
//             pos += searchWord.length();
//         }
//     }
    
//     resultFile << "Результаты поиска слова: \"" << searchWord << "\"\n";
//     resultFile << "Общее количество вхождений: " << totalOccurrences << "\n\n";
    
//     if (totalOccurrences > 0) {
//         resultFile << "Список вхождений:\n";
//         resultFile << "Строка\tПозиция\tКонтекст\n";
        
//         bookFile.clear();
//         bookFile.seekg(0, std::ios::beg);
        
//         int currentLine = 0;
//         while (std::getline(bookFile, line)) {
//             currentLine++;
//             for (const auto& pos : positions) {
//                 if (pos.first == currentLine) {
//                     int start = std::max(0, pos.second - 15);
//                     int end = std::min(static_cast<int>(line.length()), 
//                                      pos.second + static_cast<int>(searchWord.length()) + 15);
//                     std::string context = line.substr(start, end - start);
//                     resultFile << currentLine << "\t" << pos.second << "\t...";
//                     resultFile << context << "...\n";
//                 }
//             }
//         }
//     } else {
//         resultFile << "Слово не найдено.\n";
//     }
    
//     std::cout << "Поиск завершен. Найдено вхождений: " << totalOccurrences << std::endl;
    
//     bookFile.close();
//     resultFile.close();
//     return 0;
// }