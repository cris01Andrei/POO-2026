#pragma once

#include <ostream>
#include <cmath>

class Complex {
  private:
    double real_data;
    double imag_data;

  public:
    Complex();
    Complex(double real, double imag);

    bool is_real() const;

    double real() const;
    double imag() const;
    double abs() const;
    Complex conjugate() const;

    // op() behaves as a setter and allows chaining
    Complex& operator()(double real, double imag);

    // Increment/Decrement (Real part only according to main.cpp logic)
    Complex& operator++();       // prefix
    Complex operator++(int);     // postfix
    Complex& operator--();       // prefix
    Complex operator--(int);     // postfix
};

// Binary Operators: Addition
Complex operator+(const Complex& l, const Complex& r);
Complex operator+(const Complex& l, double r);
Complex operator+(double l, const Complex& r);

// Binary Operators: Subtraction
Complex operator-(const Complex& l, const Complex& r);
Complex operator-(const Complex& l, double r);
Complex operator-(double l, const Complex& r);

// Binary Operators: Multiplication
Complex operator*(const Complex& l, const Complex& r);
Complex operator*(const Complex& l, double r);
Complex operator*(double l, const Complex& r);

// Unary Operator
Complex operator-(const Complex& obj);

// Relational Operators
bool operator==(const Complex& l, const Complex& r);
bool operator!=(const Complex& l, const Complex& r);

// Stream Operator
std::ostream& operator<<(std::ostream& out, const Complex& complex);