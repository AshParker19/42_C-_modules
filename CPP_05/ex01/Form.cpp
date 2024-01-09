#include "Form.hpp"

Form::Form() : signGrade(0), execGrade(0) {}

Form::Form(const std::string &newName, int newSignGrade, int newExecGrade) :
           name(newName), sign(false), signGrade(newSignGrade), execGrade(newExecGrade)
{ }

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
    os << "Ford data: \n" << "     Name  --> " << f.getName()
                          << "     Sign  --> " << f.getSign()
                          << "     Grade --> " << f.getSignGrade()
                          << "Exec Grade --> " << f.getExecGrade()
                          << std::endl;
    return (os);
}