#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const std::string &n) : notation(n)
{
    if (notation.empty())
        throw (EmptyStringException());
}

RPN::RPN(const RPN &other) 
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this == &other)
        return (*this);

    this->numbers = other.numbers;
    this->notation = other.notation;
    return (*this);
}

RPN::~RPN() {}

void RPN::calculate()
{
    std::istringstream iss(notation);
    std::string token;
    int op1, op2;
    
    while (iss >> token)
    {
        if (token.size() != 1)
            throw (ErrorException());
        if (isdigit(token[0]))
            numbers.push(std::atoi(token.c_str()));
        else if (token.find_first_of("*/+-") != std::string::npos)
        {
            if(numbers.size() != 2)
                throw (ErrorException());

            op2 = numbers.top();
            numbers.pop();
            op1 = numbers.top();
            numbers.pop();

            if (token[0] == '/' && op2 == 0)
                throw (DivisionByZeroException());

            switch (token[0])
            {
                case '*':
                    numbers.push(op1 * op2);
                    break ;
                
                case '/':
                    numbers.push(op1 / op2);
                    break ;
                
                case '+':
                    numbers.push(op1 + op2);
                    break ;
                
                case '-':
                    numbers.push(op1 - op2);
            }
        }
        else
            throw (ErrorException());
    }

    if (numbers.size() != 1)
        throw ErrorException();
}

int RPN::getResult()
{
    return (numbers.top());
}

const char *RPN::WrongArgumentNumberException::what(void) const throw()
{
    return ("Wrong number of arguments.");
}

const char *RPN::EmptyStringException::what(void) const throw()
{
    return ("Empty input string.");
}

const char *RPN::ErrorException::what(void) const throw()
{
    return ("Error");
}

const char *RPN::DivisionByZeroException::what(void) const throw()
{
    return ("Division by zero");
}