#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>
class Array
{
    private:
        T *elements;
        size_t sizeN;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        ~Array();
        T &operator[](int index);
        size_t size() const;

        class OutOfBoundException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
};

#include "Array.tpp"

#endif