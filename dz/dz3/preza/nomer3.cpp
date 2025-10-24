// #include <iostream> 
// #include <math.h>
// using namespace std;
// int main() {
//     setlocale(LC_ALL, "rus");
//     double matrix[3][3];
//     cout << "Введите кооринаты\n";
//     for (int i = 0; i < 3; i++) {
//         cin >> matrix[i][0] >> matrix[i][1];
//         matrix[i][2] = 1;
//     }
//     double a1 = (matrix[1][0] * matrix[2][1]) - (matrix[2][0] * matrix[1][1]);
//     double a2 = (matrix[1][0] * matrix[2][1]) - (matrix[2][0] * matrix[1][1]);
//     double a3 = (matrix[1][0] * matrix[2][1]) - (matrix[2][0] * matrix[1][1]);
//     double s = (a1 - a2 + a3);
//     if (s == 0) {
//         cout << "точки коллинеарны ";
//     }
//     else {
//         cout << "точки не коллинеарны ";
//     }

//     return 0;
// }