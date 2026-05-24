#pragma once
#include <exception>

class IndexOutOfBoundsException : public std::exception {
    virtual const char* what() const throw() {
        return "Indexul este inafara domeniului!";
    }
};

class CapacityExceededException : public std::exception {
    virtual const char* what() const throw() {
        return "Capacitatea maxima a fost depasita!";
    }
};

class Compare {
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class Array;

template<class T>
class ArrayIterator {
private:
    int Current;
    T** ListRef;
public:
    ArrayIterator() {
        Current = 0;
        ListRef = nullptr;
    }
    
    ArrayIterator(int index, T** list) {
        Current = index;
        ListRef = list;
    }

    ArrayIterator& operator++() {
        Current++;
        return *this;
    }

    ArrayIterator& operator--() {
        Current--;
        return *this;
    }

    bool operator==(const ArrayIterator<T>& other) {
        return (Current == other.Current && ListRef == other.ListRef);
    }

    bool operator!=(const ArrayIterator<T>& other) {
        return !(*this == other);
    }

    T* GetElement() {
        if (ListRef == nullptr) return nullptr;
        return ListRef[Current];
    }
};

template<class T>
class Array {
private:
    T** List;
    int Capacity;
    int Size;

public:
    Array() {
        List = nullptr;
        Capacity = 0;
        Size = 0;
    }

    ~Array() {
        if (List != nullptr) {
            for (int i = 0; i < Size; i++) {
                delete List[i];
            }
            delete[] List;
        }
    }

    Array(int capacity) {
        if (capacity < 0) throw IndexOutOfBoundsException();
        Capacity = capacity;
        Size = 0;
        List = new T*[Capacity];
    }

    Array(const Array<T>& otherArray) {
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T*[Capacity];
        for (int i = 0; i < Size; i++) {
            List[i] = new T(*(otherArray.List[i]));
        }
    }

    T& operator[](int index) {
        if (index < 0 || index >= Size) {
            throw IndexOutOfBoundsException();
        }
        return *(List[index]);
    }

    const Array<T>& operator+=(const T& newElem) {
        if (Size >= Capacity) {
            throw CapacityExceededException();
        }
        List[Size] = new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem) {
        if (index < 0 || index > Size) {
            throw IndexOutOfBoundsException();
        }
        if (Size >= Capacity) {
            throw CapacityExceededException();
        }
        for (int i = Size; i > index; i--) {
            List[i] = List[i - 1];
        }
        List[index] = new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray) {
        if (index < 0 || index > Size) {
            throw IndexOutOfBoundsException();
        }
        if (Size + otherArray.Size > Capacity) {
            throw CapacityExceededException();
        }
        for (int i = Size - 1; i >= index; i--) {
            List[i + otherArray.Size] = List[i];
        }
        for (int i = 0; i < otherArray.Size; i++) {
            List[index + i] = new T(*(otherArray.List[i]));
        }
        Size += otherArray.Size;
        return *this;
    }

    const Array<T>& Delete(int index) {
        if (index < 0 || index >= Size) {
            throw IndexOutOfBoundsException();
        }
        delete List[index];
        for (int i = index; i < Size - 1; i++) {
            List[i] = List
