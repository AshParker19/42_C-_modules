#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : elements(N), count(0), spansFound(false) {}

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
    if (count >= elements.size())
        throw (NoSpaceForMoreNumbersException());
    elements[count++] = newNum;
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    for (std::vector<int>::iterator it = start; it != end; it++)
    {
        if (count >= elements.size())
            throw (NoSpaceForMoreNumbersException());
        elements[count++] = *it;
    }
}

void Span::findSpans()
{
    if (count != elements.size())
        throw (VectorIsNotPopulatedException());
    if (spansFound == true)
        return ;

    int smallestSpan = std::numeric_limits<int>::max();
    int currentSpan;

    std::sort(elements.begin(), elements.end());

    for (size_t i = 1; i < elements.size(); i++)
    {
        currentSpan = elements[i] - elements[i - 1];
        if (currentSpan < smallestSpan)
            smallestSpan = currentSpan;
    }

    spans[0] = smallestSpan;
    spans[1] = elements.back() - elements.front();
    spansFound = true;
}

int Span::shortestSpan()
{
    if (elements.empty() || elements.size() < 2)
        throw (NotEnoughNumbersException());

    findSpans();
    return (spans[0]);  
}

int Span::longestSpan()
{
    if (elements.empty() || elements.size() < 2)
        throw (NotEnoughNumbersException());

    findSpans();
    return (spans[1]);
}

const char *Span::NoSpaceForMoreNumbersException::what() const throw()
{
    return ("No space for more numbers!");
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
    return ("Not enough elements were provided to find a span!");
}

const char *Span::VectorIsNotPopulatedException::what() const throw()
{
    return ("Vector is not populated with enough numbers!");
}