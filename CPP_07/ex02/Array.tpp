#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : elements(NULL), size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]), size(n) {}

template <typename T>
Array<T>::Array(const Array &other)
{

}

template <typename T>
Array &Array<T>::operator=(const Array &other) : size(other.size)
{
    if (this == &other)
        return (*this);
    Array *tmp = new T[size];
    delete []elements;
    for (size_t i = 0; i < size; i++)
    {
        tmp[i] = other;
    }
}

template <typename T>
Array<T>::~Array();
{
    
}

template <typename T>
T &Array<T>::operator[](size_t index);
{

}

template <typename T>
size_t Array<T>::size() const
{

}


#endif