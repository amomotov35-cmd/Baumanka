// #include <iostream>
// #include <memory>

// int main() {
//     setlocale(LC_ALL, "rus");
//     auto ptr1 = std::make_unique<int>(42);
//     std::cout << "ptr1 до move: " << *ptr1 << std::endl;
    
//     auto ptr2 = std::move(ptr1);
    
//     if (ptr1 == nullptr) {
//         std::cout << "ptr1 теперь nullptr" << std::endl;
//     }
    
//     if (ptr2) {
//         std::cout << "ptr2 содержит: " << *ptr2 << std::endl;
//     }
    
//     return 0;
// }