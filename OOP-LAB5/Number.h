#pragma once

class Number
{
    char* value;
    int base;
    int digitsCount;

    
    long long ToDecimal() const;
    void FromDecimal(long long dec, int newBase);
    int CharToVal(char c) const;
    char ValToChar(int v) const;

    
    int StringLen(const char* s) const;
    void StringCopy(char* dest, const char* src) const;

public:
    Number(const char* value, int base);
    Number(int value); 
    ~Number();

  
    Number(const Number& other);
    Number(Number&& other) noexcept;
    Number& operator=(Number&& other) noexcept;
    Number& operator=(const char* val);
    Number& operator=(int val);

    
    bool operator>(const Number& n) const;
    bool operator<(const Number& n) const;
    bool operator>=(const Number& n) const;
    bool operator<=(const Number& n) const;
    bool operator==(const Number& n) const;

    
    char operator[](int index) const;
    Number& operator--();    
    Number operator--(int); 
    Number& operator+=(const Number& n);

    
    friend Number operator+(const Number& n1, const Number& n2);
    friend Number operator-(const Number& n1, const Number& n2);

    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;
};