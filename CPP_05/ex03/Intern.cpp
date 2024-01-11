#include "Intern.hpp"

Inter::Inter() {}

Inter::Inter(const Inter &other)
{
    *this = other;
}

Inter &Inter::operator=(const Inter &other)
{
    return (*this);
}

Inter::~Inter() {}
