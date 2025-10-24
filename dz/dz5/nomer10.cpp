// #include <iostream>
// #include <string>
// #include <sstream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// string invertWords(const string& input) {
//     stringstream ss(input);
//     string word;
//     vector<string> words;
//     while (ss >> word) {
//         reverse(word.begin(), word.end());
//         words.push_back(word);
//     }
//     string result;
//     for (size_t i = 0; i < words.size(); i++) {
//         result += words[i]; 
//         if (i < words.size() - 1) {
//             result += " "; 
//         }
//     }
//     return result;
// }
// int main() {
//     setlocale(LC_ALL, "rus");
//     string input;
//     cout << "Введите строку: ";
//     getline(cin, input); 
//     string invertedText = invertWords(input);
//     cout << "Инвертированные слова: " << invertedText << endl;
//     return 0;
// }