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
//     int maxV = arr[0], minV = arr[0];
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
//     swap(arr[minI], arr[0]);
//     if (maxI == 0) {
//         maxI = minI; 
//     }
//     swap(arr[maxI], arr[n - 1]);
//     cout << "Измененная последовательность:" << endl;
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }