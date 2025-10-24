// #include <iostream>
// #include <vector>
// #include <numeric>
// #include <algorithm>
// #include <cstdlib>
// #include <ctime>
// using namespace std;
// void Show(const vector<double>& vec) {
//     for (const auto& value : vec) {
//         cout << value << " ";
//     }
//     cout << endl;
// }
// int main() {
//     setlocale(LC_ALL, "rus");
//     srand(static_cast<unsigned int>(time(0))); 
//     vector<vector<double>> temp(5, vector<double>(30));
//     vector<vector<double>> pressure(5, vector<double>(100));
//     for (int i = 0; i < 5; i++) {
//         cout << i + 1 << " канал температуры: ";
//         for (int j = 0; j < 30; j++) {
//             temp[i][j] = static_cast<double>(rand()) / RAND_MAX * 100;
//             cout << temp[i][j] << " ";
//         }
//         cout << endl;
//     }
//     for (int i = 0; i < 5; i++) {
//         cout << i + 1 << " канал давления: ";
//         for (int j = 0; j < 100; j++) {
//             pressure[i][j] = static_cast<double>(rand()) / RAND_MAX * 10;
//             cout << pressure[i][j] << " ";
//         }
//         cout << endl;
//     }
//     for (int i = 0; i < 5; i++) {
//         double total = accumulate(temp[i].begin(), temp[i].end(), 0.0);
//         double average = total / temp[i].size();
//         cout << "Средняя температура " << i + 1 << " канала: " << average << endl;
//     }
//     for (int i = 0; i < 5; i++) {
//         auto itMin = min_element(pressure[i].begin(), pressure[i].end());
//         auto itMax = max_element(pressure[i].begin(), pressure[i].end());
//         cout << "Минимальное давление " << i + 1 << " канала: " << *itMin << endl;
//         cout << "Максимальное давление " << i + 1 << " канала: " << *itMax << endl;
//     }
//     int Ti = 0; 
//     double Tmax = 0.0;
//     for (int i = 0; i < 5; i++) {
//         auto itMin = min_element(temp[i].begin(), temp[i].end());
//         auto itMax = max_element(temp[i].begin(), temp[i].end());
//         if ((*itMax - *itMin) > Tmax) {
//             Tmax = *itMax - *itMin;
//             Ti = i;
//         }
//     }
//     cout << "Канал " << Ti + 1 << " с наибольшей вариацией температуры, которая равна " << Tmax << endl;
//     vector<vector<double>> pressure2(5, vector<double>(100));
//     for (int i = 0; i < 5; i++) {
//         double itMin = *min_element(pressure[i].begin(), pressure[i].end());
//         double itMax = *max_element(pressure[i].begin(), pressure[i].end());
//         transform(pressure[i].begin(), pressure[i].end(), pressure2[i].begin(), [itMin, itMax](double x) { 
//             return (x - itMin) / (itMax - itMin); 
//         });
//     }
//     cout << "Значения давления после нормализации: " << endl;
//     for (int i = 0; i < 5; i++) {
//         cout << i + 1 << " канал давления: ";
//         Show(pressure2[i]);
//     }
//     cout << "Значения давления после нормализации, которые превышают 0.9 (пики): " << endl;
//     for (int i = 0; i < 5; i++) {
//         cout << i + 1 << " канал давления: ";
//         for_each(pressure2[i].begin(), pressure2[i].end(), [](double x) { 
//             if (x > 0.9) { 
//                 cout << x << " "; 
//             } 
//         });
//         cout << endl;
//     }
//     int totali = 0; 
//     double totalMax = 0.0;
//     for (int i = 0; i < 5; i++) {
//         double total = accumulate(temp[i].begin(), temp[i].end(), 0.0);
//         double average = total / temp[i].size();
//         if (average > totalMax) {
//             totalMax = average; 
//             totali = i;
//         }
//     }
//     cout << "Канал с максимальной средней температурой: " << totali + 1 << endl;
//     Show(temp[totali]);
//     return 0;
// }