// #include <iostream> 
// #include <limits> 
// using namespace std;
// int main() {
//     setlocale(LC_ALL, "rus");
//     const int n = 15;
//     double arr[n];
//     cout << "Введите 15 целых чисел:" << endl;
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
//     if (minV == 0 || maxV == 0) {
//         for (int i = 0; i < minI; i++) {
//             arr[i] = 0;
//         }
//         cout << "Все элементы массива, предшествующие минимальному элементу, обнулены:" << endl;
//         for (int i = 0; i < n; i++) {
//             cout << arr[i] << " ";
//         }
//         cout << endl;

//     }
//     else {
//         cout << "Условия не выполнены: минимальный или максимальный элемент не равны 0." << endl;
//     }
//     return 0;
// }