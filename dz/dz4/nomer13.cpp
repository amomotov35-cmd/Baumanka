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
//     vector<int> vec(50);
//     int start = 0, end = 15;
//     srand(static_cast<unsigned int>(time(nullptr))); 
//     for (int i = 0; i < vec.size(); i++) {
//         vec[i] = rand() % (end - start + 1) + start;
//     }
//     vec.erase(remove_if(vec.begin(), vec.end(), [](int x) { return (x < 0 || x > 12); }), vec.end());
//     if (vec.empty()) {
//         cout << "Вектор пуст, все значения были удалены." << endl;
//         return 0;
//     }
//     double average = accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
//     cout << "Среднее давление: " << average << endl;
//     auto itMin = min_element(vec.begin(), vec.end());
//     auto itMax = max_element(vec.begin(), vec.end());
//     cout << "Минимальное давление: " << *itMin << endl;
//     cout << "Максимальное давление: " << *itMax << endl;
//     cout << "Значения, превышающие 8 бар: ";
//     for_each(vec.begin(), vec.end(), [](int x) { if (x > 8) { cout << x << " "; } });
//     cout << endl;
//     double median = calculateMedian(vec);
//     cout << "Медиана давления: " << median << endl;
//     return 0;
// }