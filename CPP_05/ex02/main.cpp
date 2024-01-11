#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    PresidentialPardonForm form("bixo");
    Bureaucrat bob("Bob", 42);

    bob.signForm(form);
    bob.executeForm(form);
}
