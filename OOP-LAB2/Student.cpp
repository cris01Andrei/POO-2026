#include "Student.h"

void Student::SetName(const char* n) {
    int i = 0;
    while (n[i] != '\0' && i < 99) {
        this->name[i] = n[i];
        i++;
    }
    this->name[i] = '\0';
}

const char* Student::GetName() const {
    return this->name;
}

void Student::SetMathGrade(float g) {
    if (g >= 1.0f && g <= 10.0f) this->math = g;
}

float Student::GetMathGrade() const {
    return this->math;
}

void Student::SetEnglishGrade(float g) {
    if (g >= 1.0f && g <= 10.0f) this->english = g;
}

float Student::GetEnglishGrade() const {
    return this->english;
}

void Student::SetHistoryGrade(float g) {
    if (g >= 1.0f && g <= 10.0f) this->history = g;
}

float Student::GetHistoryGrade() const {
    return this->history;
}

float Student::GetAverage() const {
    return (this->math + this->english + this->history) / 3.0f;
}