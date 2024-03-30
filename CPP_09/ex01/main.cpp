#include "RPN.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw (RPN::WrongAgumentNumberException());
        
        RPN rpn(av[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}