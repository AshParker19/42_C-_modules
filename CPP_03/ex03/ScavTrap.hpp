#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    protected:
        static const int ENERGY_POINTS;
    
    public:
        ScavTrap();
        ScavTrap(const std::string &new_name);
        ScavTrap(const ScavTrap &other);
        ScavTrap &operator=(const ScavTrap &other);
        ~ScavTrap();

        void attack(const std::string& target);
        void guardGate();
};

#endif