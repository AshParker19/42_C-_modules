#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    ClapTrap bro("bro");
    ClapTrap dude("dude");

    bro.attack("dude");
    dude.takeDamage(5);
    dude.attack("bro");
    bro.takeDamage(7);
    
    bro.attack("dude");
    dude.takeDamage(10);
}