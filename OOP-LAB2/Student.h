#pragma once

class Student {
private:
    char name[100];
    float math, english, history;

public:
    void SetName(const char* n);
    const char* GetName() const;

    void SetMathGrade(float g);
    float GetMathGrade() const;

    void SetEnglishGrade(float g);
    float GetEnglishGrade() const;

    void SetHistoryGrade(float g);
    float GetHistoryGrade() const;

    float GetAverage() const;
};