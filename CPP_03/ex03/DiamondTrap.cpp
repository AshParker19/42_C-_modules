#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {}

DiamondTrap::DiamondTrap(const std::string &new_name) :
                         ClapTrap(new_name + "_clap_name"),
                         ScavTrap(new_name),
                         FragTrap(new_name),
                         name(new_name)
{
    this->energy_points = ScavTrap::ENERGY_POINTS;
    std::cout << "DiamontTrap " << GREEN << name << RESET << " has gained all the wisdom and ready for combat!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : 
                         ClapTrap(other),
                         ScavTrap(other),
                         FragTrap(other)
{
        *this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this == &other)
        return (*this);
    this->ScavTrap::operator=(other);
    this->FragTrap::operator=(other);
    this->name = other.name;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamontTrap " << GREEN << name << RESET << " finished his stuff here and goes away!" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout   << "I am " << BLUE << name << RESET << " DiamondTrap and I am " << BLUE << ClapTrap::name
                << RESET << " ClapTrap" << std::endl; 
}
