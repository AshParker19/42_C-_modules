#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &newTarget) :
    AForm("RobotomyRequestForm", 72, 45),
    target(newTarget) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
    AForm(other),
    target(other.target) 
{
    *this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this == &other)
        return (*this);
    AForm::operator=(other);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string const &RobotomyRequestForm::getTarget(void) const
{
    return (this->target);
}
