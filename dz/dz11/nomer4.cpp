// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <numeric>

// int main() {
//     setlocale(LC_ALL, "rus");
//     const std::string filename = "numbers.bin";
//     std::vector<int> numbers = {15, 23, 7, 42, 18, 91, 3, 56, 77, 10};
    
//     std::ofstream outFile(filename, std::ios::binary);
//     outFile.write(reinterpret_cast<const char*>(numbers.data()), 
//                   numbers.size() * sizeof(int));
//     outFile.close();
    
//     std::ifstream inFile(filename, std::ios::binary | std::ios::ate);
//     std::streamsize fileSize = inFile.tellg();
//     inFile.seekg(0, std::ios::beg);
    
//     std::vector<int> readNumbers(fileSize / sizeof(int));
//     inFile.read(reinterpret_cast<char*>(readNumbers.data()), fileSize);
//     inFile.close();
    
//     std::cout << "Размер файла: " << fileSize << " байт\n";
//     std::cout << "Прочитанные числа:\n";
//     for (size_t i = 0; i < readNumbers.size(); ++i) {
//         std::cout << readNumbers[i];
//         if (i < readNumbers.size() - 1) std::cout << ", ";
//     }
    
//     int sum = std::accumulate(readNumbers.begin(), readNumbers.end(), 0);
//     double average = static_cast<double>(sum) / readNumbers.size();
    
//     std::cout << "\nСумма чисел: " << sum << std::endl;
//     std::cout << "Среднее значение: " << average << std::endl;
    
//     return 0;
// }