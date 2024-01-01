#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap bro("bro");
    
    std::cout << std::endl;
    bro.guardGate();
    std::cout << std::endl;
    std::cout << "   Hit Points --> " << bro.getHitPoints() << "\n";
    std::cout << "       Energy --> " << bro.getEnergyPoints() << "\n"; 
    std::cout << "Attack damage --> " << bro.getAttackDamage() << "\n";
    std::cout << std::endl;
    bro.attack("dude");
    std::cout << std::endl;
    bro.highFivesGuys();
    std::cout << std::endl;
    bro.whoAmI();
    std::cout << std::endl;
}