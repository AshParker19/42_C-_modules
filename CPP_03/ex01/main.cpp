#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap bro("bro");
    ScavTrap dude("dude");

    bro.attack("dude");
    dude.takeDamage(5);
    dude.attack("bro");
    bro.takeDamage(7);
    
    bro.attack("dude");
    dude.takeDamage(10);
}