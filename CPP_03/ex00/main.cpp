#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    ClapTrap bro("bro");
    ClapTrap dude("dude");

    std::cout << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << GREEN << "**************************************************" << RESET << std::endl;
        bro.attack("dude");
        if (bro.getHitPoints() > 0)
            dude.takeDamage(bro.getAttackDamage());
        if (i && i % 4 == 0)
            bro.beRepaired(i);

        dude.attack("bro");
        if (dude.getHitPoints() > 0)
            bro.takeDamage(dude.getAttackDamage());
        if (i && i % 8 == 0)
            dude.beRepaired(i);

        std::cout   << GREEN << ">>>>>>>>>>>>>>>>>> " << PURPLE << "ROUND " << (i + 1) << " RESULT"
                    << GREEN << " <<<<<<<<<<<<<<<<<<" << RESET << std::endl;
        bro.roundResult();
        dude.roundResult();
        std::cout << GREEN << "**************************************************\n" << RESET << std::endl;
    }
}