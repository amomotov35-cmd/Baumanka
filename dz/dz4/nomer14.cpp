// #include <iostream>
// #include <vector>
// #include <numeric>
// #include <algorithm>
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
//     vector<int> vec(24);
//     int start = 100, end = 500;
//     srand(static_cast<unsigned int>(time(nullptr)));
//     for (int i = 0; i < vec.size(); i++) {
//         vec[i] = rand() % (end - start + 1) + start;
//     }
//     Show(vec);
//     vec.erase(remove_if(vec.begin(), vec.end(), [](int x) { return (x < 0 || x > 500); }), vec.end());
//     if (vec.empty()) {
//         cout << "Все значения были удалены." << endl;
//         return 0;
//     }
//     int total = accumulate(vec.begin(), vec.end(), 0);
//     cout << "Суммарное потребление: " << total << endl;
//     double average = static_cast<double>(total) / vec.size(); 
//     cout << "Среднее потребление: " << average << endl;
//     auto itMax = max_element(vec.begin(), vec.end());
//     cout << "Максимальное потребление: " << *itMax << " в час " << (itMax - vec.begin()) << endl;
//     vector<int> vec2(vec.size());
//     transform(vec.begin(), vec.end(), vec2.begin(), [average](int x) { return x - average; });
//     cout << "Отклонение каждого часа: ";
//     Show(vec2);
//     sort(vec.begin(), vec.end());
//     cout << "Топ-5 минимальных часов потребления: " << endl;
//     for (int i = 0; i < 5 && i < vec.size(); i++) { 
//         cout << vec[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }