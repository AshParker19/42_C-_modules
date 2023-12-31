#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string name;
        using FragTrap::hit_points;
        using ScavTrap::energy_points;
        using FragTrap::attack_damage;
    
    public:
        DiamondTrap();
        DiamondTrap(const std::string &new_name);
        DiamondTrap(const DiamondTrap &other);
        DiamondTrap &operator=(const DiamondTrap &other);
        ~DiamondTrap();

        using ScavTrap::attack;
        void whoAmI();

};

#endif