#include "Sort.h"
#include <iostream>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>


Sort::Sort(int num_elements, int min_val, int max_val) {
    this->count = num_elements;
    this->elements = new int[count];
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        this->elements[i] = min_val + rand() % (max_val - min_val + 1);
    }
}


Sort::Sort(std::initializer_list<int> init_list) {
    this->count = init_list.size();
    this->elements = new int[count];
    int i = 0;
    for (int x : init_list) {
        this->elements[i++] = x;
    }
}


Sort::Sort(int* vector, int num_elements) {
    this->count = num_elements;
    this->elements = new int[count];
    for (int i = 0; i < count; i++) {
        this->elements[i] = vector[i];
    }
}


Sort::Sort(int count, ...) {
    this->count = count;
    this->elements = new int[count];
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        this->elements[i] = va_arg(args, int);
    }
    va_end(args);
}


Sort::Sort(const char* string_values) {
    int n = 0;
    if (string_values != nullptr) {
        n = 1;
        for (int i = 0; string_values[i] != '\0'; i++) {
            if (string_values[i] == ',') n++;
        }
    }
    this->count = n;
    this->elements = new int[count];

    int current_index = 0;
    int current_val = 0;
    for (int i = 0; ; i++) {
        if (string_values[i] >= '0' && string_values[i] <= '9') {
            current_val = current_val * 10 + (string_values[i] - '0');
        } else if (string_values[i] == ',' || string_values[i] == '\0') {
            this->elements[current_index++] = current_val;
            current_val = 0;
            if (string_values[i] == '\0') break;
        }
    }
}

Sort::~Sort() {
    delete[] elements;
}

void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < count; i++) {
        int key = elements[i];
        int j = i - 1;
        while (j >= 0 && (ascendent ? (elements[j] > key) : (elements[j] < key))) {
            elements[j + 1] = elements[j];
            j--;
        }
        elements[j + 1] = key;
    }
}

void Sort::BubbleSort(bool ascendent) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (ascendent ? (elements[j] > elements[j + 1]) : (elements[j] < elements[j + 1])) {
                int temp = elements[j];
                elements[j] = elements[j + 1];
                elements[j + 1] = temp;
            }
        }
    }
}

void Sort::QuickSort(bool ascendent) {
    QuickSortInternal(0, count - 1, ascendent);
}

void Sort::QuickSortInternal(int left, int right, bool ascendent) {
    if (left < right) {
        int p = Partition(left, right, ascendent);
        QuickSortInternal(left, p - 1, ascendent);
        QuickSortInternal(p + 1, right, ascendent);
    }
}

int Sort::Partition(int left, int right, bool ascendent) {
    int pivot = elements[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        bool condition = ascendent ? (elements[j] < pivot) : (elements[j] > pivot);
        if (condition) {
            i++;
            int temp = elements[i];
            elements[i] = elements[j];
            elements[j] = temp;
        }
    }
    int temp = elements[i + 1];
    elements[i + 1] = elements[right];
    elements[right] = temp;
    return i + 1;
}

void Sort::Print() {
    for (int i = 0; i < count; i++) {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
}

int Sort::GetElementsCount() {
    return count;
}

int Sort::GetElementFromIndex(int index) {
    if (index >= 0 && index < count) return elements[index];
    return -1;
}