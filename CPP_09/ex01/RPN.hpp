#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <exception>

class RPN
{
    private:
        RPN();
        std::stack<int> numbers;

    public:
        RPN(const std::string &notation);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

    class WrongAgumentNumberException : public std::exception
    {
        public:
            const char *what(void) const throw();
    };

    class EmptyStringException : public std::exception
    {
        public:
            const char *what(void) const throw();
    };

    class WrongNotationFormatException : public std::exception
    {
        public:
            const char *what(void) const throw();
    };
};

#endif