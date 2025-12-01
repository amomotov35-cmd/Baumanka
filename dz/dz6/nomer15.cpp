// #include <iostream>
// #include <memory>
// #include <vector>
// #include <string>
// #include <algorithm>

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::vector<std::string> routes = {
//         "Moscow-Berlin",
//         "Berlin-Paris",
//         "Paris-Rome",
//         "Rome-Moscow"
//     };
    
//     auto ptrRoutes = std::make_shared<std::vector<std::string>>(routes);
    
//     auto countCity = [](std::shared_ptr<std::vector<std::string>> routesPtr, 
//                        const std::string& city) -> int {
//         int count = 0;
//         for (const auto& route : *routesPtr) {
//             if (route.find(city) != std::string::npos) {
//                 ++count;
//             }
//         }
//         return count;
//     };
    
//     auto sortByLength = [](std::shared_ptr<std::vector<std::string>> routesPtr) {
//         std::sort(routesPtr->begin(), routesPtr->end(),
//                   [](const std::string& a, const std::string& b) {
//                       return a.length() > b.length(); 
//                   });
//     };
    
//     auto concat = [](std::shared_ptr<std::vector<std::string>> routesPtr) -> std::string {
//         std::string result;
//         for (size_t i = 0; i < routesPtr->size(); ++i) {
//             if (!result.empty()) result += " -> ";
//             result += (*routesPtr)[i];
//         }
//         return result;
//     };
    
//     int parisCount = countCity(ptrRoutes, "Paris");
//     std::cout << "Количество маршрутов с \"Paris\": " << parisCount << std::endl;
    
//     sortByLength(ptrRoutes);
//     std::cout << "Отсортированные маршруты:\n";
//     for (const auto& route : *ptrRoutes) {
//         std::cout << route << std::endl;
//     }
    
//     std::string combined = concat(ptrRoutes);
//     std::cout << "\nОбщий маршрут:\n" << combined << std::endl;
    
//     return 0;
// }