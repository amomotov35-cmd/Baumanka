#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    setlocale(LC_ALL, "rus");
    int n, m;
    std::cout << "Введите размеры матрицы N и M: ";
    std::cin >> n >> m;
    
    auto matrix = std::make_unique<double[]>(n * m);
    
    std::cout << "Введите элементы матрицы " << n << "x" << m << ":\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> matrix[i * m + j];
        }
    }
    
    auto sumColumns = [&]() -> std::vector<double> {
        std::vector<double> sums(m, 0.0);
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                sums[j] += matrix[i * m + j];
            }
        }
        return sums;
    };
    
    auto maxIndex = [](const std::vector<double>& vec) -> int {
        return std::distance(vec.begin(), 
                            std::max_element(vec.begin(), vec.end()));
    };
    
    auto sums = sumColumns();
    int maxIdx = maxIndex(sums);
    
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Суммы столбцов: [";
    for (size_t i = 0; i < sums.size(); ++i) {
        std::cout << sums[i];
        if (i < sums.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    
    std::cout << "Столбец с максимальной суммой: " << maxIdx + 1 
              << " (" << sums[maxIdx] << ")" << std::endl;
    
    return 0;
}