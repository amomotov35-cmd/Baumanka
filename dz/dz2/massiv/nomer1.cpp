// #include <iostream>
// #include <cmath>
// using namespace std;
// int main() {
//     setlocale(LC_ALL, "rus");
//     int k;
//     int n;
//     int s = 0;
//     cout << "Введите количество элементов массива (>=1): ";
//     cin >> n;
//     if (n < 1) {
//             cout << "Количество элементов должно быть >= 1." << endl;
//             return 1;
//     }
//     cout << "Введите k: ";
//     cin >> k;
//     int arr[n];
//     cout << "Введите элементы массива:" << endl;        
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     for (int i = 0; i < n; i++) {
//         if (arr[i] > pow(2, k)) {
//                 s++;
//         }
//     }
//     cout << "Количество элементов:" << " " << s << endl;
//     return 0;
// }