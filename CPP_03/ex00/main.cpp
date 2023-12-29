#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    ClapTrap bro("bro");
    ClapTrap dude("dude");

    bro.attack("dude");  // TODO: can we affect damage here?
    dude.takeDamage(5);
    dude.attack("bro"); //TODO: use a for loop and random value using rand() for damage
    bro.takeDamage(7);
    
    bro.attack("dude");
    dude.takeDamage(10);
}