#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &newName, int newGrade) : name(newName)
{
    if (newGrade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (newGrade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        grade = newGrade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this == &other)
        return (*this);
    this->grade = other.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

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
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::downGrade(void)
{
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
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

void Bureaucrat::signForm(const Form &f)
{
    try
    {
        const_cast<Form &>(f).beSigned(*this);
        std::cout << name << " signed " << f.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << name << " couldn't sign " << f.getName()
                  << " because " << e.what() << std::endl;
    }
}
