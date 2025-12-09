// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <chrono>
// #include <random>

// int main() {
//     setlocale(LC_ALL, "rus");
//     const int NUM_ELEMENTS = 100000;
//     std::vector<int> data(NUM_ELEMENTS);
    
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<> dist(1, 1000);
    
//     for (int i = 0; i < NUM_ELEMENTS; ++i) {
//         data[i] = dist(gen);
//     }
    
//     auto measure_time = [](const std::string& name, auto&& func) {
//         auto start = std::chrono::steady_clock::now();
//         func();
//         auto end = std::chrono::steady_clock::now();
//         auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
//         std::cout << name << ": " << duration.count() << " мс\n";
//     };
    
//     std::cout << "Сравнение скорости записи в файл\n";
//     std::cout << "Количество элементов: " << NUM_ELEMENTS << "\n\n";
    
//     measure_time("Запись по одному элементу", [&]() {
//         std::ofstream file("method1.bin", std::ios::binary);
//         for (int i = 0; i < NUM_ELEMENTS; ++i) {
//             file.write(reinterpret_cast<char*>(&data[i]), sizeof(int));
//         }
//         file.close();
//     });
    
//     measure_time("Запись всех элементов сразу", [&]() {
//         std::ofstream file("method2.bin", std::ios::binary);
//         file.write(reinterpret_cast<char*>(data.data()), data.size() * sizeof(int));
//         file.close();
//     });
    
//     measure_time("Запись через вектор char", [&]() {
//         std::ofstream file("method3.bin", std::ios::binary);
//         const char* buffer = reinterpret_cast<const char*>(data.data());
//         file.write(buffer, data.size() * sizeof(int));
//         file.close();
//     });
    
//     std::cout << "\nПроверка целостности данных...\n";
    
//     std::ifstream file1("method1.bin", std::ios::binary);
//     std::ifstream file2("method2.bin", std::ios::binary);
    
//     std::vector<int> read1(NUM_ELEMENTS);
//     std::vector<int> read2(NUM_ELEMENTS);
    
//     file1.read(reinterpret_cast<char*>(read1.data()), NUM_ELEMENTS * sizeof(int));
//     file2.read(reinterpret_cast<char*>(read2.data()), NUM_ELEMENTS * sizeof(int));
    
//     file1.close();
//     file2.close();
    
//     if (data == read1 && data == read2) {
//         std::cout << "✓ Все файлы содержат одинаковые данные\n";
//     } else {
//         std::cout << "✗ Ошибка: данные в файлах различаются\n";
//     }
    
//     return 0;
// }