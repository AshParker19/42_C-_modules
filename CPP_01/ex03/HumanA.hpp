#ifndef HUMAN_A
#define HUMAN_A

#include <string>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon &weapon;
    
    public:
        HumanA(std::string new_name, Weapon &new_weapon) : 
            name(new_name),
            weapon(new_weapon)
            {}
        
        void attack();
};

#endif