// #include <iostream>
// #include <iomanip>
// #include <cstring>
// #include <cmath>
// #include <cstdlib>
// using namespace std;

//  ЗАДАЧА 1: 
//  {
//     int x = 10, y = 20;
//     int *p1 = &x;
//     int *p2 = &y;
    
//     cout << "До обмена:" << endl;
//     cout << "p1 = " << p1 << ", *p1 = " << *p1 << endl;
//     cout << "p2 = " << p2 << ", *p2 = " << *p2 << endl;
    
//     void swapPointers(int **a, int **b) {
//         int *temp = *a;
//         *a = *b;
//         *b = temp;
//     }
    
//     swapPointers(&p1, &p2);
    
//     cout << "\nПосле обмена:" << endl;
//     cout << "p1 = " << p1 << ", *p1 = " << *p1 << endl;
//     cout << "p2 = " << p2 << ", *p2 = " << *p2 << endl;
// }


//  {
//     int n, m;
//     cout << "Введите n и m: ";
//     cin >> n >> m;
    
//     //  Выделение памяти
//     int** allocate2D(int n, int m) {
//         int **arr = new int*[n];
//         for (int i = 0; i < n; i++) {
//             arr[i] = new int[m];
//         }
//         return arr;
//     }
    
//     //  Освобождение памяти
//     void free2D(int **arr, int n) {
//         for (int i = 0; i < n; i++) {
//             delete[] arr[i];
//         }
//         delete[] arr;
//     }
    
//     //  Транспонирование
//     int** transpose(int **matrix, int n, int m) {
//         int **result = allocate2D(m, n);
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 result[i][j] = matrix[j][i];
//             }
//         }
//         return result;
//     }
    
