#include "complex.h"

Complex::Complex() : Complex(0, 0) {}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag_data == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return std::sqrt(real_data * real_data + imag_data * imag_data);
}

Complex Complex::conjugate() const {
    return { real_data, -imag_data };
}

Complex& Complex::operator()(double real, double imag) {
    this->real_data = real;
    this->imag_data = imag;
    return *this;
}


Complex& Complex::operator++() {
    this->real_data++;
    return *this;
}


Complex Complex::operator++(int) {
    Complex temp = *this;
    ++(*this);
    return temp;
}


Complex& Complex::operator--() {
    this->real_data--;
    return *this;
}


Complex Complex::operator--(int) {
    Complex temp = *this;
    --(*this);
    return temp;
}


Complex operator+(const Complex& l, const Complex& r) {
    return { l.real() + r.real(), l.imag() + r.imag() };
}
Complex operator+(const Complex& l, double r) {
    return { l.real() + r, l.imag() };
}
Complex operator+(double l, const Complex& r) {
    return { l + r.real(), r.imag() };
}


Complex operator-(const Complex& l, const Complex& r) {
    return { l.real() - r.real(), l.imag() - r.imag() };
}
Complex operator-(const Complex& l, double r) {
    return { l.real() - r, l.imag() };
}
Complex operator-(double l, const Complex& r) {
    return { l - r.real(), -r.imag() };
}


Complex operator*(const Complex& l, const Complex& r) {
    return { l.real() * r.real() - l.imag() * r.imag(),
             l.real() * r.imag() + l.imag() * r.real() };
}
Complex operator*(const Complex& l, double r) {
    return { l.real() * r, l.imag() * r };
}
Complex operator*(double l, const Complex& r) {
    return { l * r.real(), l * r.imag() };
}


Complex operator-(const Complex& obj) {
    return { -obj.real(), -obj.imag() };
}


bool operator==(const Complex& l, const Complex& r) {
    return l.real() == r.real() && l.imag() == r.imag();
}

bool operator!=(const Complex& l, const Complex& r) {
    return !(l == r);
}


std::ostream& operator<<(std::ostream& out, const Complex& c) {
    if (c.real() == 0 && c.imag() == 0) {
        out << "0";
        return out;
    }

    if (c.real() != 0) {
        out << c.real();
        if (c.imag() > 0) {
            out << " + " << c.imag() << "i";
        } else if (c.imag() < 0) {
            out << " - " << -c.imag() << "i";
        }
    } else {
        out << c.imag() << "i";
    }

    return out;
}