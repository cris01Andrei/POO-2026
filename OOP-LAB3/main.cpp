#include <iostream>
#include "Math.h"

int main() {
    std::cout << "Add(2, 3): " << Math::Add(2, 3) << std::endl;
    std::cout << "Add(2, 3, 4): " << Math::Add(2, 3, 4) << std::endl;
    std::cout << "Add(2.5, 3.5): " << Math::Add(2.5, 3.5) << std::endl;
    std::cout << "Variadic Add(4, 1, 2, 3, 4): " << Math::Add(4, 1, 2, 3, 4) << std::endl;
    
    char* s = Math::Add("Hello ", "World");
    if (s) {
        std::cout << "String Add: " << s << std::endl;
        delete[] s;
    }
    return 0;
}