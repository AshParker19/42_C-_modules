#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include "AForm.hpp"

class Bureaucrat
{
    private:
        const std::string	name;
        int					grade;
        Bureaucrat();

    public:
        Bureaucrat(const std::string &newName, int newGrade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        const std::string &getName(void) const;
        int getGrade(void) const;
        void upGrade(void);
        void downGrade(void);
        void signForm(const AForm &f);

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
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat &b);

#endif