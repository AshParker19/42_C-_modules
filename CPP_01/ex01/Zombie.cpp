#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {}

void    Zombie::announce(void)
{
    std::cout << "\033[32m" << name << "\033[0m: BraiiiiiiinnnzzzZ..." << std::endl; 
}

void Zombie::set_name(const std::string &name)
{
    this->name = name;
}


