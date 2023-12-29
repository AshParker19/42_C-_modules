#include <iostream>
#include <string>
#include "FragTrap.hpp"

FragTrap::FragTrap() {}

FragTrap::FragTrap(const std::string &new_name) : ClapTrap(new_name)
{
    name = new_name;
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap " << GREEN << name << RESET << " is here for a clash!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap (other)
{
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    ClapTrap::operator=(other);
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << GREEN << name << RESET << " decided to get out of here!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << YELLOW << name << RESET << " is requesting a high five! Who's in for some team spirit?" << std::endl; 
}
