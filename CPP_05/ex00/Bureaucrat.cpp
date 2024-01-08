#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &newName, int newGrade) : name(newName)
{
    try
    {
        if (newGrade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (newGrade > 150)
            throw Bureaucrat::GradeTooLowException();
        else
            grade = newGrade;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
}

const std::string &Bureaucrat::getName(void) const
{
    return (name);
}

int Bureaucrat::getGrade(void) const
{
    return (grade);
}

void Bureaucrat::upGrade(void)
{
    try
    {
        if (grade - 1 < 1)
            throw Bureaucrat::GradeTooHighException();
        grade--;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void Bureaucrat::downGrade(void)
{
    try
    {
        if (grade + 1 > 150)
            throw Bureaucrat::GradeTooLowException();
        grade++;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
    return (os);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is to hight");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is to low");
}
