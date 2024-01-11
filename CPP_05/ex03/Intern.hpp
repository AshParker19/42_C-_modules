#ifndef INTERT_HPP
#define INTERT_HPP

#include <string>
#include "AForm.hpp"

class Inter
{
    public:
        Inter();
        Inter(const Inter &other);
        Inter &operator=(const Inter &other);
        ~Inter();
        AForm *makeForm(std::string formName, std::string target);
};

#endif