#include "Sort.h"
#include <iostream>

int main() {
  
    Sort s1(5, 10, 50);
    std::cout << "Random s1: "; s1.Print();
    s1.BubbleSort(true);
    std::cout << "Sorted s1 (Asc): "; s1.Print();

   
    Sort s2({ 10, 5, 20, 1, 15 });
    std::cout << "List s2: "; s2.Print();
    s2.InsertSort(false);
    std::cout << "Sorted s2 (Desc): "; s2.Print();

    
    int v[] = { 4, 8, 2, 1 };
    Sort s3(v, 4);
    std::cout << "Vector s3: "; s3.Print();
    s3.QuickSort(true);
    std::cout << "Sorted s3 (Asc): "; s3.Print();

  
    Sort s4(4, 100, 200, 300, 50);
    std::cout << "Variadic s4: "; s4.Print();
    s4.BubbleSort(false);
    std::cout << "Sorted s4 (Desc): "; s4.Print();

   
    Sort s5("10,40,100,5,70");
    std::cout << "String s5: "; s5.Print();
    s5.QuickSort(true);
    std::cout << "Sorted s5 (Asc): "; s5.Print();

    std::cout << "Elements in s5: " << s5.GetElementsCount() << std::endl;
    std::cout << "Element at index 2 in s5: " << s5.GetElementFromIndex(2) << std::endl;

    return 0;
}