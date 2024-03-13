#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <exception>

class Span
{
    private:
        Span();
        std::vector<int> elements;
        unsigned int count;
        int spans[2];

    public:
        Span(unsigned int newSize);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int newNum);
        int shortestSpan();
        int longestSpan();
        void findSpans();

        class NoSpaceForMoreNumbersException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };

        class NotEnoughNumbersException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };

        class VectorIsNotPopulatedException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
};

#endif