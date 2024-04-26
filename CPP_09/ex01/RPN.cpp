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

    numbers = other.numbers;
    notation = other.notation;
    return (*this);
}

RPN::~RPN() {}

void RPN::performOperation(char operand)
{
    int op1, op2;

    op2 = numbers.top();
    numbers.pop();
    op1 = numbers.top();
    numbers.pop();

    if (operand == '/' && op2 == 0)
        throw (DivisionByZeroException());

    switch (operand)
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

void RPN::calculate()
{
    std::istringstream iss(notation);
    std::string token;
    size_t count = 0;
    
    while (iss >> token)
    {
        if (token.size() != 1)
            throw (ErrorException());
        if (isdigit(token[0]))
            numbers.push(std::atoi(token.c_str()));
        else if (token.find_first_of("*/+-") != std::string::npos)
        {
            if (numbers.size() < 2)
                break ;
            performOperation(token[0]);
        }
        else
            throw (ErrorException());
        count++;
    }
    if (numbers.size() != 1 || count < 3)
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
