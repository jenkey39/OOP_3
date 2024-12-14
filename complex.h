#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    double real;
    double imag;
public:
    Complex();
    Complex(double real, double imag);

    // Методы для получения и изменения компонентов
    double getReal() const;
    double getImag() const;
    void setReal(double real);
    void setImag(double imag);

    // Перегрузка операторов для работы с комплексными числами
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    // Ввод и вывод
    friend std::ostream& operator<<(std::ostream& out, const Complex& c);
    friend std::istream& operator>>(std::istream& in, Complex& c);
};

#endif // COMPLEX_H
