#pragma once

template <typename K, typename V>
class Map {
private:
    struct Entry {
        K key;
        V value;
    };

    Entry* entries;
    int size;
    int capacity;

    void Resize() {
        capacity = (capacity == 0) ? 4 : capacity * 2;
        Entry* newEntries = new Entry[capacity];
        for (int i = 0; i < size; i++) {
            newEntries[i] = entries[i];
        }
        delete[] entries;
        entries = newEntries;
    }

public:
    Map() {
        size = 0;
        capacity = 4;
        entries = new Entry[capacity];
    }

    ~Map() {
        delete[] entries;
    }

  
    Map(const Map& other) {
        size = other.size;
        capacity = other.capacity;
        entries = new Entry[capacity];
        for (int i = 0; i < size; i++) {
            entries[i] = other.entries[i];
        }
    }

    Map& operator=(const Map& other) {
        if (this != &other) {
            delete[] entries;
            size = other.size;
            capacity = other.capacity;
            entries = new Entry[capacity];
            for (int i = 0; i < size; i++) {
                entries[i] = other.entries[i];
            }
        }
        return *this;
    }

    
    void Set(const K& key, const V& value) {
        for (int i = 0; i < size; i++) {
            if (entries[i].key == key) {
                entries[i].value = value;
                return;
            }
        }
        if (size >= capacity) {
            Resize();
        }
        entries[size].key = key;
        entries[size].value = value;
        size++;
    }


    bool Get(const K& key, V& value) {
        for (int i = 0; i < size; i++) {
            if (entries[i].key == key) {
                value = entries[i].value;
                return true;
            }
        }
        return false;
    }

    
    V& operator[](const K& key) {
        for (int i = 0; i < size; i++) {
            if (entries[i].key == key) {
                return entries[i].value;
            }
        }
        if (size >= capacity) {
            Resize();
        }
        entries[size].key = key;
        entries[size].value = V(); 
        size++;
        return entries[size - 1].value;
    }

  
    int Count() const {
        return size;
    }

  
    void Clear() {
        size = 0;
    }

 
    bool Delete(const K& key) {
        int indexToRemove = -1;
        for (int i = 0; i < size; i++) {
            if (entries[i].key == key) {
                indexToRemove = i;
                break;
            }
        }
        if (indexToRemove == -1) return false;

      
        for (int i = indexToRemove; i < size - 1; i++) {
            entries[i] = entries[i + 1];
        }
        size--;
        return true;
    }

   
    bool Includes(const Map<K, V>& otherMap) const {
        for (int i = 0; i < otherMap.size; i++) {
            bool found = false;
            for (int j = 0; j < this->size; j++) {
                if (this->entries[j].key == otherMap.entries[i].key) {
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }

 
    struct IterationProxy {
        K key;
        V value;
        int index;
    };

    class Iterator {
    private:
        const Map<K, V>& mapRef;
        int currentIndex;

    public:
        Iterator(const Map<K, V>& map, int index) : mapRef(map), currentIndex(index) {}

        bool operator!=(const Iterator& other) const {
            return currentIndex != other.currentIndex;
        }

        void operator++() {
            currentIndex++;
        }

       
        IterationProxy operator*() const {
            return { mapRef.entries[currentIndex].key, mapRef.entries[currentIndex].value, currentIndex };
        }
    };

    Iterator begin() const {
        return Iterator(*this, 0);
    }

    Iterator end() const {
        return Iterator(*this, size);
    }
};
