#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack &);
        MutantStack &operator=(const MutantStack &);
        ~MutantStack();

        typedef typename std::stack<T>::container_type::iterator iterator;
};

#include "MutantStack.tpp"

#endif