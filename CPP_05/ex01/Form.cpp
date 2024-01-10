#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : name(""), sign(false), signGrade(1), execGrade(1) {}

Form::Form(const std::string &newName, int newSignGrade, int newExecGrade) :
           name(newName), sign(false), signGrade(newSignGrade), execGrade(newExecGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : 
           name(other.name), signGrade(other.signGrade), execGrade(other.execGrade) 
{
    *this = other;
}

Form &Form::operator=(const Form &other)
{
    if (this == &other)
        return (*this);
    this->sign = other.sign;
    return (*this);
}

Form::~Form() {}

const std::string &Form::getName() const
{
    return (name); 
}

bool Form::getSign() const
{
    return (sign);
}

int Form::getSignGrade() const
{
    return (signGrade);
}

int Form::getExecGrade() const
{
    return (execGrade);
}

std::ostream &operator<<(std::ostream& os, const Form &f)
{
    os << "Form data: \n" << "     Name  --> " << f.getName() << "\n"
                          << "     Sign  --> " << f.getSign() << "\n"
                          << "     Grade --> " << f.getSignGrade() << "\n"
                          << "Exec Grade --> " << f.getExecGrade();
    return (os);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is to high for");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is to low");
}

const char *Form::FormAlreadySignedException::what() const throw()
{
    return ("Form is already signed");
}

void Form::beSigned(const Bureaucrat &b)
{
    if (sign == true)
        throw Form::FormAlreadySignedException();
    if (b.getGrade() > signGrade)
        throw Form::GradeTooLowException();
    sign = true;
}
