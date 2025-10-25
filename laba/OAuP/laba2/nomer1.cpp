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
   
}
    
