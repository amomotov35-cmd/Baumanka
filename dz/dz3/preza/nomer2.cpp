// #include <iostream> 
// #include <math.h>
// using namespace std;
// int main() {
// 	setlocale(LC_ALL, "rus");
// 	double ta1[2], ta2[2], fi = 0;
// 	cout << "Введите координаты\n";
// 	cin >> ta1[0] >> ta1[1];
// 	cout << "Введите угол\n";
// 	cin >> fi;
// 	double matrix[2][2] = { {cos(fi * M_PI / 180), sin(fi * M_PI / 180)},{-sin(fi * M_PI / 180),cos(fi * M_PI / 180)}};
// 		for (int i = 0; i < 2; i++) {
// 		double s = 0;
// 			for (int j = 0; j < 2; j++)
// 			{
// 				s += matrix[i][j] * ta1[j];
// 			}
// 			ta2[i] = s;
// 			s = 0;
// 		}
// 		cout << "x = " << ta1[0] << ", y = " << ta1[1] << endl;
// 		cout << "x1 = " << ta2[0] << ", y1 = " << ta2[1] << endl;
// 		cout << cos(fi * M_PI / 180);
// 		return 0;
// }
    