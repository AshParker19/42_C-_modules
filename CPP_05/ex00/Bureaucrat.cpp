#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &newName, int newGrade) : name(newName)
{
    // try ()
}

const std::string &Bureaucrat::getName(void)
{
    return (name);
}

int Bureaucrat::getGrade(void)
{
    return (grade);
}

void Bureaucrat::upGrade(void)
{
    // try
}

void Bureaucrat::downGrade(void)
{
    // try
}


std::ostream &operator<<(std::ostream& os, const Bureaucrat &obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
    return (os)
}
