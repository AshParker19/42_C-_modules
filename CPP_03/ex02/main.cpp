#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap bro("bro");
    FragTrap dude("dude");

    dude.highFivesGuys();
    bro.attack("dude");
    dude.takeDamage(5);
    dude.attack("bro");
    bro.takeDamage(7);
    
    bro.attack("dude");
    dude.takeDamage(10);
}