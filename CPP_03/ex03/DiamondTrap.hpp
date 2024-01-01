#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string name;
  
    public:
        DiamondTrap();
        DiamondTrap(const std::string &new_name);
        // DiamondTrap(const DiamondTrap &other);
        // DiamondTrap &operator=(const DiamondTrap &other);
        ~DiamondTrap();

        void whoAmI();
};

#endif