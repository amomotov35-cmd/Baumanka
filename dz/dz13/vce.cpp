// #include <iostream>
// #include <string>

// using namespace std;

// // Задача 1: Класс Book
// class Book {
// private:
//     string title;
//     string author;
//     int year;
    
// public:
//     void setInfo(string t, string a, int y) {
//         title = t;
//         author = a;
//         year = y;
//     }
    
//     void displayInfo() {
//         cout << "Название: " << title << ", Автор: " << author << ", Год выпуска: " << year << endl;
//     }
// };

// // Задача 2: Класс Rectangle
// class Rectangle {
// private:
//     double length;
//     double width;
    
// public:
//     void setDimensions(double l, double w) {
//         length = l;
//         width = w;
//     }
    
//     double calculateArea() {
//         return length * width;
//     }
    
//     double calculatePerimeter() {
//         return 2 * (length + width);
//     }
    
//     void displayInfo() {
//         cout << "Длина: " << length << ", Ширина: " << width 
//              << ", Площадь: " << calculateArea() 
//              << ", Периметр: " << calculatePerimeter() << endl;
//     }
// };

// int main() {
//     // Задача 1
//     Book book1;
//     book1.setInfo("Война и мир", "Лев Толстой", 1869);
//     book1.displayInfo();
    
//     // Задача 2
//     Rectangle rect1;
//     rect1.setDimensions(5.0, 3.0);
//     rect1.displayInfo();
    
//     return 0;
// }


// // ЗАДАЧА 1: Класс Book
// class Book {
// private:
//     string title;
//     string author;
//     int year;
    
// public:
//     Book(string t, string a, int y) : title(t), author(a), year(y) {}
    
//     void displayInfo() {
//         cout << "Название: " << title << ", Автор: " << author << ", Год выпуска: " << year << endl;
//     }
// };

// // ЗАДАЧА 2: Класс Rectangle
// class Rectangle {
// private:
//     double length;
//     double width;
    
// public:
//     Rectangle(double l, double w) : length(l), width(w) {}
    
//     double calculateArea() {
//         return length * width;
//     }
    
//     double calculatePerimeter() {
//         return 2 * (length + width);
//     }
    
//     void displayInfo() {
//         cout << "Длина: " << length << ", Ширина: " << width 
//              << ", Площадь: " << calculateArea() 
//              << ", Периметр: " << calculatePerimeter() << endl;
//     }
// };

// int main() {
//     // ЗАДАЧА 1: Демонстрация класса Book
//     Book book1("Война и мир", "Лев Толстой", 1869);
//     book1.displayInfo();
    
//     // ЗАДАЧА 2: Демонстрация класса Rectangle
//     Rectangle rect1(5.0, 3.0);
//     rect1.displayInfo();
    
//     return 0;
// }


// // ЗАДАЧА 1: Создание базового класса Publication и производного класса Book
// class Publication {
// protected:
//     string title;
// public:
//     Publication(string t) {
//         title = t;
//     }
// };

// class Book : public Publication {
// private:
//     string author;
//     int year;
// public:
//     Book(string t, string a, int y) : Publication(t) {
//         author = a;
//         year = y;
//     }
    
//     void displayInfo() {
//         cout << "Название: " << title << ", Автор: " << author 
//              << ", Год выпуска: " << year << endl;
//     }
// };

// // ЗАДАЧА 2: Создание базового класса Shape и производного класса Rectangle
// class Shape {
// protected:
//     double length;
// public:
//     Shape(double l) {
//         length = l;
//     }
    
//     virtual void displayInfo() {
//         cout << "Длина: " << length << endl;
//     }
// };

// class Rectangle : public Shape {
// private:
//     double width;
// public:
//     Rectangle(double l, double w) : Shape(l) {
//         width = w;
//     }
    
//     double calculateArea() {
//         return length * width;
//     }
    
//     double calculatePerimeter() {
//         return 2 * (length + width);
//     }
    
//     void displayInfo() override {
//         cout << "Длина: " << length << ", Ширина: " << width 
//              << ", Площадь: " << calculateArea() 
//              << ", Периметр: " << calculatePerimeter() << endl;
//     }
// };

// int main() {
//     // Демонстрация ЗАДАЧИ 1: Работа с классом Book
//     Book book("Война и мир", "Лев Толстой", 1869);
//     book.displayInfo();
    
//     // Демонстрация ЗАДАЧИ 2: Работа с классом Rectangle
//     Rectangle rect(5.0, 3.0);
//     rect.displayInfo();
    
//     return 0;
// }