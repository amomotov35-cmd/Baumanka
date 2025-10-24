// #include<iostream>
// #include<cmath>
// using namespace std;
// int main() {
// 	setlocale(LC_ALL, "rus");
// 	const int a = 8;
// 	int array[a];
// 	cout << "Введите 8 целых чисел:" << endl;
// 	for (int i = 0; i < 8; i += 2) {
// 		int m = (i / 2) + 1;
// 		cout << "Введите координаты вершины х"<<" "<< m <<" "<<"вершины:";
// 		cin >> array[i];
// 		cout << "Введите координаты вершины y"<<" "<< m <<" "<<"вершины:";
// 		cin >> array[i + 1];
// 		m += 1;
// 	}
//     double x1 = array[0];
//     double y1 = array[1]; // Точка A
//     double x2 = array[2];
//     double y2 = array[3]; // Точка B
//     double x3 = array[4];
//     double y3 = array[5]; // Точка C
//     double x4 = array[6];
//     double y4 = array[7]; // Точка D
//     double xAB = x2 - x1;
//     double yAB = y2 - y1;
//     double xCD = x4 - x3;
//     double yCD = y4 - y3;
//         double w = yAB * xCD - xAB * yCD;
//         if (w==0) {
//             cout<< "отрезки параллельны."<< endl;
//         } 
//         else {
//              double t = ((x1 - x3) * yCD - (y1 - y3) * xCD) / w;
//              double u = ((x1 - x3) * yAB - (y1 - y3) * xAB) / w;
//             if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
//                 cout<<"отрезки  пересекаются."<< endl;   
//             }
//             else {
//             cout <<"отрезки не пересекаются."<< endl;
//             }
//         }
// 	return 0;
// }