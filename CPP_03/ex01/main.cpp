#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap bro("bro");
    ScavTrap dude("dude");

    std::cout << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << GREEN << "**************************************************" << RESET << std::endl;
        bro.attack("dude");
        if (bro.getEnergyPoints() > 0)
            dude.takeDamage(bro.getAttackDamage());
        if (dude.getHitPoints() <= 0)
        {
            std::cout << GREEN << "**************************************************\n" << RESET << std::endl;
            break ;
        }
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
        std::cout << GREEN << "**************************************************\n" << RESET << std::endl;
    }
}