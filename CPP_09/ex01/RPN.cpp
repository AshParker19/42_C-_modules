#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const std::string &notation)
{
    if (notation.empty())
        throw (EmptyStringException());

    std::istringstream iss(notation);
    std::string token;
    
    while (iss >> token)
    {
        if (token.size() != 1)
            throw (WrongNotationFormatException());
        if (isdigit(token[0]))
            numbers.push(std::atoi(token.c_str()));
        
    }
}

RPN::RPN(const RPN &other) 
{
    (void)other;
}

RPN &RPN::operator=(const RPN &other)
{
    (void)other;
    return (*this);
}

RPN::~RPN() {}

const char *RPN::WrongAgumentNumberException::what(void) const throw()
{
    return ("Wrong number of arguments.");
}

const char *RPN::EmptyStringException::what(void) const throw()
{
    return ("Empty input string.");
}

const char *RPN::WrongNotationFormatException::what(void) const throw()
{
    return ("Wrong Notation Format");
}