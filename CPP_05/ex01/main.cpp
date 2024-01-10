#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form f1("Doc1", 42, 42);
        std::cout << f1 << std::endl;
        Bureaucrat b1("Bob", 1);
        std::cout << b1 << std::endl;
        // f1.beSigned(b1);
        b1.signForm(f1);
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {   
        std::cerr << "Error: " << e.what() << std::endl;
        return (2);
    }
    catch (const Form::GradeTooHighException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (3);
    }
    catch (const Form::GradeTooLowException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (4);
    }
    catch (const Form::FormAlreadySignedException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (5);
    }
}