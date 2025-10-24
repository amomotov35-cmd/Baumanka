// #include <iostream>
// #include <string>
// #include <unordered_set>
// using namespace std;
// void findUniqueSubstrings(const string& str, int k) {
//     int n = str.length();
//     if (k > n) {
//         cout << "Подстрока длиной " << k << " не может быть извлечена из строки длиной " << n << "." << endl;
//         return;
//     }
//     for (int i = 0; i <= n - k; i++) {
//         string substring = str.substr(i, k);
//         unordered_set<char> charSet;
//         bool hasDuplicates = false;

//         for (char c : substring) {
//             if (charSet.find(c) != charSet.end()) {
//                 hasDuplicates = true;
//                 break; 
//             }
//             charSet.insert(c);
//         }
//         if (!hasDuplicates) {
//             cout << substring << endl;
//         }
//     }
// }
// int main() {
//     setlocale(LC_ALL, "rus");
//     string str;
//     int k;
//     cout << "Введите строку: ";
//     getline(cin, str);
//     cout << "Введите длину подстроки (k): ";
//     cin >> k;
//     findUniqueSubstrings(str, k);
//     return 0;
// }