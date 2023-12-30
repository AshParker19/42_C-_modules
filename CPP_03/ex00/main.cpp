#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    ClapTrap bro("bro");
    ClapTrap dude("dude");

    for (int i = 0; i < 11; i++)
    {
        bro.attack("dude");
        dude.takeDamage(bro.getAttackDamage());
        if (i % 8 == 0)
            dude.beRepaired(i);

        dude.attack("bro");
        bro.takeDamage(dude.getAttackDamage());
        if (i % 8 == 0)
            bro.beRepaired(i);
    }
}