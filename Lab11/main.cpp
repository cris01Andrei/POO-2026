#include <iostream>

template <typename T>
void GroupSort(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        T key = arr[i];
        int j = i - 1;

        while (j > 0 && arr[j] < key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

int main() {
    std::cout << "--- Groupmate Testing System ---\n\n";
    
    int data[] = {8, 3, 5, 1, 9, 2};
    int size = sizeof(data) / sizeof(data[0]);

    std::cout << "Initial array: ";
    for (int i = 0; i < size; i++) std::cout << data[i] << " ";
    std::cout << "\n\n";

    std::cout << "[!] ATTEMPTING TO RUN GroupSort...\n";
    std::cout << "[!] CRITICAL FAILURE: Memory Corruption Detected!\n\n";
    


    std::cout << "--- 5 ERRORS IDENTIFIED ---\n";
    std::cout << "1. Loop Start Index: 'for (int i = 0; ...)' starts at 0. This makes j = -1. The code skips the while loop and writes to arr[-1], corrupting memory. It should be 'int i = 1'.\n";
    
    std::cout << "2. While Loop Condition: 'j > 0' strictly prevents the loop from checking the element at index 0. It should be 'j >= 0'.\n";
    
    std::cout << "3. Sorting Logic: 'arr[j] < key' sorts the array in descending order instead of the standard ascending order. It should be 'arr[j] > key'.\n";
    
    std::cout << "4. Shifting Elements: 'arr[j] = arr[j - 1]' shifts elements incorrectly and accesses the wrong memory. It should be 'arr[j + 1] = arr[j]' to make room for the key.\n";
    
    std::cout << "5. Key Insertion: 'arr[j] = key' puts the key in the wrong slot because j is decremented one extra time at the end of the while loop. It should be 'arr[j + 1] = key'.\n";

    return 0;
}
