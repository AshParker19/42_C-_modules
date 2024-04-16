#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <exception>
#include <cstdlib>

class RPN
{
    private:
        RPN();
        std::stack<int> numbers;
        std::string notation;

    public:
        RPN(const std::string &n);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        void calculate();
        void performOperation(char operand);
        int getResult();

    class WrongArgumentNumberException : public std::exception
    {
        public:
            const char *what(void) const throw();
    };

    class EmptyStringException : public std::exception
    {
        public:
            const char *what(void) const throw();
    };

    class ErrorException : public std::exception
    {
        public:
            const char *what(void) const throw();
    };

    class DivisionByZeroException : public std::exception
    {
        public:
            const char *what(void) const throw();
    };
    
};

#endif