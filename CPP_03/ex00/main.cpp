#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    ClapTrap bro("bro");
    ClapTrap dude("dude");

    bro.attack("dude");  // TODO: make a getter here to actually
    dude.takeDamage(bro.getAttackDamage());
    dude.attack("bro"); //TODO: use a for loop and random value using rand() for damage
    bro.takeDamage(7);
    
    bro.attack("dude");
    dude.takeDamage(10);
}