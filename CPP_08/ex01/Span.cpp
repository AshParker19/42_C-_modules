#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : elements(N), maxSize(N), count(0) {}

Span::Span(const Span &other) : elements(other.elements) {}

Span &Span::operator=(const Span &other)
{
    if (this == &other)
        return (*this);
    elements = other.elements;
    return (*this);
}

Span::~Span() {}

void Span::addNumber(int newNum)
{
    if (count++ == maxSize)
        throw (NoSpaceForMoreNumbersException());
    
}

const char *Span::NoSpaceForMoreNumbersException::what() const throw()
{
    return ("No space for more numbers!");
}