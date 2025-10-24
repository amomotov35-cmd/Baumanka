// #include<iostream>
// #include<cmath>
// #include <cstdlib>
// #include <locale>
// using namespace std;
// double DlinaStorona(int x1, int y1, int x2, int y2) {
//     double n = 0;
//     n = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
//     return n;
// }
// int Orientetion(int x1, int x2, int x3, int y1, int y2, int y3) {
//     int det;
//     det = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
//     return det;
// }

// int main() {
//     setlocale(LC_ALL, "rus");
//     int n = 0;
//     int** arr;
//     cout << "Введите количество вершин для 1-го многоугольника: ";
//     cin >> n;
//     if (n < 3) {
//         cout << "Ошибка, у многоугольника должно быть минимум 3 вершины " << endl;
//     }
//     else {
//         arr = new int* [n];
//         for (int i = 0; i < n; i++) {
//             arr[i] = new int[2];
//         }
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < 2; ++j) {
//                 if (j == 0) {
//                     cout << "Введите x для " << i + 1 << " вершины: ";
//                     cin >> arr[i][j];
//                 }
//                 if (j == 1) {
//                     cout << "Введите y для " << i + 1 << " вершины: ";
//                     cin >> arr[i][j];
//                 }
//             }
//         }
//     }
//     int** arr2;
//     int n2 = 0;
//     cout << "Введите количество вершин для 2-го многоугольника: ";
//     cin >> n2;
//     if (n2 < 3) {
//         cout << "Ошибка, у многоугольника должно быть минимум 3 вершины " << endl;
//     }
//     else {
//         arr2 = new int* [n2];
//         for (int i = 0; i < n2; i++) {
//             arr2[i] = new int[2];
//         }
//         for (int i = 0; i < n2; i++) {
//             for (int j = 0; j < n2 - 1; i++) {
//                 if (j == 0) {
//                     cout << "Введите x для " << i + 1 << " вершины: ";
//                     cin >> arr[i][j];
//                 }
//                 if (j == 1) {
//                     cout << "Введите y для " << i + 1 << " вершины: ";
//                     cin >> arr[i][j];
//                 }
//             }
//         }
//     }
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n2 - 1; i++) {
//             int s1 = Orientetion(arr[i][0], arr[i + 1][0], arr2[j][0], arr[i][1], arr[i + 1][1], arr2[j][1]);
//             int s2 = Orientetion(arr[i][0], arr[i + 1][0], arr2[j + 1][0], arr[i][1], arr[i + 1][1], arr2[j + 1][1]);
//             if (s1 != s2 && s1 != 0 && s2 != 0) {
//                 cout << "Многоугольники пересекаются" << endl;
//                 exit(EXIT_FAILURE);
//             }
//             else if ((s1 != s2 && s1 == 0) or (s1 != s2 && s2 == 0)) {
//                 cout << "Многоугольники пересекаются" << endl;
//                 exit(EXIT_FAILURE);
//             }
//         }
//     }
//     cout << "Многоугольники не пересекаются" << endl;
//     return 0;
// }