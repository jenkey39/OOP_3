#include "complex.h"

// Конструкторы
Complex::Complex() : real(0), imag(0) {}
Complex::Complex(double r, double i) : real(r), imag(i) {}

// Методы доступа
double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }
void Complex::setReal(double r) { real = r; }
void Complex::setImag(double i) { imag = i; }

// Операторы
Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
}

Complex Complex::operator/(const Complex& other) const {
    double denom = other.real * other.real + other.imag * other.imag;
    return Complex((real * other.real + imag * other.imag) / denom, (imag * other.real - real * other.imag) / denom);
}

// Ввод и вывод
std::ostream& operator<<(std::ostream& out, const Complex& c) {
    out << "(" << c.real << ", " << c.imag << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Complex& c) {
    std::cout << "Введите действительную часть: ";
    in >> c.real;
    std::cout << "Введите мнимую часть: ";
    in >> c.imag;
    return in;
}
