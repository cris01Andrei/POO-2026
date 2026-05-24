#include <iostream>
#include "Array.h"

int MyCompare(const int& a, const int& b) {
    if (a == b) return 0;
    return (a > b) ? 1 : -1;
}

class IntComparator : public Compare {
public:
    int CompareElements(void* e1, void* e2) override {
        int val1 = *(static_cast<int*>(e1));
        int val2 = *(static_cast<int*>(e2));
        if (val1 == val2) return 0;
        return (val1 > val2) ? 1 : -1;
    }
};

int main() {
    Array<int> arr(5);

    try {
        arr += 40;
        arr += 10;
        arr += 30;
        arr += 20;
        arr.Insert(2, 50);
        
        std::cout << "Elemente: ";
        for (int i = 0; i < arr.GetSize(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";

        arr.Sort(MyCompare);
        std::cout << "Dupa sortare: ";
        for (auto it = arr.GetBeginIterator(); it != arr.GetEndIterator(); ++it) {
            std::cout << *(it.GetElement()) << " ";
        }
        std::cout << "\n";

    } catch (std::exception& e) {
        std::cout << "Exceptie prinsa: " << e.what() << "\n";
    }

    try {
        std::cout << arr[10] << "\n";
    } catch (std::exception& e) {
        std::cout << "Test Index Exception: " << e.what() << "\n";
    }

    try {
        arr += 100;
    } catch (std::exception& e) {
        std::cout << "Test Capacity Exception: " << e.what() << "\n";
    }

    return 0;
}
