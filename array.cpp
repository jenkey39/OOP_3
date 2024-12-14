#include "array.h"

// Конструкторы
Array::Array() : roots(nullptr), size(0) {}
Array::Array(size_t s) : size(s) {
    roots = new Complex[size];
}

// Деструктор
Array::~Array() {
    delete[] roots;
}

// Методы
void Array::setRoot(size_t index, const Complex& root) {
    if (index < size) {
        roots[index] = root;
    }
}

const Complex& Array::getRoot(size_t index) const {
    return roots[index];
}

size_t Array::getSize() const {
    return size;
}

void Array::resize(size_t newSize) {
    delete[] roots;
    size = newSize;
    roots = new Complex[size];
}

// Ввод и вывод
std::ostream& operator<<(std::ostream& out, const Array& arr) {
    for (size_t i = 0; i < arr.size; ++i) {
        out << arr.roots[i] << " ";
    }
    return out;
}

std::istream& operator>>(std::istream& in, Array& arr) {
    for (size_t i = 0; i < arr.size; ++i) {
        in >> arr.roots[i];
    }
    return in;
}
