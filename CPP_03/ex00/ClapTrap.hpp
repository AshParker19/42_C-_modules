#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

class ClapTrap
{
    private:
        std::string name;
        int         hit_points;
        int         energy_points;
        int         attack_damage;

    public:
        ClapTrap();
        ClapTrap(const std::string &new_name);
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap &other);
        ~ClapTrap();
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);  
        int  getAttackDamage() const;
        int  getHitPoints() const;
        int  getEnergyPoints() const;
};

#endif