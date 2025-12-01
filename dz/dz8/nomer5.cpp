// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <algorithm>
// #include <iomanip>

// struct Student {
//     int id;
//     char name[50];
//     int age;
//     double average_grade;
// };

// void addStudentToFile(const std::string& filename, const Student& student) {
//     std::ofstream file(filename, std::ios::binary | std::ios::app);
//     file.write(reinterpret_cast<const char*>(&student), sizeof(Student));
//     file.close();
// }

// std::vector<Student> readAllStudents(const std::string& filename) {
//     std::vector<Student> students;
//     std::ifstream file(filename, std::ios::binary);
    
//     Student student;
//     while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
//         students.push_back(student);
//     }
    
//     file.close();
//     return students;
// }

// int main() {
//     setlocale(LC_ALL, "rus");
//     const std::string filename = "students.dat";
    
//     Student students[] = {
//         {1, "Иван Петров", 20, 4.5},
//         {2, "Мария Сидорова", 19, 4.8},
//         {3, "Алексей Иванов", 21, 4.2}
//     };
    
//     for (const auto& student : students) {
//         addStudentToFile(filename, student);
//     }
    
//     auto allStudents = readAllStudents(filename);
    
//     std::cout << "=== Список всех студентов ===\n";
//     std::cout << " ID | Имя                | Возраст | Средний балл\n";
//     std::cout << "----+--------------------+---------+-------------\n";
    
//     for (const auto& student : allStudents) {
//         std::cout << std::setw(3) << student.id << " | "
//                   << std::setw(20) << student.name << " | "
//                   << std::setw(7) << student.age << " | "
//                   << std::fixed << std::setprecision(2) << student.average_grade << std::endl;
//     }
    
//     if (!allStudents.empty()) {
//         auto bestStudent = *std::max_element(allStudents.begin(), allStudents.end(),
//             [](const Student& a, const Student& b) {
//                 return a.average_grade < b.average_grade;
//             });
        
//         std::cout << "\nСтудент с наивысшим баллом:\n";
//         std::cout << bestStudent.name << " - " << bestStudent.average_grade << std::endl;
//     }
    
//     std::cout << "\nОбщее количество студентов: " << allStudents.size() << std::endl;
    
//     return 0;
// }