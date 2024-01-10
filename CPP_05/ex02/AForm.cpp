#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : name(""), sign(false), signGrade(1), execGrade(1) {}

AForm::AForm(const std::string &newName, int newSignGrade, int newExecGrade) :
           name(newName), sign(false), signGrade(newSignGrade), execGrade(newExecGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : 
           name(other.name), signGrade(other.signGrade), execGrade(other.execGrade) 
{
    *this = other;
}

AForm &AForm::operator=(const AForm &other)
{
    if (this == &other)
        return (*this);
    this->sign = other.sign;
    return (*this);
}

AForm::~AForm() {}

const std::string &AForm::getName() const
{
    return (name); 
}

bool AForm::getSign() const
{
    return (sign);
}

int AForm::getSignGrade() const
{
    return (signGrade);
}

int AForm::getExecGrade() const
{
    return (execGrade);
}

std::ostream &operator<<(std::ostream& os, const AForm &f)
{
    os << "Form data: \n" << "     Name  --> " << f.getName() << "\n"
                          << "     Sign  --> " << f.getSign() << "\n"
                          << "     Grade --> " << f.getSignGrade() << "\n"
                          << "Exec Grade --> " << f.getExecGrade();
    return (os);
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is to high for");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is to low");
}

const char *AForm::FormAlreadySignedException::what() const throw()
{
    return ("Form is already signed");
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (sign == true)
        throw AForm::FormAlreadySignedException();
    if (b.getGrade() > signGrade)
        throw AForm::GradeTooLowException();
    sign = true;
}
