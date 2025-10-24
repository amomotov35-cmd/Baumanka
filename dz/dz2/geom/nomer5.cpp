// #include<iostream>
// #include<cmath>
// using namespace std;
// int main() {
// 	setlocale(LC_ALL, "rus");
// 	const int a = 6;
// 	int array[a];
// 	cout << "Введите 6 целых чисел:" << endl;
// 	for (int i = 0; i < 6; i += 2) {
// 		int m = (i / 2) + 1;
// 		cout << "Введите координаты вершины х"<<" "<< m <<" "<<"вершины:";
// 		cin >> array[i];
// 		cout << "Введите координаты вершины y"<<" "<< m <<" "<<"вершины:";
// 		cin >> array[i + 1];
// 		m += 1;
// 	}
// 		double x1 = (array[2] - array[0]);
// 		double x2 = (array[4] - array[0]);
// 		double y1 = (array[3] - array[1]);
// 		double y2 = (array [5] - array[1]);
// 		double p = ((x1 * y2) - (y1 * x2));
// 		if (p == 0) {
// 			cout << "Точки лежат на одной прямой" << endl;
// 		}
// 		else {
// 			cout << "Точки не лежат на одной прямой" << endl;
// 		}
// 	return 0;
// }