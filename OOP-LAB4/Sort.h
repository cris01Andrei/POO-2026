#pragma once
#include <initializer_list>

class Sort
{
    int* elements;
    int count;

   
    void QuickSortInternal(int left, int right, bool ascendent);
    int Partition(int left, int right, bool ascendent);

public:
    Sort(int num_elements, int min_val, int max_val);
    Sort(std::initializer_list<int> init_list);
    Sort(int* vector, int num_elements);
    Sort(int count, ...);
    Sort(const char* string_values);

    
    ~Sort();

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};