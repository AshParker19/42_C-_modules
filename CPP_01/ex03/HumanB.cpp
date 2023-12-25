#include <iostream>
#include "HumanB.hpp"

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void HumanB::unsetWeapon(void)
{
    weapon = NULL;
}

void HumanB::attack()
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " is not armed yet!" << std::endl;
}

