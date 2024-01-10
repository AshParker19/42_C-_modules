#include "Bureaucrat.hpp"

int main(int ac, char **av)
{
    if (ac != 3 && ac != 4)
        return (1);

    std::string name = av[1];
    int grade = atoi(av[2]);

    try
    {
        Bureaucrat b1(name, grade);
        std::cout << b1 << "\n" << std::endl;

        if (ac == 4) // if we have 4th argument means we can increment or decrement the initial value, if the value is even, incrementation will ocuur and the oposite
        {
            int counter = atoi(av[3]);
            if (counter % 2 == 0)
            {
                for (int i = 0; i < counter; i++)
                    b1.upGrade();
            }
            else
            {
                for (int i = 0; i < counter; i++)
                    b1.downGrade();
            }
            std::cout << b1 << std::endl;
        }
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (2);
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (3);
    }
}