//     //  Сортировка строк по сумме
//     void sortRowsBySum(int **arr, int n, int m) {
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = 0; j < n - i - 1; j++) {
//                 int sum1 = 0, sum2 = 0;
//                 for (int k = 0; k < m; k++) {
//                     sum1 += arr[j][k];
//                     sum2 += arr[j + 1][k];
//                 }
//                 if (sum1 > sum2) {
//                     int *temp = arr[j];
//                     arr[j] = arr[j + 1];
//                     arr[j + 1] = temp;
//                 }
//             }
//         }
//     }
    
//     int **arr = allocate2D(n, m);
    
//     srand(time(0));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             arr[i][j] = rand() % 100;
//         }
//     }
    
//     cout << "\nИсходный массив:" << endl;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cout << setw(3) << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
    
//     sortRowsBySum(arr, n, m);
    
//     cout << "\nПосле сортировки строк по сумме:" << endl;
//     for (int i = 0; i < n; i++) {
//         int sum = 0;
//         for (int j = 0; j < m; j++) {
//             cout << setw(3) << arr[i][j] << " ";
//             sum += arr[i][j];
//         }
//         cout << " | Сумма: " << sum << endl;
//     }
    
//     free2D(arr, n);
// }

// // ЗАДАЧА 6
//  {
//     int n = 3, m = 5;
//     int **arr = new int*[n];
//     for (int i = 0; i < n; i++) {
//         arr[i] = new int[m];
//     }
    
//     int counter = 1;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             arr[i][j] = counter++;
//         }
//     }
    
//     int sumElements(int **arr, int n, int m) {
//         int sum = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 sum += *(*(arr + i) + j);
//             }
//         }
//         return sum;
//     }
    
//     cout << "Сумма всех элементов: " << sumElements(arr, n, m) << endl;
    
//     for (int i = 0; i < n; i++) {
//         delete[] arr[i];
//     }
//     delete[] arr;
// }

// //  ЗАДАЧА 7:
//  {
//     const int wordCount = 7;
//     char **words = new char*[wordCount];
    
//     char *initialWords[] = {"banana", "apple", "grape", "cherry", "date", "fig", "elderberry"};
    
//     for (int i = 0; i < wordCount; i++) {
//         words[i] = new char[strlen(initialWords[i]) + 1];
//         strcpy(words[i], initialWords[i]);
//     }
    
//     void sortStrings(char **words, int n) {
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = 0; j < n - i - 1; j++) {
//                 if (strcmp(words[j], words[j + 1]) > 0) {
//                     char *temp = words[j];
//                     words[j] = words[j + 1];
//                     words[j + 1] = temp;
//                 }
//             }
//         }
//     }
    
//     sortStrings(words, wordCount);
    
//     for (int i = 0; i < wordCount; i++) {
//         cout << words[i] << endl;
//         delete[] words[i];
//     }
//     delete[] words;
// }

// //  ЗАДАЧА 8: 
//  {
//     int n = 5, m = 5, k = 3;
    
//     double** allocatePlate(int n, int m) {
//         double **plate = new double*[n];
//         for (int i = 0; i < n; i++) {
//             plate[i] = new double[m];
//         }
//         return plate;
//     }
    
//     void freePlate(double **plate, int n) {
//         for (int i = 0; i < n; i++) {
//             delete[] plate[i];
//         }
//         delete[] plate;
//     }
    
//     void updateTemperature(double **plate, int n, int m) {
//         double **newPlate = allocatePlate(n, m);
//         int centerX = n / 2;
//         int centerY = m / 2;
        
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (i == centerX && j == centerY) {
//                     newPlate[i][j] = 100.0;
//                 } else {
//                     double sum = 0;
//                     int count = 0;
                    
//                     if (i > 0) { sum += plate[i-1][j]; count++; }
//                     if (i < n-1) { sum += plate[i+1][j]; count++; }
//                     if (j > 0) { sum += plate[i][j-1]; count++; }
//                     if (j < m-1) { sum += plate[i][j+1]; count++; }
                    
//                     newPlate[i][j] = (count > 0) ? sum / count : plate[i][j];
//                 }
//             }
//         }
        
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 plate[i][j] = newPlate[i][j];
//             }
//         }
        
//         freePlate(newPlate, n);
//     }
    
//     double **plate = allocatePlate(n, m);
    
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             plate[i][j] = 20.0;
//         }
//     }
    
//     for (int iter = 0; iter < k; iter++) {
//         updateTemperature(plate, n, m);
//     }
    
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cout << fixed << setprecision(1) << setw(6) << plate[i][j];
//         }
//         cout << endl;
//     }
    
//     freePlate(plate, n);
// }

// //  ЗАДАЧА 9:
//  {
//     int n = 3, m = 4;
    
//     double** allocateWeights(int n, int m) {
//         double **weights = new double*[n];
//         for (int i = 0; i < n; i++) {
//             weights[i] = new double[m];
//         }
//         return weights;
//     }
    
//     void freeWeights(double **weights, int n) {
//         for (int i = 0; i < n; i++) {
//             delete[] weights[i];
//         }
//         delete[] weights;
//     }
    
//     double* forward(double **weights, double *inputs, int n, int m) {
//         double *outputs = new double[n];
//         for (int i = 0; i < n; i++) {
//             outputs[i] = 0.0;
//             for (int j = 0; j < m; j++) {
//                 outputs[i] += weights[i][j] * inputs[j];
//             }
//         }
//         return outputs;
//     }
    
//     void normalizeWeights(double **weights, int n, int m) {
//         for (int i = 0; i < n; i++) {
//             double sum = 0.0;
//             for (int j = 0; j < m; j++) {
//                 sum += fabs(weights[i][j]);
//             }
//             if (sum > 1.0) {
//                 for (int j = 0; j < m; j++) {
//                     weights[i][j] /= sum;
//                 }
//             }
//         }
//     }
    
//     double **weights = allocateWeights(n, m);
//     double *inputs = new double[m];
    
//     srand(time(0));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             weights[i][j] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
//         }
//     }
    
//     for (int j = 0; j < m; j++) {
//         inputs[j] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
//     }
    
//     normalizeWeights(weights, n, m);
    
//     double *outputs = forward(weights, inputs, n, m);
    
//     for (int i = 0; i < n; i++) {
//         cout << "Выход нейрона " << i << ": " << outputs[i] << endl;
//     }
    
//     delete[] outputs;
//     delete[] inputs;
//     freeWeights(weights, n);
// }

// //  ЗАДАЧА 10: {
//     int n, t;
//     cout << "Введите количество узлов и интервалов: ";
//     cin >> n >> t;
    
//     int **load = new int*[n];
//     for (int i = 0; i < n; i++) {
//         load[i] = new int[t];
//     }
    
//     cout << "Введите нагрузку для каждого узла по интервалам:" << endl;
//     for (int i = 0; i < n; i++) {
//         cout << "Узел " << i << ": ";
//         for (int j = 0; j < t; j++) {
//             cin >> load[i][j];
//         }
//     }
    
//     // Этап 1: 
//     double* averageLoadPerNode(int **load, int n, int t) {
//         double *avg = new double[n];
//         for (int i = 0; i < n; i++) {
//             avg[i] = 0.0;
//             for (int j = 0; j < t; j++) {
//                 avg[i] += *(*(load + i) + j);
//             }
//             avg[i] /= t;
//         }
//         return avg;
//     }
    
//     // Этап 2: 
//     void normalizeLoad(int **load, int n, int t) {
//         for (int j = 0; j < t; j++) {
//             for (int i = 0; i < n; i++) {
//                 if (*(*(load + i) + j) > 80) {
//                     int reduction = round(*(*(load + i) + j) * 0.1);
//                     *(*(load + i) + j) -= reduction;
//                     int perNode = round((double)reduction / (n - 1));
//                     for (int k = 0; k < n; k++) {
//                         if (k != i) {
//                             *(*(load + k) + j) += perNode;
//                         }
//                     }
//                 }
//             }
//         }
//     }
    
//     // Этап 3:
//     int findCriticalInterval(int **load, int n, int t) {
//         int maxSum = 0;
//         int critical = 0;
//         for (int j = 0; j < t; j++) {
//             int sum = 0;
//             for (int i = 0; i < n; i++) {
//                 sum += *(*(load + i) + j);
//             }
//             if (sum > maxSum) {
//                 maxSum = sum;
//                 critical = j;
//             }
//         }
//         return critical;
//     }
    
//     void printMatrix(int **load, int n, int t) {
//         for (int i = 0; i < n; i++) {
//             cout << "Узел " << i << ": ";
//             for (int j = 0; j < t; j++) {
//                 cout << setw(4) << *(*(load + i) + j);
//             }
//             cout << endl;
//         }
//     }
    
//     cout << "\nИсходная матрица нагрузок:" << endl;
//     printMatrix(load, n, t);
    
//     double *avg = averageLoadPerNode(load, n, t);
    
//     cout << "\nСредняя нагрузка на каждом узле:" << endl;
//     for (int i = 0; i < n; i++) {
//         cout << "Узел " << i << ": " << fixed << setprecision(1) << avg[i] << "%" << endl;
//     }
    
//     normalizeLoad(load, n, t);
    
//     cout << "\nМатрица после нормализации:" << endl;
//     printMatrix(load, n, t);
    
//     int critical = findCriticalInterval(load, n, t);
//     cout << "\nКритический интервал: " << critical << endl;
    
//     // Этап 5: 
//     delete[] avg;
//     for (int i = 0; i < n; i++) {
//         delete[] load[i];
//     }
//     delete[] load;
// }
