#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(const std::string &new_name) :
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
    std::cout << "ClapTrap " << GREEN << name << RESET << " did his best at this battle and now gone!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (energy_points <= 0)
        std::cout << YELLOW << name << RESET << " has no more energy to attack!" << std::endl; 
    else
        if (hit_points > 0)
        {
            std::cout   << "ClapTrap " << BLUE << name << RESET <<  " aggressively attacking ClapTrap "
                        << PURPLE << target << RESET << std::endl;
            energy_points--;
        }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << YELLOW << name << RESET << " has suffered " << RED
              << amount << RESET<< " points of damage!" << std::endl;
    hit_points -= amount;
    if (hit_points <= 0)
        std::cout << RED << name << RESET << " was destroyed!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energy_points <= 0)
        std::cout << YELLOW << name << RESET << " has no energy left to repair!" << std::endl; 
    else
    {
        energy_points--;
        hit_points += amount;
        std::cout   << GREEN << name << RESET << " is being repared and getting "
                    PURPLE << amount << RESET << " points back!" << std::endl;
    }
}

int  ClapTrap::getAttackDamage() const
{
    return (this->attack_damage);
}

int  ClapTrap::getHitPoints() const
{
    return (this->hit_points);
}

int ClapTrap::getEnergyPoints() const
{
    return (this->energy_points);
}

void ClapTrap::roundResult() const
{
    std::cout   << BLUE << name << RESET << "  --> " << YELLOW << hit_points 
                << RESET << " hit points and " << YELLOW << energy_points
                << RESET <<  " energy points" << std::endl;
}
