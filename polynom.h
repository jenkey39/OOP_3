#ifndef POLYNOM_H
#define POLYNOM_H

#include "array.h"

class Polynom {
private:
    Complex an;  // Коэффициент при старшей степени
    Array roots;  // Массив корней
    Complex* coefficients;  // Массив коэффициентов
    size_t degree;  // Степень полинома

    void calculateCoefficients();  // Метод для вычисления коэффициентов
public:
    Polynom();
    Polynom(const Complex& an, const Array& roots);
    ~Polynom();

    void setAn(const Complex& newAn);
    void setRoot(size_t index, const Complex& root);
    Complex calculateAt(const Complex& x) const;
    void print(bool form1 = true) const;  // Вывод полинома в форме 1 или 2
    size_t getDegree() const;  // Метод для получения степени полинома
};

#endif // POLYNOM_H
