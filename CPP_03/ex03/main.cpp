#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap bro("bro");
    std::cout << "Hit Points " << bro.hit_points << "\n";
    std::cout << "Energy " << bro.energy_points << "\n"; 
    std::cout << "Attack dmage " << bro.attack_damage << "\n";
    bro.attack("dude");
    bro.whoAmI();
}