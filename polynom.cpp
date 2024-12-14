#include "polynom.h"

// Конструкторы
Polynom::Polynom() : an(0, 0), coefficients(nullptr), degree(0) {}
Polynom::Polynom(const Complex& anValue, const Array& rootsArray)
    : an(anValue), roots(rootsArray), degree(rootsArray.getSize()) {
    coefficients = new Complex[degree + 1];
    calculateCoefficients();
}

// Деструктор
Polynom::~Polynom() {
    delete[] coefficients;
}

// Методы
void Polynom::calculateCoefficients() {
    for (size_t i = 0; i <= degree; ++i) {
        coefficients[i] = Complex(0, 0);
    }

    coefficients[degree] = an;
    for (size_t i = 0; i < degree; ++i) {
        for (size_t j = degree - i; j > 0; --j) {
            coefficients[j - 1] = coefficients[j - 1] - coefficients[j] * roots.getRoot(i);
        }
    }
}

void Polynom::setAn(const Complex& newAn) {
    an = newAn;
    calculateCoefficients();
}

void Polynom::setRoot(size_t index, const Complex& root) {
    if (index < degree) {  // Добавлена проверка индекса
        roots.setRoot(index, root);
        calculateCoefficients();
    }
}

Complex Polynom::calculateAt(const Complex& x) const {
    Complex result = coefficients[degree];
    for (int i = degree - 1; i >= 0; --i) {
        result = result * x + coefficients[i];
    }
    return result;
}

void Polynom::print(bool form1) const {
    if (form1) {
        std::cout << "Полином в форме (1): p(x) = ";
        for (size_t i = 0; i <= degree; ++i) {
            std::cout << coefficients[i] << "x^" << degree - i << " ";
        }
    } else {
        std::cout << "Полином в форме (2): p(x) = " << an;
        for (size_t i = 0; i < degree; ++i) {
            std::cout << " * (x - " << roots.getRoot(i) << ")";
        }
    }
    std::cout << "\n";
}

size_t Polynom::getDegree() const {
    return degree;
}
