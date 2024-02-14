#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Invalid number of arguments" << std::endl;
        return (1);
    }
    ScalarConverter::convertToChar(av[1]);
    ScalarConverter::convertToInt(av[1]);
    ScalarConverter::convertToFloat(av[1]);
    ScalarConverter::convertToDouble(av[1]);
}