#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;




constexpr float operator"" _Kelvin(long double k) {
    return (float)(k - 273.15);
}


constexpr float operator"" _Fahrenheit(long double f) {
    return (float)((f - 32.0) * 5.0 / 9.0);
}



template <typename T>
class Vector {
private:
    T* data;
    int size;
    int capacity;

    void resize(int newCap) {
        T* newData = new T[newCap];
        for (int i = 0; i < size; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCap;
    }

public:
    
    Vector() {
        size = 0;
        capacity = 2;
        data = new T[capacity];
    }

  
    ~Vector() {
        delete[] data;
    }

   
    Vector(const Vector& other) {
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

   
    Vector(Vector&& other) {
        data = other.data;
        size = other.size;
        capacity = other.capacity;

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

   
    T& operator[](int index) {
        return data[index];
    }

    
    void insert(int index, const T& element) {
        if (index < 0 || index > size) return;

        if (size == capacity)
            resize(capacity * 2);

        for (int i = size; i > index; i--)
            data[i] = data[i - 1];

        data[index] = element;
        size++;
    }

   
    void remove(int index) {
        if (index < 0 || index >= size) return;

        for (int i = index; i < size - 1; i++)
            data[i] = data[i + 1];

        size--;
    }

  
    void sort(int (*cmp)(T, T)) {
        for (int i = 0; i < size - 1; i++)
            for (int j = i + 1; j < size; j++)
                if (cmp(data[i], data[j]) > 0) {
                    T temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
    }

    
    void sort() {
        for (int i = 0; i < size - 1; i++)
            for (int j = i + 1; j < size; j++)
                if (data[i] > data[j]) {
                    T temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
    }

  
    void print() {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};



int compare_ints(int x, int y) {
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}



int main() {

    
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    cout << "300K = " << a << " Celsius\n";
    cout << "120F = " << b << " Celsius\n";

    
    Vector<int> v;

    v.insert(0, 10);
    v.insert(1, 5);
    v.insert(2, 20);

    Vector<int> w = v; // copy constructor

    v.remove(0);
    v.sort(compare_ints);

    printf("%d\n", w[0]); // should print 10

    v.print(); // sorted: 5 20

    return 0;
}