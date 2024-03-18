#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &) {}

template <typename T>
MutantStack &MutantStack<T>::operator=(const MutantStack &) 
{
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}

template <typename T>
iterator MutantStack<T>::end()
{
    return (this->c.end());
}

template <typename T>
const_iterator MutantStack<T>::begin() const
{
    return (this->c.begin());
}

template <typename T>
const_iterator MutantStack<T>::end() const
{
    return (this->c.end());
}


#endif