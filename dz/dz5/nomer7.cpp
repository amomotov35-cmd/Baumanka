// #include <iostream>
// #include <string>
// using namespace std;
// string rleCompress(const string& input) {
//     string result;
//     int count = 1; 
//     for (size_t i = 1; i <= input.length(); i++) {
//         if (i < input.length() && input[i] == input[i - 1]) {
//             count++;
//         } else {
//             result += input[i - 1];
//             result += to_string(count);
//             count = 1;
//         }
//     }
//     return result;
// }
// int main() {
//     setlocale(LC_ALL, "rus"); 
//     string input;
//     cout << "Введите строку для сжатия: ";
//     cin >> input;
//     string compressed = rleCompress(input);
//     cout << "Сжатая строка: " << compressed << endl;
//     return 0;
// }