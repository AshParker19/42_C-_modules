#ifndef BUROCRAT_HPP
#define BUROCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
    private:
        const std::string	name;
        int					grade;
        Bureaucrat();

    public:
        Bureaucrat(const std::string &newName, int newGrade);

        const std::string &getName(void);
        int getGrade(void);
        void upGrade(void);
        void downGrade(void);

        class GradeTooHighException : public std::exception
        {

        };

        class GradeTooLowException : public std::exception
        {

        };
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat &obj);

#endif