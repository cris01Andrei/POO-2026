#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "JsonValue.h"

using namespace std;


class NullValue;
class NumberValue;
class BoolValue;
class StringValue;
class ArrayValue;
class ObjectValue;

int main(int argc, char** argv) {

    auto array_numbers = new ArrayValue();
    array_numbers->add(new NumberValue(5));
    array_numbers->add(new NumberValue(10));
    array_numbers->add(new NumberValue(15));

    auto array_strings = new ArrayValue();
    array_strings->add(new StringValue("abc"));
    array_strings->add(new StringValue("def"));
    array_strings->add(new StringValue("ghi"));

    auto subobject = new ObjectValue();
    subobject->add("email", new StringValue("t@gmail.com"));
    subobject->add("name", new StringValue("T"));
    subobject->add("online", new BoolValue(true));

    auto object = new ObjectValue();
    object->add("n", new NullValue());
    object->add("array_numbers", array_numbers);
    object->add("array_strings", array_strings);
    object->add("info", subobject);

    cout << "Top node has " << (unsigned)*object << " subnodes\n";

    // BONUS 3: output control
    if (argc > 1) {
        ofstream fout(argv[1]);
        if (fout)
            object->print(fout);
    } else {
        object->print(cout);
    }

    delete object; // BONUS 2: no leaks

    return 0;
}