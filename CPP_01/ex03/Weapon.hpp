#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
    private:
        std::string type;
    
    public:
        Weapon(std::string new_type) :
        type(new_type)
        {}

        const std::string &getType(void);
        void  setType(std::string type);
};

#endif
