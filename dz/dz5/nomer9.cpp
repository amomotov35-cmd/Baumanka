// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;
// string longestCommonSubstring(const string& str1, const string& str2) {
//     int len1 = str1.length();
//     int len2 = str2.length();
//         vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
//     int maxLength = 0;
//     int endingIndex = 0; 
//     for (int i = 1; i <= len1; i++) {
//         for (int j = 1; j <= len2; j++) {
//             if (str1[i - 1] == str2[j - 1]) {
//                 dp[i][j] = dp[i - 1][j - 1] + 1;
//                 if (dp[i][j] > maxLength) {
//                     maxLength = dp[i][j];
//                     endingIndex = i;
//                 }
//             } else {
//                 dp[i][j] = 0;
//             }
//         }
//     }
//     return str1.substr(endingIndex - maxLength, maxLength);
// }
// int main() {
//     setlocale(LC_ALL, "rus");
//     string str1, str2;
//     cout << "Введите первую строку: ";
//     getline(cin, str1);
//     cout << "Введите вторую строку: ";
//     getline(cin, str2);
//     string result = longestCommonSubstring(str1, str2);
//     cout << "Наибольшая общая подстрока: \"" << result << "\"" << endl;
//     return 0;
// }