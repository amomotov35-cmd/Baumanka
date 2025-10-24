//#include<iostream>
//#include<cmath>
//using namespace std;
//int main() {
//	setlocale(LC_ALL, "rus");
//	const int a = 8;
//	int array[a];
//	int m = 1;
//	cout << "Введите 8 целых чисел:" << endl;
//	for (int i = 0; i <8; i += 2) {
//		cout << "Введите координаты вершины х"<<" "<< m <<" "<<"вершины:";
//		cin >> array[i];
//		cout << "Введите координаты вершины y"<<" "<< m <<" "<<"вершины:";
//		cin >> array[i + 1];
//		m += 1;
//	}
//	double p = 0;
//	for (int i = 0;i < a - 2;i += 2) {
//		double x = pow((array[i + 2] - array[i]), 2);
//		double y = pow((array[i + 3] - array[i+1]), 2);
//		double r = pow((x + y), 0.5);
//		p += r;
//	 }
//	double x = pow((array[0] - array[6]), 2);
//	double y = pow((array[1] - array[7]), 2);
//	double r = pow((x + y), 0.5);
//	p += r;
//	cout << "Периметр многоугольника:" << " " << p << endl;
//	return 0;
//}