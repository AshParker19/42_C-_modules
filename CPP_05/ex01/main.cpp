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
        b1.signForm(f1);
    }
    // try
    // {
    //     Form f1("Doc1", 42, 42);
    //     std::cout << f1 << std::endl;
    //     Bureaucrat b1("Bob", 1);
    //     std::cout << b1 << std::endl;
    //     b1.signForm(f1);
    //     b1.signForm(f1);
    // }
    // try
    // {    
    //     Form f1("Doc1", 42, 42);
    //     std::cout << f1 << std::endl;
    //     Bureaucrat b1("Bob", 100);
    //     std::cout << b1 << std::endl;
    //     b1.signForm(f1);
    // }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
}