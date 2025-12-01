// #include <iostream>
// #include <queue>
// #include <string>

// void addToQueue(std::queue<std::string>& queue, const std::string& person) {
//     queue.push(person);
//     std::cout << person << " добавлен в очередь.\n";
// }

// void processQueue(std::queue<std::string>& queue) {
//     if (!queue.empty()) {
//         std::cout << queue.front() << " обработан и удален из очереди.\n";
//         queue.pop();
//     } else {
//         std::cout << "Очередь пуста.\n";
//     }
// }

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::queue<std::string> peopleQueue;
    
//     addToQueue(peopleQueue, "Анна");
//     addToQueue(peopleQueue, "Борис");
//     addToQueue(peopleQueue, "Виктор");
    
//     processQueue(peopleQueue);
//     processQueue(peopleQueue);
//     processQueue(peopleQueue);
//     processQueue(peopleQueue);
    
//     return 0;
// }