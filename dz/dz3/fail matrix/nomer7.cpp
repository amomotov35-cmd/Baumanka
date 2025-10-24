// #include <iostream>
// #include <vector>
// #include <iomanip> 
// using namespace std;
// bool gaussElimination(vector<vector<double>>& A, vector<double>& B) {
//     int n = A.size();
//     for (int i = 0; i < n; i++) {
//         double maxVal = abs(A[i][i]);
//         int maxRow = i;
//         for (int k = i + 1; k < n; k++) {
//             if (abs(A[k][i]) > maxVal) {
//                 maxVal = abs(A[k][i]);
//                 maxRow = k;
//             }
//         }   
//         swap(A[i], A[maxRow]);
//         swap(B[i], B[maxRow]);
//         for (int k = i + 1; k < n; k++) {
//             double coeff = A[k][i] / A[i][i];
//             B[k] -= coeff * B[i];
//             for (int j = i; j < n; j++) {
//                 A[k][j] -= coeff * A[i][j];
//             }
//         }
//     }
//     vector<double> x(n);
//     for (int i = n - 1; i >= 0; i--) {
//         x[i] = B[i];
//         for (int j = i + 1; j < n; j++) {
//             x[i] -= A[i][j] * x[j];
//         }
//         x[i] /= A[i][i];
//     }
//     cout << "Решение:" << endl;
//     for (int i = 0; i < n; i++) {
//         cout << "x[" << i << "] = " << setprecision(4) << x[i] << endl;
//     }
//     return true;
// }
// int main() {
//   setlocale(LC_ALL, "rus");
//     vector<vector<double>> A = {
//         {1, 1, 1},
//         {2, -1, 3},
//         {-1, 4, -1}
//     };
//     vector<double> B = {6, 14, 2};
//     if (!gaussElimination(A, B)) {
//         cout << "Ошибка при решении системы." << endl;
//     }
//     return 0;
// }