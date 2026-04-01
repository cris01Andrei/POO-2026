#include "JsonValue.h"
#include <fstream>

using namespace std;

// ---------------- Base destructor ----------------
JsonValue::~JsonValue() {}

// ---------------- NullValue ----------------
class NullValue : public JsonValue {
public:
    void print(ostream& out, int indent = 0) const override {
        out << "null";
    }
    unsigned count() const override { return 1; }
};

// ---------------- NumberValue ----------------
class NumberValue : public JsonValue {
    double value;
public:
    NumberValue(double v) : value(v) {}

    void print(ostream& out, int indent = 0) const override {
        out << value;
    }
    unsigned count() const override { return 1; }
};

// ---------------- BoolValue ----------------
class BoolValue : public JsonValue {
    bool value;
public:
    BoolValue(bool v) : value(v) {}

    void print(ostream& out, int indent = 0) const override {
        out << (value ? "true" : "false");
    }
    unsigned count() const override { return 1; }
};

// ---------------- StringValue ----------------
class StringValue : public JsonValue {
    char value[256];
public:
    StringValue(const char* v) {
        strncpy(value, v, 255);
        value[255] = '\0';
    }

    void print(ostream& out, int indent = 0) const override {
        out << "\"" << value << "\"";
    }
    unsigned count() const override { return 1; }
};

// ---------------- ArrayValue ----------------
class ArrayValue : public JsonValue {
    JsonValue* values[16];
    int size;

public:
    ArrayValue() : size(0) {}

    ~ArrayValue() {
        for (int i = 0; i < size; i++)
            delete values[i];
    }

    void add(JsonValue* v) {
        if (size < 16)
            values[size++] = v;
    }

    void print(ostream& out, int indent = 0) const override {
        out << "[";
        for (int i = 0; i < size; i++) {
            values[i]->print(out, indent);
            if (i != size - 1) out << ", ";
        }
        out << "]";
    }

    unsigned count() const override {
        unsigned total = 1;
        for (int i = 0; i < size; i++)
            total += values[i]->count();
        return total;
    }
};

// ---------------- ObjectValue ----------------
class ObjectValue : public JsonValue {
    struct Pair {
        char name[256];
        JsonValue* value;
    };

    Pair values[16];
    int size;

public:
    ObjectValue() : size(0) {}

    ~ObjectValue() {
        for (int i = 0; i < size; i++)
            delete values[i].value;
    }

    void add(const char* name, JsonValue* v) {
        if (size < 16) {
            strncpy(values[size].name, name, 255);
            values[size].name[255] = '\0';
            values[size].value = v;
            size++;
        }
    }

    void print(ostream& out, int indent = 0) const override {
        out << "{";
        for (int i = 0; i < size; i++) {
            out << "\"" << values[i].name << "\": ";
            values[i].value->print(out, indent);
            if (i != size - 1) out << ", ";
        }
        out << "}";
    }

    unsigned count() const override {
        unsigned total = 1;
        for (int i = 0; i < size; i++)
            total += values[i].value->count();
        return total;
    }
};