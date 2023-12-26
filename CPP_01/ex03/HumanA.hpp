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
        HumanA(const std::string &new_name, Weapon &new_weapon);
        ~HumanA();
        
        void attack();
};

#endif