// #include <iostream>
// #include <string>
// using namespace std;
// char shiftCharacter(char c, int shift) {
//     char base;
//     if (c >= 'A' && c <= 'Z') {
//         base = 'A';
//     } else if (c >= 'a' && c <= 'z') {
//         base = 'a';
//     } else {
//         return c;
//     }
//     return (c - base + shift) % 26 + base;
// }
// string caesarCipher(const string& text, int shift) {
//     string result;
//     for (char c : text) {
//         result += shiftCharacter(c, shift);
//     }
//     return result;
// }
// int main() {
//     setlocale(LC_ALL, "rus"); 
//     string text;
//     int shift;
//     cout << "Введите текст для шифрования: ";
//     getline(cin, text);
//     cout << "Введите сдвиг: ";
//     cin >> shift;
//     string encryptedText = caesarCipher(text, shift);
//     cout << "Зашифрованный текст: " << encryptedText << endl;
//     return 0;
// }