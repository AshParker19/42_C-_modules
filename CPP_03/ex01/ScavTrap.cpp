#include <iostream>
#include <string>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {}

ScavTrap::ScavTrap(const std::string &new_name) : ClapTrap(new_name)
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap " << GREEN << name << RESET << " is thrilled to punch some faces!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this == &other)
        return (*this);
    this->ClapTrap::operator=(other);
    /*
        '=' operator of a base class copies only base class related data
        this is called object-slicing, we need to avoid it by assigning all the derive
        class related members manually
    */
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << GREEN << name << RESET << " is no longer in this fight!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (energy_points <= 0)
        std::cout << YELLOW << name << RESET << " has no more energy to attack!" << std::endl; 
    else
        if (hit_points > 0)
        {
            std::cout   << "ScavTrap " << BLUE << name << RESET <<  " ruthlessly striking ScavTrap "
                        << PURPLE << target << RESET << std::endl;
            energy_points--;
        }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << YELLOW << name << RESET << " is guarding the gate now. No one goes through!" << std::endl;
}
