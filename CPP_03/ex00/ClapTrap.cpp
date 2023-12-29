#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(std::string new_name) :
                    name(new_name),
                    hit_points(10),
                    energy_points(10),
                    attack_damage(0)
{
    std::cout << "ClapTrap " << GREEN << name << RESET << " is ready to fight!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    this->name = other.name;
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << GREEN << name << RESET <<" did his best at this battle and now gone!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (energy_points > 0)
    {
        if (hit_points > 0)
        {
            std::cout   << "ClapTrap " << BLUE << name << RESET <<  " aggressively attacking ClapTrap "
                        << PURPLE << target << RESET << " and causes " << RED << attack_damage
                        << RESET << " points of severe damage!" << std::endl;
            energy_points--;
        }
        else
            std::cout << YELLOW << name << RESET << " ran out of hit point!" << std::endl;
    }
    else
        std::cout << YELLOW << name << RESET << " ran out of energy!" << std::endl; 
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << PURPLE << name << RESET << " has suffered " << RED
              << amount << RESET<< " points of damage!" << std::endl;
    hit_points -= amount;
    if (hit_points <= 0)
        std::cout << RED << name << RESET << " was destroyed!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energy_points > 0)
    {
        std::cout   << GREEN << name << RESET << " is being repared and getting "
                    PURPLE << amount << RESET << " points back!" << std::endl;
        energy_points--;
        hit_points += amount;
    }
    else
        std::cout << YELLOW << name << RESET << " ran out of energy!" << std::endl; 
}
