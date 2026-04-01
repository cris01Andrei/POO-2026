#pragma once
#include <iostream>
#include <cstring>

class JsonValue {
public:
    virtual ~JsonValue() = 0;

    virtual void print(std::ostream& out, int indent = 0) const = 0;
    virtual unsigned count() const = 0;

    operator unsigned() const { return count(); }
};