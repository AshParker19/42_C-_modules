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

#endif