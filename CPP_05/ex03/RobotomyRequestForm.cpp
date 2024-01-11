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

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    this->canExecute(executor);
    srand(std::time(0));
    if (rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "The robotomy of " << target << " failed" << std::endl;
}
