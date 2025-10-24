// #include <iostream>
// #include <vector>
// #include <numeric>
// #include <algorithm>
// #include <iomanip>
// #include <cstdlib> 
// #include <ctime> 
// using namespace std;
// void Show(const vector<int>& vec) {
//     for (const auto& value : vec) {
//         cout << value << " ";
//     }
//     cout << endl;
// }
// double calculateMedian(vector<int>& vec) {
//     sort(vec.begin(), vec.end());
//     int n = vec.size();
//     if (n % 2 == 0) {
//         return (vec[n / 2 - 1] + vec[n / 2]) / 2.0;
//     } else {
//         return vec[n / 2];
//     }
// }
// int main() {
//     setlocale(LC_ALL, "rus");
//     vector<int> vec(50);
//     int start = 10, end = 100;
//     srand(static_cast<unsigned int>(time(nullptr)));
//     for (int i = 0; i < vec.size(); i++) {
//         vec[i] = rand() % (end - start + 1) + start;
//     }
//     sort(vec.begin(), vec.end(), [](int a, int b) { return a > b; });
//     Show(vec);
//     auto itMin = min_element(vec.begin(), vec.end());
//     auto itMax = max_element(vec.begin(), vec.end());
//     cout << "Минимальное потребление энергии: " << *itMin << endl;
//     int threshold = static_cast<int>(*itMax * 0.95);
//     bool isAboveThreshold = all_of(vec.begin(), vec.end(), [&threshold](int x) { return x >= threshold; });
//     if (!isAboveThreshold) {
//         cout << "Падал уровень ниже 5% от максимального." << endl;
//     } else {
//         cout << "Не падал уровень ниже 5% от максимального." << endl;
//     }
//     double averageConsumption = accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
//     cout << "Среднее потребление: " << averageConsumption << endl;
//     double median = calculateMedian(vec);
//     cout << "Медиана: " << median << endl;
//     return 0;
// }