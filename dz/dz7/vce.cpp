// // Задача 1
// #include <iostream>

// int myStrLen(const char* str) {
//     const char* p = str;
//     while (*p) p++;
//     return p - str;
// }

// int main() {
//     const char* test = "Hello";
//     std::cout << myStrLen(test) << std::endl;
//     return 0;
// }

// // Задача 2
// #include <iostream>

// void myStrCopy(char* dest, const char* src) {
//     while (*src) {
//         *dest = *src;
//         dest++;
//         src++;
//     }
//     *dest = '\0';
// }

// int main() {
//     char dest[20];
//     myStrCopy(dest, "Hello World");
//     std::cout << dest << std::endl;
//     return 0;
// }

// // Задача 3
// #include <iostream>

// void myStrCat(char* dest, const char* src) {
//     while (*dest) dest++;
//     while (*src) {
//         *dest = *src;
//         dest++;
//         src++;
//     }
//     *dest = '\0';
// }

// int main() {
//     char dest[50] = "Hello ";
//     myStrCat(dest, "World!");
//     std::cout << dest << std::endl;
//     return 0;
// }

// // Задача 4
// #include <iostream>

// int countChar(const char* str, char ch) {
//     int count = 0;
//     while (*str) {
//         if (*str == ch) count++;
//         str++;
//     }
//     return count;
// }

// int main() {
//     char str[100];
//     char ch;
//     std::cout << "Enter string: ";
//     std::cin.getline(str, 100);
//     std::cout << "Enter character: ";
//     std::cin >> ch;
//     std::cout << "Count: " << countChar(str, ch) << std::endl;
//     return 0;
// }

// // Задача 5
// #include <iostream>

// void replaceSpaces(char* str) {
//     while (*str) {
//         if (*str == ' ') *str = '_';
//         str++;
//     }
// }

// int main() {
//     char str[100];
//     std::cout << "Enter string: ";
//     std::cin.getline(str, 100);
//     replaceSpaces(str);
//     std::cout << "Result: " << str << std::endl;
//     return 0;
// }

// // Задача 6
// #include <iostream>
// #include <cstring>

// void reverse(char* str) {
//     char* start = str;
//     char* end = str + strlen(str) - 1;
//     while (start < end) {
//         char temp = *start;
//         *start = *end;
//         *end = temp;
//         start++;
//         end--;
//     }
// }

// int main() {
//     char str[100];
//     std::cout << "Enter string: ";
//     std::cin.getline(str, 100);
//     reverse(str);
//     std::cout << "Reversed: " << str << std::endl;
//     return 0;
// }

// // Задача 7
// #include <iostream>
// #include <cstring>

// bool isPalindrome(const char* str) {
//     const char* start = str;
//     const char* end = str + strlen(str) - 1;
//     while (start < end) {
//         if (*start != *end) return false;
//         start++;
//         end--;
//     }
//     return true;
// }

// int main() {
//     char str[100];
//     std::cout << "Enter string: ";
//     std::cin.getline(str, 100);
//     std::cout << (isPalindrome(str) ? "Palindrome" : "Not palindrome") << std::endl;
//     return 0;
// }

// // Задача 8
// #include <iostream>

// const char* findSubstring(const char* text, const char* word) {
//     const char* t = text;
//     while (*t) {
//         const char* t1 = t;
//         const char* w = word;
//         while (*t1 && *w && *t1 == *w) {
//             t1++;
//             w++;
//         }
//         if (!*w) return t;
//         t++;
//     }
//     return nullptr;
// }

// int main() {
//     const char* text = "Hello world!";
//     const char* word = "world";
//     const char* result = findSubstring(text, word);
//     if (result) std::cout << "Found at position: " << result - text << std::endl;
//     else std::cout << "Not found" << std::endl;
//     return 0;
// }

// // Задача 9
// #include <iostream>

// void removeSpaces(char* str) {
//     char* dst = str;
//     while (*str) {
//         if (*str != ' ') {
//             *dst = *str;
//             dst++;
//         }
//         str++;
//     }
//     *dst = '\0';
// }

// int main() {
//     char str[100];
//     std::cout << "Enter string: ";
//     std::cin.getline(str, 100);
//     removeSpaces(str);
//     std::cout << "Result: " << str << std::endl;
//     return 0;
// }

// // Задача 10
// #include <iostream>

// int myStrCmp(const char* s1, const char* s2) {
//     while (*s1 && *s2 && *s1 == *s2) {
//         s1++;
//         s2++;
//     }
//     return *s1 - *s2;
// }

