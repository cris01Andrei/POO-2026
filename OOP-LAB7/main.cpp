#include <iostream>
using namespace std;


constexpr float operator"" _Kelvin(long double k)
{
    return (float)(k - 273.15);
}


constexpr float operator"" _Fahrenheit(long double f)
{
    return (float)((f - 32.0) * 5.0 / 9.0);
}



template <typename T>
class Tree {
public:
    struct Node {
        T value;
        Node** children;
        int childCount;
        int capacity;

        Node(T val) : value(val), childCount(0), capacity(2) {
            children = new Node*[capacity];
        }

        ~Node() {
            for (int i = 0; i < childCount; i++)
                delete children[i];
            delete[] children;
        }

        void addChild(Node* child) {
            if (childCount == capacity) {
                capacity *= 2;
                Node** newChildren = new Node*[capacity];
                for (int i = 0; i < childCount; i++)
                    newChildren[i] = children[i];
                delete[] children;
                children = newChildren;
            }
            children[childCount++] = child;
        }
    };

private:
    Node* root;

public:
    Tree() : root(nullptr) {}
    ~Tree() { delete root; }

    
    Node* add_node(T value, Node* parent = nullptr) {
        Node* newNode = new Node(value);

        if (parent == nullptr) {
            root = newNode;
        } else {
            parent->addChild(newNode);
        }
        return newNode;
    }

    
    Node* get_node(Node* parent = nullptr) {
        if (parent == nullptr)
            return root;
        return parent;
    }

  
    void delete_node(Node* node) {
        if (node == root) {
            delete root;
            root = nullptr;
        } else {
            
            delete node;
        }
    }

    
    Node* find(bool (*cmp)(const T&, const T&), const T& value, Node* start = nullptr) {
        if (start == nullptr)
            start = root;

        if (cmp(start->value, value))
            return start;

        for (int i = 0; i < start->childCount; i++) {
            Node* res = find(cmp, value, start->children[i]);
            if (res) return res;
        }
        return nullptr;
    }

   
    void insert(Node* parent, T value, int index) {
        if (!parent) return;

        if (parent->childCount == parent->capacity) {
            parent->capacity *= 2;
            Node** newChildren = new Node*[parent->capacity];
            for (int i = 0; i < parent->childCount; i++)
                newChildren[i] = parent->children[i];
            delete[] parent->children;
            parent->children = newChildren;
        }

        for (int i = parent->childCount; i > index; i--)
            parent->children[i] = parent->children[i - 1];

        parent->children[index] = new Node(value);
        parent->childCount++;
    }

    
    void sort(Node* node, bool (*cmp)(const T&, const T&) = nullptr) {
        if (!node) return;

        for (int i = 0; i < node->childCount - 1; i++)
            for (int j = i + 1; j < node->childCount; j++) {
                bool condition;
                if (cmp)
                    condition = cmp(node->children[j]->value, node->children[i]->value);
                else
                    condition = node->children[j]->value < node->children[i]->value;

                if (condition) {
                    Node* tmp = node->children[i];
                    node->children[i] = node->children[j];
                    node->children[j] = tmp;
                }
            }
    }

   
    int count(Node* node = nullptr) {
        if (node == nullptr)
            node = root;

        if (!node) return 0;

        int total = node->childCount;
        for (int i = 0; i < node->childCount; i++)
            total += count(node->children[i]);

        return total;
    }
};



bool cmp_int(const int& a, const int& b) {
    return a == b;
}

int main() {

    
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    cout << "300K in Celsius = " << a << endl;
    cout << "120F in Celsius = " << b << endl;

    
    Tree<int> t;

    auto root = t.add_node(10);
    auto n1 = t.add_node(5, root);
    auto n2 = t.add_node(20, root);

    t.add_node(3, n1);
    t.add_node(7, n1);

    t.insert(root, 15, 1);

    cout << "Total nodes (excluding root): " << t.count() << endl;

    auto found = t.find(cmp_int, 7);
    if (found)
        cout << "Found node with value: " << found->value << endl;

    t.sort(root);

    return 0;
}