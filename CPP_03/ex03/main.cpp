#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap bro("bro");
    std::cout << "Hit Points " << bro.getHitPoints() << "\n";
    std::cout << "Energy " << bro.getEnergyPoints() << "\n"; 
    std::cout << "Attack damage " << bro.getAttackDamage() << "\n";
    bro.attack("dude");
    bro.whoAmI();
}