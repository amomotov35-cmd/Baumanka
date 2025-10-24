// #include <iostream> 
// #include <cstring> 
// #include <cctype> 
// bool isPalindrome(const char* str) {
// 	int length = strlen(str); 
// 	int left = 0;
// 	int right = length - 1;
// 	while (left < right) {
// 		while (left < right && isspace(str[left])) {
// 			left++;
// 		}
// 		while (left < right && isspace(str[right])) {
// 			right--;
// 		}
// 		if (tolower(str[left]) != tolower(str[right])) {
// 			return false; 
// 		}
// 		left++;
// 		right--;
// 	}
// 	return true; 
// }
// int main() {
// 	setlocale(LC_ALL, "rus");
// 	char str[100]; 
// 	std::cout << "Введите строку: "; 
// 	std::cin.getline(str, 100); 
// 	if (isPalindrome(str)) { 
// 		std::cout << "Это палиндром." << std::endl; 
// 	}
// 	else {
// 		std::cout << "Это не палиндром." << std::endl; 
// 	}
// 	return 0; 
// }