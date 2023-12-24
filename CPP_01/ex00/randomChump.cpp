#include <iostream>
#include "Zombie.hpp"

void    randomChump( std::string name )
{
    Zombie chumpy(name);

    chumpy.announce();
}
