// #include <iostream>
// #include <memory>
// #include <vector>
// #include <algorithm>
// #include <string>

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::vector<std::string> logs = {
//         "INFO: Start",
//         "ERROR: Disk failure",
//         "WARNING: Low memory",
//         "ERROR: Disk failure",
//         "INFO: Stop"
//     };
    
//     auto pLogs = std::make_shared<std::vector<std::string>>(logs);
    
//     std::vector<std::string> errors;
    
//     auto isError = [](const std::string& log) {
//         return log.find("ERROR") != std::string::npos;
//     };
    
//     std::copy_if(pLogs->begin(), pLogs->end(), std::back_inserter(errors), isError);
    
//     std::sort(errors.begin(), errors.end());
//     auto last = std::unique(errors.begin(), errors.end());
//     errors.erase(last, errors.end());
    
//     std::cout << "Исходный журнал:\n";
//     for (const auto& log : *pLogs) {
//         std::cout << log << std::endl;
//     }
    
//     std::cout << "\nОшибки:\n";
//     for (const auto& error : errors) {
//         std::cout << error << std::endl;
//     }
    
//     return 0;
// }