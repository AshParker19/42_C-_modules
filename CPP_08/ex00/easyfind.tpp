#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

template <typename T>
int easyfind(const T &container, int value)
{
    typename T::const_iterator it = container.begin();
    while (it != container.end())
    {
        if (*it == value)
            return (value);
        it++;
    }
    throw std::runtime_error("Value not found");
}

#endif
