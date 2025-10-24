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
// int main() {
//     setlocale(LC_ALL, "rus");
//     srand(static_cast<unsigned int>(time(0)));
//     vector<int> vec(30);
//     int start = 10, end = 100;
//     for (int i = 0; i < vec.size(); i++) {
//         vec[i] = rand() % (end - start + 1) + start;
//     }
//     Show(vec); 
//     int total = accumulate(vec.begin(), vec.end(), 0);
//     cout << "Общее потребление за месяц: " << total << " кВт·ч" << endl;
//     double average = static_cast<double>(total) / vec.size();
//     cout << "Среднее значение потребления воды за месяц: " << average << " кВт·ч" << endl;
//     auto itMin = min_element(vec.begin(), vec.end());
//     auto itMax = max_element(vec.begin(), vec.end());
//     cout << "Минимальное потребление энергии: " << *itMin << " кВт·ч в день " << (itMin - vec.begin() + 1) << endl;
//     cout << "Максимальное потребление энергии: " << *itMax << " кВт·ч в день " << (itMax - vec.begin() + 1) << endl;
//     double peakThreshold = average * 1.2;
//     vector<int> peakDays;
//     for (const auto& value : vec) {
//         if (value > peakThreshold) {
//             peakDays.push_back(value);
//         }
//     }
//     cout << "<<Пиковые>> дни:" << endl;
//     Show(peakDays);
//     return 0;
// }