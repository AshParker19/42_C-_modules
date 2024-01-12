#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;

    try 
    {
        AForm* rrf;
        Bureaucrat bob("bob", 42);
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        rrf->beSigned(bob); // we cant use signForm because it accpets const AForm, so we sign it within a form
        rrf->execute(bob);
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
