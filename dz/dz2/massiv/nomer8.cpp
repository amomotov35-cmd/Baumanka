// #include <iostream> 
// #include <limits> 
// using namespace std;
// int main() {
//     setlocale(LC_ALL, "rus");
//     const int n = 10;
//     double arr[n];
//     cout << "Введите 10 целых чисел:" << endl;
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     double maxV = arr[0], minV = arr[0];
//     int maxI = 0, minI = 0;
//     for (int i = 1; i < n; i++) {
//         if (arr[i] > maxV) {
//             maxV = arr[i];
//             maxI = i;
//         }
//         if (arr[i] < minV) {
//             minV = arr[i];
//             minI = i;
//         }
//     }
//     if (minI == 4 && maxI == 1) {
//         for (int i = 0; i < minI; i++) {
//             arr[i] = maxV;
//         }
//         cout << "Все элементы массива, предшествующие минимальному элементу, равны максимальному." << endl;
//         cout << "Изменённый массив:" << endl;
//         for (int i = 0; i < n; i++) {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
//     else {
//         cout << "Условия не выполнены: минимальный элемент не стоит на 5 месте или максимальный не стоит на 2 месте ." << endl;
//     }
//     return 0;
// }