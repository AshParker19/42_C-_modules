#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
    private:
        Form();
        const std::string name;
        bool sign;
        const int signGrade;
        const int execGrade;

    public:
        Form(const std::string &newName, int newSignGrade, int newExecGrade);
        const std::string &getName() const;
        bool getSign() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void beSigned(const Bureaucrat &b);

        Bureaucrat::GradeTooHighException;
};

std::ostream &operator<<(std::ostream& os, const Form &b);

#endif