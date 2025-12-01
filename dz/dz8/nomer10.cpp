// #include <iostream>
// #include <fstream>
// #include <string>
// #include <sstream>

// void createConfig() {
//     std::ofstream file("config.json");
//     file << "{\n";
//     file << "  \"app_name\": \"My Application\",\n";
//     file << "  \"version\": \"1.0.0\",\n";
//     file << "  \"settings\": {\n";
//     file << "    \"max_connections\": 100,\n";
//     file << "    \"timeout\": 30,\n";
//     file << "    \"debug_mode\": true\n";
//     file << "  },\n";
//     file << "  \"database\": {\n";
//     file << "    \"host\": \"localhost\",\n";
//     file << "    \"port\": 5432,\n";
//     file << "    \"username\": \"admin\"\n";
//     file << "  }\n";
//     file << "}";
//     file.close();
//     std::cout << "Конфигурационный файл создан\n";
// }

// void readAndModifyConfig() {
//     std::ifstream file("config.json");
//     std::stringstream buffer;
//     buffer << file.rdbuf();
//     file.close();
    
//     std::string content = buffer.str();
    
//     std::cout << "Текущий конфигурационный файл:\n";
//     std::cout << content << "\n";
    
//     size_t timeoutPos = content.find("\"timeout\": 30");
//     if (timeoutPos != std::string::npos) {
//         content.replace(timeoutPos, 13, "\"timeout\": 60");
        
//         std::ofstream outFile("config.json");
//         outFile << content;
//         outFile.close();
        
//         std::cout << "Параметр timeout изменен на 60\n";
//     } else {
//         std::cout << "Параметр timeout не найден\n";
//     }
// }

// int main() {
//     setlocale(LC_ALL, "rus");
//     createConfig();
//     readAndModifyConfig();
//     return 0;
// }