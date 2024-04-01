#include "RPN.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw (RPN::WrongArgumentNumberException());
        
        RPN rpn(av[1]);
        rpn.calculate();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}