#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//vulgo quondam literatim ana syllabatim quondam ibidem singillatim sine passim
int main() {
    setlocale(LC_ALL, "rus");
    string s, sr;
    vector<string> Ve;
    cout << "Введите строку из 10 слов на латинице:";
    getline(cin, s);
    s = s + " ";
    int m = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] != ' ') {
            sr = sr + s[i];
        }
        else if ((s[i] == ' ') && (s[i + 1] != ' ')) {
            Ve.push_back(sr);
            sr = "";
        }
    }
    Ve.push_back(sr);
    // 1 chast
    /*
     for (int i = 0; i < Ve.size(); i++) {
        cout << Ve[i] << " ";
    }
    for (int i = 0; i < Ve.size(); i++) {
        if (Ve[i][0] == 'a') {
           m += 1;
        }
    }
    cout << "Кол-во слов начинающихся на букву a:" << m << endl;
    */
   // 2 chast
   /*
    int min = Ve.empty() ? 0 : Ve[0].length();
    for (int i = 1; i < Ve.size(); i++) {
        if (Ve[i].length() < min) {
            min = Ve[i].length();
        }
    }
    cout << "2. Длина самого короткого слова: " << min << endl;
    */
   // 3 chast
   /*if (!Ve.empty()) {
        const char* lastWord = Ve.back().c_str();
        int count = 0;
        while (*lastWord != '\0') {
            if (*lastWord == 'a' || *lastWord == 'A') {
                count++;
            }
            lastWord++; // Перемещение указателя
        }
        cout << "3. Букв 'a' в последнем: " << count << endl;
    }
    */
   // 4 chast
   /*
   string lowerStr = s;
    for (int i = 0; i < lowerStr.length(); i++) {
        lowerStr[i] = tolower(lowerStr[i]);
    }
    cout << "4. Строка в нижнем регистре: " << lowerStr << endl;
   */
   // 5 chast
   /*
   int sameEnds = 0;
    for (int i = 0; i < Ve.size(); i++) {
        if (!Ve[i].empty()) {
            string word = Ve[i];
            if (tolower(word[0]) == tolower(word[word.length() - 1])) {
                sameEnds++;
            }
        }
    }
    cout << "5. Слов с одинаковыми первым и последним символами: " << sameEnds << endl;
   */
  // 6 chast
  /*
  if (Ve.size() >= 2) {
        string shortestCommon;
        int minLength = 1000; // Большое число
        
        // Перебираем все пары слов
        for (int i = 0; i < Ve.size(); i++) {
            for (int j = i + 1; j < Ve.size(); j++) {
                string word1 = Ve[i];
                string word2 = Ve[j];
                
                // Ищем общие подстроки
                for (int start = 0; start < word1.length(); start++) {
                    for (int end = start; end < word1.length(); end++) {
                        string substring = word1.substr(start, end - start + 1);
                        if (substring.length() > 0 && word2.find(substring) != string::npos) {
                            if (substring.length() < minLength) {
                                minLength = substring.length();
                                shortestCommon = substring;
                            }
                        }
                    }
                }
            }
        }
        
        if (!shortestCommon.empty()) {
            cout << "6. Самая короткая общая подстрока: \"" << shortestCommon << "\" (длина: " << minLength << ")" << endl;
        } else {
            cout << "6. Общих подстрок не найдено" << endl;
        }
    } else {
        cout << "6. Недостаточно слов для поиска общей подстроки" << endl;
    }
  */

   return 0;
}
    
