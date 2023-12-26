#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
    private:
        std::string type;
    
    public:
        Weapon(const std::string &new_type);
        ~Weapon();

        const std::string &getType(void);
        void  setType(std::string type);
};

#endif
