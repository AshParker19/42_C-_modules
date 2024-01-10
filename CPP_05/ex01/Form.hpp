#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;
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

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };

        class FormAlreadySignedException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
};

std::ostream &operator<<(std::ostream& os, const Form &b);

#endif