#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string new_name) :
                          name(new_name),
                          hit_points(10),
                          energy_points(10),
                          attack_damage(0)

{
    std::cout << "ClapTrap " << GREEN << name << RESET << " is ready to fight!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << GREEN << name << RESET <<" did his best at this battle and now gone!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (energy_points > 0)
    {
        std::cout   << "ClapTrap " << BLUE << this->name << RESET <<  " aggressively attacking ClapTrap "
                    << PURPLE << target << RESET << " and causes " << RED << attack_damage
                    << RESET << " points of severe damage!" << std::endl;
        energy_points--;
    }
    else
        std::cout << YELLOW << name << RESET << " ran out of energy!" << std::endl;
    
}

// void ClapTrap::takeDamage(unsigned int amount)
// {

// }

// void ClapTrap::beRepaired(unsigned int amount)
// {

// }
