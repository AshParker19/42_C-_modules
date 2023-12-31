#include <iostream>
#include <string>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {}

ScavTrap::ScavTrap(const std::string &new_name) : ClapTrap(new_name) // TODO: how to give ClapTrap different name?
{
    name = new_name;
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
    ClapTrap::operator=(other);
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
    std::cout << "ScavTrap " << BLUE << name << RESET << " is guarding the gate now. No one goes through!" << std::endl;
}
