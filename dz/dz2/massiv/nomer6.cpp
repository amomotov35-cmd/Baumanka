// #include <iostream> 
// #include <limits> 
// using namespace std;
// int main() {
//     setlocale(LC_ALL, "rus");
//     const int n = 15;
//     double arr[n];
//     cout << "Введите 15 вещественных чисел:" << endl;
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
//     if (minI == 1 && maxI == 0) {
//         for (int i = 0; i < n; i++) {
//             arr[i] /= 2.0;
//         }
//         cout << "Все элементы массива уменьшены в 2 раза:" << endl;
//         for (int i = 0; i < n; i++) {
//             cout << arr[i] << " ";
//         }
//         cout << endl;

//     }
//     else {
//         cout << "Условия не выполнены: минимальный элемент не на 2 месте или максимальный элемент не на 1 месте." << endl;
//     }
//     return 0;
// }