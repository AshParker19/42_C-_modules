#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <exception>
#include <cstdlib>
#include <ctime>

class Span
{
    private:
        Span();
        std::vector<int> elements;
        unsigned int count;
        int spans[2];
        bool spansFound;

    public:
        Span(unsigned int newSize);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int newNum);
        void addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
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