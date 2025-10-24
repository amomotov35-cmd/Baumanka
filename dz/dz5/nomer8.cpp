// #include <iostream>
// #include <string>
// using namespace std;
// string correctCase(const string& input) {
//     string result;
//     bool capitalizeNext = true; 
//     for (char c : input) {
//         if (capitalizeNext && isalpha(c)) {
//             result += toupper(c);
//             capitalizeNext = false; 
//         } else {
//             result += tolower(c); 
//         }
//         if (c == '.' || c == '!' || c == '?') {
//             capitalizeNext = true; 
//         }
//     }
//     return result;
// }
// int main() {
//     setlocale(LC_ALL, "rus"); 
//     string input;
//     cout << "Введите текст: ";
//     getline(cin, input); 
//     string correctedText = correctCase(input);
//     cout << "Скорректированный текст: " << correctedText << endl;
//     return 0;
// }