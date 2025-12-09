// #include <iostream>
// #include <queue>
// #include <string>
// #include <vector>

// struct Order {
//     std::string customerName;
//     std::vector<std::string> items;
// };

// void addOrder(std::queue<Order>& orderQueue, const Order& newOrder) {
//     orderQueue.push(newOrder);
//     std::cout << "Заказ добавлен для клиента: " << newOrder.customerName << "\n";
// }

// void processOrder(std::queue<Order>& orderQueue) {
//     if (!orderQueue.empty()) {
//         Order currentOrder = orderQueue.front();
//         std::cout << "\nОбрабатывается заказ клиента: " << currentOrder.customerName << "\n";
//         std::cout << "Товары в заказе:\n";
//         for (const auto& item : currentOrder.items) {
//             std::cout << "- " << item << "\n";
//         }
//         orderQueue.pop();
//         std::cout << "Заказ обработан и удален из очереди.\n";
//     } else {
//         std::cout << "Очередь заказов пуста.\n";
//     }
// }

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::queue<Order> ordersQueue;
    
//     Order order1;
//     order1.customerName = "Иван Петров";
//     order1.items = {"Ноутбук", "Мышка", "Чехол"};
    
//     Order order2;
//     order2.customerName = "Мария Сидорова";
//     order2.items = {"Книга", "Ручка"};
    
//     Order order3;
//     order3.customerName = "Алексей Иванов";
//     order3.items = {"Смартфон", "Наушники", "Зарядное устройство"};
    
//     addOrder(ordersQueue, order1);
//     addOrder(ordersQueue, order2);
//     addOrder(ordersQueue, order3);
    
//     processOrder(ordersQueue);
//     processOrder(ordersQueue);
//     processOrder(ordersQueue);
//     processOrder(ordersQueue);
    
//     return 0;
// }