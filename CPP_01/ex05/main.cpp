#include <iostream>
#include <string>
#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;

    if (ac != 2)
    {
        std::cout << "[ Unacceptable amount of complaints too handle ]" << std::endl;
        return (1);
    }
    harl.complain(av[1]);
}