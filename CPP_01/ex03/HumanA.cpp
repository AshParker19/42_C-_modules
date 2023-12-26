#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(const std::string &new_name, Weapon &new_weapon) : 
                                               name(new_name), 
                                               weapon(new_weapon) {}

HumanA::~HumanA() {}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
