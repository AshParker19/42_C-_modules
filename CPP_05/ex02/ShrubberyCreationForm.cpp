#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &newTarget) :
    AForm("ShrubberyCreationForm", 145, 137),
    target(newTarget) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
    AForm(other),
    target(other.target) 
{
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this == &other)
        return (*this);
    AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string const &ShrubberyCreationForm::getTarget(void) const
{
    return (this->target);
}

