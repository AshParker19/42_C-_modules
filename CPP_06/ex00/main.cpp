#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Invalid number of arguments" << std::endl;
        return (1);
    }
    ScalarConverter::convertMain(av[1]);
}