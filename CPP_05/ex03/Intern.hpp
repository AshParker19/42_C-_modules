#ifndef INTERT_HPP
#define INTERT_HPP

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        static AForm *(*formConstructors[3])(const std::string &target);
        static std::string formNames[3];

    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();
        
        AForm *makeForm(const std::string &formName, const std::string &target);

        class FormDoesNotExist : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
};

#endif