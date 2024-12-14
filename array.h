#ifndef ARRAY_H
#define ARRAY_H

#include "complex.h"
#include <iostream>

class Array {
private:
    Complex* roots;
    size_t size;
public:
    Array();
    Array(size_t size);
    ~Array();

    void setRoot(size_t index, const Complex& root);
    const Complex& getRoot(size_t index) const;
    size_t getSize() const;
    void resize(size_t newSize);

    // Ввод и вывод массива
    friend std::ostream& operator<<(std::ostream& out, const Array& arr);
    friend std::istream& operator>>(std::istream& in, Array& arr);
};

#endif // ARRAY_H
