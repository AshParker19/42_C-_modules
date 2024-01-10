#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include "Form.hpp"

class Bureaucrat
{
    private:
        const std::string	name;
        int					grade;
        Bureaucrat();

    public:
        Bureaucrat(const std::string &newName, int newGrade);

        const std::string &getName(void) const;
        int getGrade(void) const;
        void upGrade(void);
        void downGrade(void);
        void signForm(const Form &f);

        class GradeTooHighException : public std::exception
        {
            public: // throw() in a function declaration is an exception specification which makes sure we can't throw another exception from this function
                const char *what(void) const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat &b);

#endif