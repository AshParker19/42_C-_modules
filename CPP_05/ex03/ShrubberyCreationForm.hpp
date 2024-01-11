#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string target;
        ShrubberyCreationForm();
    
    public:
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();

        std::string const &getTarget(void) const;
        void execute(Bureaucrat const &executor) const;

        class CouldNotOpenFileException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
};

#endif