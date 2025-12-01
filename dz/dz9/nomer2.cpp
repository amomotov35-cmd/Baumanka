// #include <iostream>
// #include <queue>
// #include <string>

// void addEvent(std::queue<std::string>& eventQueue, const std::string& event) {
//     eventQueue.push(event);
//     std::cout << "Событие добавлено: " << event << "\n";
// }

// void processEvents(std::queue<std::string>& eventQueue) {
//     if (!eventQueue.empty()) {
//         std::cout << "Обрабатывается событие: " << eventQueue.front() << "\n";
//         eventQueue.pop();
//     } else {
//         std::cout << "Очередь событий пуста.\n";
//     }
// }

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::queue<std::string> networkEvents;
    
//     addEvent(networkEvents, "Запрос от клиента A: GET /home");
//     addEvent(networkEvents, "Запрос от клиента B: POST /data");
//     addEvent(networkEvents, "Запрос от клиента C: GET /about");
    
//     processEvents(networkEvents);
//     processEvents(networkEvents);
//     processEvents(networkEvents);
//     processEvents(networkEvents);
    
//     return 0;
// }