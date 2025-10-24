// #include <iostream> 
// #include <vector> 
// #include <algorithm>

// int main() {
//     setlocale(LC_ALL, "rus");
//     std::vector<int> v(10);
//     for (int i = 0; i < 10; ++i) {
//         v[i] = i + 1;
//     }
//     std::for_each(v.begin(), v.end(), [](int &v) {
//         v *= 2;
//         });
//     std::cout << "Умноженные на 2 числа: ";
//     std::for_each(v.begin(), v.end(), [](int v) { 
//         std::cout << v << " ";
//     });
//     std::cout << std::endl;

//     return 0;
// }
