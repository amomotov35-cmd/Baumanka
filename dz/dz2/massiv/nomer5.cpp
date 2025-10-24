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
//     if (minI == 4 && maxI == 9) {
//         double p = (maxV + minV)/2.0;
//         cout << "Среднее арифметическое максимального (" << maxV << ") и минимального (" << minV << ") элементов: " << p << endl;
//     }
//     else {
//         cout << "Максимальный элемент не стоит на 10 месте или минимальный элемент не стоит на 5 месте ." << endl;
//     }

//     return 0;
// }