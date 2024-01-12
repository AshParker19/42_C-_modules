#include "Intern.hpp"

std::string Intern::formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};


Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (formConstructors[i](target));
        }
    }
    throw Intern::FormDoesNotExist();
}

AForm *createShrubberyCreationForm(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *createRobotomyRequestForm(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}

AForm *createPresidentialPardonForm(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}

AForm *(*Intern::formConstructors[3])(const std::string &target)
                                        = { &createShrubberyCreationForm,
                                            &createRobotomyRequestForm, 
                                            &createPresidentialPardonForm };
                                            
const char *Intern::FormDoesNotExist::what() const throw()
{
    return ("Form does not exist");
}
