#include <string>
#include "Weapon.hpp"

Weapon::Weapon(const std::string &new_type) : type(new_type){}

Weapon::~Weapon() {}

const std::string &Weapon::getType(void)
{
    return (type);
}

void  Weapon::setType(std::string type)
{
    this->type = type;
}


