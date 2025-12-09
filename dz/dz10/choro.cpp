// // Задача 1
// #include <iostream>
// #include <chrono>

// long long sumToN(int n) {
//     long long sum = 0;
//     for (int i = 1; i <= n; i++) {
//         sum += i;
//     }
//     return sum;
// }

// int main() {
//     auto start = std::chrono::high_resolution_clock::now();
//     long long result = sumToN(1000000);
//     auto end = std::chrono::high_resolution_clock::now();
//     auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
//     std::cout << "Время выполнения: " << duration.count() << " миллисекунд" << std::endl;
//     return 0;
// }

// // Задача 2
// #include <iostream>
// #include <chrono>
// #include <thread>

// int main() {
//     int seconds;
//     std::cout << "Введите количество секунд: ";
//     std::cin >> seconds;
    
//     for (int i = seconds; i > 0; i--) {
//         std::cout << "Осталось: " << i << " секунд";
//         if (i == 1) std::cout << "а";
//         std::cout << std::endl;
//         std::this_thread::sleep_for(std::chrono::seconds(1));
//     }
    
//     std::cout << "Время вышло!" << std::endl;
//     return 0;
// }

// // Задача 3
// #include <iostream>
// #include <chrono>

// int main() {
//     long long total_seconds;
//     std::cout << "Введите количество секунд: ";
//     std::cin >> total_seconds;
    
//     using namespace std::chrono;
//     auto total_duration = seconds(total_seconds);
    
//     auto hours = duration_cast<hours>(total_duration);
//     total_duration -= hours;
    
//     auto minutes = duration_cast<minutes>(total_duration);
//     total_duration -= minutes;
    
//     auto seconds_remaining = duration_cast<seconds>(total_duration);
    
//     std::cout << hours.count() << " час";
//     if (hours.count() != 1) std::cout << "ов";
//     std::cout << " ";
    
//     std::cout << minutes.count() << " минут";
//     if (minutes.count() != 1) std::cout << "а";
//     else std::cout << "у";
//     std::cout << " ";
    
//     std::cout << seconds_remaining.count() << " секунд";
//     if (seconds_remaining.count() == 1) std::cout << "а";
//     std::cout << std::endl;
    
//     return 0;
// }
// // Задача 4
// #include <iostream>
// #include <vector>
// #include <random>
// #include <chrono>
// #include <algorithm>

// // Bubble Sort
// void bubbleSort(std::vector<int>& arr) {
//     int n = arr.size();
//     for (int i = 0; i < n-1; i++) {
//         for (int j = 0; j < n-i-1; j++) {
//             if (arr[j] > arr[j+1]) {
//                 std::swap(arr[j], arr[j+1]);
//             }
//         }
//     }
// }

// // Insertion Sort
// void insertionSort(std::vector<int>& arr) {
//     int n = arr.size();
//     for (int i = 1; i < n; i++) {
//         int key = arr[i];
//         int j = i - 1;
//         while (j >= 0 && arr[j] > key) {
//             arr[j+1] = arr[j];
//             j--;
//         }
//         arr[j+1] = key;
//     }
// }

// // Merge Sort helper functions
// void merge(std::vector<int>& arr, int left, int mid, int right) {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;
    
//     std::vector<int> L(n1), R(n2);
    
//     for (int i = 0; i < n1; i++) L[i] = arr[left + i];
//     for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
//     int i = 0, j = 0, k = left;
//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         } else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }
    
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }
    
//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }

// void mergeSortHelper(std::vector<int>& arr, int left, int right) {
//     if (left < right) {
//         int mid = left + (right - left) / 2;
//         mergeSortHelper(arr, left, mid);
//         mergeSortHelper(arr, mid+1, right);
//         merge(arr, left, mid, right);
//     }
// }

// void mergeSort(std::vector<int>& arr) {
//     mergeSortHelper(arr, 0, arr.size()-1);
// }

// // Quick Sort helper functions
// int partition(std::vector<int>& arr, int low, int high) {
//     int pivot = arr[high];
//     int i = low - 1;
    
//     for (int j = low; j < high; j++) {
//         if (arr[j] < pivot) {
//             i++;
//             std::swap(arr[i], arr[j]);
//         }
//     }
//     std::swap(arr[i+1], arr[high]);
//     return i + 1;
// }

// void quickSortHelper(std::vector<int>& arr, int low, int high) {
//     if (low < high) {
//         int pi = partition(arr, low, high);
//         quickSortHelper(arr, low, pi-1);
//         quickSortHelper(arr, pi+1, high);
//     }
// }

// void quickSort(std::vector<int>& arr) {
//     quickSortHelper(arr, 0, arr.size()-1);
// }

// // Функция измерения времени выполнения
// template<typename Func>
// long long measureTime(Func sortFunction, std::vector<int> arr) {
//     auto start = std::chrono::high_resolution_clock::now();
//     sortFunction(arr);
//     auto end = std::chrono::high_resolution_clock::now();
//     return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
// }

// int main() {
//     const int SIZE = 10000;
    
//     // Задача 5
//     std::vector<int> original(SIZE);
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<> dis(1, 10000);
    
//     for (int i = 0; i < SIZE; i++) {
//         original[i] = dis(gen);
//     }
    
//     std::cout << "Сравнение алгоритмов сортировки (массив из " << SIZE << " элементов):\n";
//     std::cout << "==================================================\n";
    
//     // Bubble Sort
//     std::vector<int> arr1 = original;
//     long long time1 = measureTime(bubbleSort, arr1);
//     std::cout << "Пузырьковая сортировка: " << time1 << " мс\n";
    
//     // Insertion Sort
//     std::vector<int> arr2 = original;
//     long long time2 = measureTime(insertionSort, arr2);
//     std::cout << "Сортировка вставками:   " << time2 << " мс\n";
    
//     // Merge Sort
//     std::vector<int> arr3 = original;
//     long long time3 = measureTime(mergeSort, arr3);
//     std::cout << "Сортировка слиянием:    " << time3 << " мс\n";
    
//     // Quick Sort
//     std::vector<int> arr4 = original;
//     long long time4 = measureTime(quickSort, arr4);
//     std::cout << "Быстрая сортировка:     " << time4 << " мс\n";
    
//     // std::sort
//     std::vector<int> arr5 = original;
//     auto start = std::chrono::high_resolution_clock::now();
//     std::sort(arr5.begin(), arr5.end());
//     auto end = std::chrono::high_resolution_clock::now();
//     long long time5 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
//     std::cout << "std::sort:              " << time5 << " мс\n";
    
//     return 0;
// }