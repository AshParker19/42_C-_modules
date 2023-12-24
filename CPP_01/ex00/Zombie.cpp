#include <iostream>
#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << "\033[32m" << name << "\033[0m: BraiiiiiiinnnzzzZ..." << std::endl; 
}

Zombie::~Zombie()
{
    std::cout << "Our zombie \033[32m" << name << "\033[0m has turned into ashes!" << std::endl;
}
