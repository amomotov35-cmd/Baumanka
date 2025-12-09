// #include <iostream>

// struct Date {
//     int year;
//     int month;
//     int day;
// };

// struct Time {
//     int hour;
//     int minute;
//     int second;
// };

// union DateTime {
//     Date date;
//     Time time;
// };

// int main() {
//     setlocale(LC_ALL, "rus");
//     DateTime dt;
    
//     std::cout << "Введите год: ";
//     std::cin >> dt.date.year;
    
//     std::cout << "Введите месяц: ";
//     std::cin >> dt.date.month;
    
//     std::cout << "Введите день: ";
//     std::cin >> dt.date.day;
    
//     std::cout << "Введите час: ";
//     std::cin >> dt.time.hour;
    
//     std::cout << "Введите минуту: ";
//     std::cin >> dt.time.minute;
    
//     std::cout << "Введите секунду: ";
//     std::cin >> dt.time.second;
    
//     std::cout << "Дата и время: " 
//               << dt.date.year << "-" 
//               << dt.date.month << "-" 
//               << dt.date.day << " "
//               << dt.time.hour << ":" 
//               << dt.time.minute << ":" 
//               << dt.time.second << std::endl;
    
//     return 0;
// }