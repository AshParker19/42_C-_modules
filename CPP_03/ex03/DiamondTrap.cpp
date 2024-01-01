#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {}

DiamondTrap::DiamondTrap(const std::string &new_name) :
                         ClapTrap(new_name + "_clap_name"),
                         ScavTrap(new_name),
                         FragTrap(new_name),
                         name(new_name)
{
    std::cout << "DiamontTrap " << GREEN << name << RESET << " has gained all the wisdom and ready for combat!" << std::endl;
}

// DiamondTrap::DiamondTrap(const DiamondTrap &other) : 
//                          ClapTrap(other),
//                          ScavTrap(other),
//                          FragTrap(other)
// {
//         *this = other;
// }

// DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
// {
//     if (this != &other) // TODO:add this protection
//     {
//         this->attack_damage = other.
//     }
//     ClapTrap::operator=(other);
//     ScavTrap::operator=(other);
//     FragTrap::operator=(other);
    
//     return (*this);
// }

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamontTrap " << GREEN << name << RESET << " finished his stuff here and goes away!" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout   << "I am " << BLUE << name << RESET << " DiamondTrap and I am " << BLUE << ClapTrap::name
                << RESET << " ClapTrap" << std::endl; 
}
