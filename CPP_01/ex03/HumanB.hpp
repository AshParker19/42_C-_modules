#ifndef HUMAN_B
#define HUMAN_B

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *weapon;
    
    public:
        HumanB(std::string new_name) :
            name(new_name),
            weapon(NULL)
        {}

        void setWeapon(Weapon &weapon);
        void unsetWeapon();
        void attack();
};

#endif