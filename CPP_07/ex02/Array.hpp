#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>
class Array
{
    private:
        T *elements;
        size_t size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        ~Array();
        T &operator[](size_t index);
        size_t size() const;
};

#include "Array.tpp"

#endif