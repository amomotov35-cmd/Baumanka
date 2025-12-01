// #include <iostream>
// #include <cmath>
// #define _USE_MATH_DEFINES

// struct Circle {
//     double radius;
// };

// struct Rectangle {
//     double length;
//     double width;
// };

// union Shape {
//     Circle circle;
//     Rectangle rectangle;
// };

// int main() {
//     setlocale(LC_ALL, "rus");
//     Shape figure;
//     int choice;
    
//     std::cout << "Выберите фигуру (1 - круг, 2 - прямоугольник): ";
//     std::cin >> choice;
    
//     if (choice == 1) {
//         std::cout << "Введите радиус круга: ";
//         std::cin >> figure.circle.radius;
//         double area = M_PI * figure.circle.radius * figure.circle.radius;
//         std::cout << "Площадь круга: " << area << std::endl;
//     }
//     else if (choice == 2) {
//         std::cout << "Введите длину прямоугольника: ";
//         std::cin >> figure.rectangle.length;
//         std::cout << "Введите ширину прямоугольника: ";
//         std::cin >> figure.rectangle.width;
//         double area = figure.rectangle.length * figure.rectangle.width;
//         std::cout << "Площадь прямоугольника: " << area << std::endl;
//     }
//     else {
//         std::cout << "Неверный выбор." << std::endl;
//     }
    
//     return 0;
// }