// #include <iostream>
// using namespace std;
// int main() {
//     setlocale(LC_ALL, "rus");
//     int n;
//     cout << "Введите количество элементов массива: ";
//     cin >> n;
//     if (n <= 0) {
//         cout << "Количество элементов должно быть натуральным числом." << endl;
//         return 1;
//     }
//     int* arr = new int[n];
//     cout << "Введите " << n << " целых чисел:" << endl; 
//     int s = 0;
//     int max = INT_MIN;
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//         if (arr[i] % 2 == 0) {
//             s++;
//         }
//         else {
//             if (arr[i] > max) {
//                 max = arr[i];
//             }
//         }
//     }
//         delete[] arr;
//         if (max == INT_MIN) {
//             cout << "Нет нечетных чисел в последовательности." << endl;
//         }
//         else {
//             cout << "Наибольшее нечетное число: " << max << endl;
//         }
//         cout << "Количество четных элементов:" << " " << s << endl;   
//     return 0;
// }