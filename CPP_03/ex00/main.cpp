#include <iostream>
#include "ClapTrap.hpp"

void put_line(bool nl)
{
    std::cout << GREEN << "**************************************************" << RESET << std::endl;
    if (nl)
        std::cout << std::endl;
}

int main()
{
    ClapTrap bro("bro");
    ClapTrap dude("dude");

    std::cout << std::endl;
    for (int i = 0; i < 11; i++)
    {
        put_line(false);
        bro.attack("dude");
        if (bro.getEnergyPoints() > 0)
            dude.takeDamage(bro.getAttackDamage());
        if (i && i % 4 == 0)
            bro.beRepaired(i);

        dude.attack("bro");
        if (dude.getEnergyPoints() > 0)
            bro.takeDamage(dude.getAttackDamage());
        if (i && i % 8 == 0)
            dude.beRepaired(i);

        std::cout   << GREEN << ">>>>>>>>>>>>>>>>>> " << PURPLE << "ROUND " << (i + 1) << " RESULT"
                    << GREEN << " <<<<<<<<<<<<<<<<<<" << RESET << std::endl;
        bro.roundResult();
        dude.roundResult();
        put_line(true);
    }
}