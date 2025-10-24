// #include <iostream>
// #include <vector>
// #include <numeric>
// #include <algorithm>
// #include <iomanip>
// #include <cstdlib> 
// #include <ctime> 
// using namespace std;
// void Show2(const vector<double>& vec) {
//     for (const auto& value : vec) {
//         cout << fixed << setprecision(2) << value << " "; 
//     }
//     cout << endl;
// }
// int main (){
//     setlocale(LC_ALL, "rus");
//     vector<double> vec(50);
//     srand(time(0));
//     for (int i = 0; i < vec.size(); i++) {
//         vec[i] = static_cast<double>(rand()) / RAND_MAX; 
//     }
//     Show2(vec);
//     vec.erase(remove_if(vec.begin(), vec.end(), [](double x) { return x < 0.1; }), vec.end());
//     if (vec.empty()) {
//         cout << "Все значения меньше 0.1." << endl;
//         return 0; 
//     }
//     auto itMax = max_element(vec.begin(), vec.end());
//     cout << "Максимальное значение амплитуды: " << *itMax << endl;
//     double total = accumulate(vec.begin(), vec.end(), 0.0);
//     double average = total / vec.size();
//     cout << "Среднее значение амплитуды: " << average << endl;
//     bool allAboveThreshold = all_of(vec.begin(), vec.end(), [](double x) { return x > 0.5; });
//     if (!allAboveThreshold) {
//         cout << "Не все значения превышают порог 0.5" << endl;
//     } else {
//         cout << "Все значения превышают порог 0.5" << endl;
//     }
//     sort(vec.begin(), vec.end());
//     cout << "10 максимальных значений амплитуд: " << endl;
//     for (int i = vec.size() - 10; i < vec.size(); i++) {
//         cout << fixed << setprecision(2) << vec[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }