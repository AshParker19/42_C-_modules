#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &newTarget) :
    AForm("PresidentialPardonForm", 25, 5),
    target(newTarget) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
    AForm(other),
    target(other.target) 
{
    *this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this == &other)
        return (*this);
    AForm::operator=(other);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string const &PresidentialPardonForm::getTarget(void) const
{
    return (this->target);
}