// int main() {
//     const char* s1 = "abc";
//     const char* s2 = "abd";
//     std::cout << myStrCmp(s1, s2) << std::endl;
//     return 0;
// }

// // Задача 11
// #include <iostream>
// #include <vector>

// int main() {
//     std::vector<int> vec = {1, 2, 3, 4, 5};
//     int sum = 0;
//     int* p = &vec[0];
//     for (size_t i = 0; i < vec.size(); i++) {
//         sum += *(p + i);
//     }
//     std::cout << "Sum: " << sum << std::endl;
//     return 0;
// }

// // Задача 12
// #include <iostream>
// #include <vector>

// int main() {
//     std::vector<int> vec = {1, 2, 3, 4, 5};
//     int* p = vec.data();
//     for (size_t i = 0; i < vec.size(); i++) {
//         *(p + i) += 10;
//     }
//     for (int val : vec) std::cout << val << " ";
//     std::cout << std::endl;
//     return 0;
// }

// // Задача 13
// #include <iostream>

// void parseTelemetry(const char* data) {
//     const char* p = data;
//     while (*p) {
//         const char* name_start = p;
//         while (*p && *p != ':') p++;
//         if (!*p) break;
        
//         // Выводим имя
//         std::cout.write(name_start, p - name_start);
//         std::cout << ": ";
//         p++; 
//         const char* value_start = p;
//         while (*p && *p != ';') p++;
//         std::cout.write(value_start, p - value_start);
//         std::cout << std::endl;
        
//         if (*p == ';') p++;
//     }
// }

// int main() {
//     const char* data = "TEMP:24.5;PRESS:101.3;HUM:55.2";
//     parseTelemetry(data);
//     return 0;
// }

// // Задача 14
// #include <iostream>
// #include <vector>
// #include <cmath>

// double computeRMS(const std::vector<double>& signal) {
//     const double* p = signal.data();
//     double sum = 0.0;
//     size_t n = signal.size();
    
//     for (size_t i = 0; i < n; i++) {
//         sum += (*(p + i)) * (*(p + i));
//     }
    
//     return sqrt(sum / n);
// }

// int main() {
//     std::vector<double> signal = {2.0, 3.0, 1.0, 4.0, 3.0};
//     std::cout << "RMS value: " << computeRMS(signal) << std::endl;
//     return 0;
// }

// // Задача 15
// #include <iostream>
// #include <vector>
// #include <string>
// #include <cstdlib>

// struct Command {
//     std::string name;
//     int value;
// };

// void parseCommand(const char* input, std::vector<Command>& buffer) {
//     const char* p = input;
    
//     const char* name_start = p;
//     while (*p && *p != ' ') p++;
    
//     Command cmd;
//     cmd.name = std::string(name_start, p - name_start);
    
//     cmd.value = 0;
//     if (*p == ' ') {
//         p++;
//         cmd.value = atoi(p);
//     }
    
//     buffer.push_back(cmd);
// }

// int main() {
//     std::vector<Command> buffer;
//     parseCommand("FORWARD 10", buffer);
//     parseCommand("TURN 90", buffer);
//     parseCommand("STOP", buffer);
    
//     for (const auto& cmd : buffer) {
//         std::cout << "Command: " << cmd.name 
//                   << ", Value: " << cmd.value << std::endl;
//     }
    
//     return 0;
// }

// // Задача 16
// #include <iostream>
// #include <vector>

// void analyzePressure(const std::vector<double>& data, 
//                      double& minVal, double& maxVal, double& avgVal) {
//     const double* p = data.data();
//     size_t n = data.size();
    
//     if (n == 0) return;
    
//     minVal = *p;
//     maxVal = *p;
//     double sum = 0.0;
    
//     for (size_t i = 0; i < n; i++) {
//         double val = *(p + i);
//         if (val < minVal) minVal = val;
//         if (val > maxVal) maxVal = val;
//         sum += val;
//     }
    
//     avgVal = sum / n;
// }

// int main() {
//     std::vector<double> pressure = {101.3, 100.8, 101.9, 100.5, 102.0};
//     double minVal, maxVal, avgVal;
    
//     analyzePressure(pressure, minVal, maxVal, avgVal);
    
//     std::cout << "Min pressure: " << minVal << std::endl;
//     std::cout << "Max pressure: " << maxVal << std::endl;
//     std::cout << "Average pressure: " << avgVal << std::endl;
    
//     return 0;
// }