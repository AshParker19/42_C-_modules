#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        AForm();
        const std::string name;
        bool sign;
        const int signGrade;
        const int execGrade;

    public:
        AForm(const std::string &newName, int newSignGrade, int newExecGrade);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        ~AForm();

        const std::string &getName() const;
        bool getSign() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void beSigned(const Bureaucrat &b);
        virtual void execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException : public std::exception //TODO:move definition to .cpp  
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

std::ostream &operator<<(std::ostream& os, const AForm &b);

#endif