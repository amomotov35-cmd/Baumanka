// #include <iostream>
// #include <memory>

// int main() {
//     setlocale(LC_ALL, "rus");
//     auto ptr1 = std::make_shared<int>(100);
//     std::cout << "После создания ptr1: use_count = " << ptr1.use_count() << std::endl;
    
//     auto ptr2 = ptr1;
//     std::cout << "После создания ptr2: use_count = " << ptr1.use_count() << std::endl;
    
//     auto ptr3 = ptr2;
//     std::cout << "После создания ptr3: use_count = " << ptr1.use_count() << std::endl;
    
//     {
//         auto ptr4 = ptr3;
//         std::cout << "Во вложенном блоке: use_count = " << ptr1.use_count() << std::endl;
//     }
    
//     std::cout << "После выхода из блока: use_count = " << ptr1.use_count() << std::endl;
    
//     return 0;
// }