// #include <iostream>
// using namespace std;
// void InsertionSort(int arr[], int a) {
// 	for (int i = 1; i < a; i++) {
// 		int k = arr[i];
// 		int j = i - 1;
// 		// сдвигаем вперед элементы массива > k 
// 		while (j >= 0 && arr[j] > k) {
// 			arr[j + 1] = arr[j];
// 			j = j - 1;
// 		}
// 		arr[j + 1] = k;
// 	}
// }
// int main() {
// 	setlocale(LC_ALL, "rus");
// 	const int a = 10;
// 	int arr[a];
// 	int s = 0;
// 	int b;
// 	//заполняем массив
// 	cout << "Введите 10 целых чисел:" << endl;
// 	for (int i = 0; i < a; i++) {
// 		cout << "Число" << i + 1 << ":";
// 		cin >> arr[i];
// 		s += arr[i];
// 	}
// 	// вывод элементов массива
// 	cout << "Элементы массива:" << endl;
// 	for (int i = 0; i < a; i++) {
// 		cout << arr[i] << " ";
// 	}
// 	// поиск минимального элемента массива
// 	cout << endl;
// 	b = arr[0];
// 	for (int i = 1; i < a; i++) {
// 		if (arr[i] < b) {
// 			b = arr[i];
// 		}
// 	}
// 	cout << "Сумма всех элементов массива:" << s << endl;
// 	cout << "Минимальный элемент массива : " << b << endl;
// 	//сортировка в порядке возрастания
// 	InsertionSort(arr, a);
// 	//вывод отсортированных элементов
// 	cout << "Отсортированные элементы массива:" << endl;
// 	for (int i = 0; i < a; i++) {
// 		cout << arr[i] << " ";
// 	}
// 	cout << endl;
// 	return 0;
// }