#include <string>
#include "Weapon.hpp"

const std::string &Weapon::getType(void)
{
    return (type);
}

void  Weapon::setType(std::string type)
{
    this->type = type;
}


