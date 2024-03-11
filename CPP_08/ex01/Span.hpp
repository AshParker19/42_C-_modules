#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
    private:
        Span();
        std::vector<int> elements;
        unsigned int maxSize;
        int count;

    public:
        Span(unsigned int newSize);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int newNum);

        class NoSpaceForMoreNumbersException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
};

#endif