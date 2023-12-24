#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{
}

void    Zombie::announce(void)
{
    std::cout << "\033[32m" << name << "\033[0m: BraiiiiiiinnnzzzZ..." << std::endl; 
}

void Zombie::set_name(const std::string &name)
{
    this->name = name;
}

// Zombie::~Zombie()
// {
//     std::cout << "The horde of \033[32m" << name << "\033[0m has turned into ashes!" << std::endl;
// }
