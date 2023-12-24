#include <exception>
#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    try
    {
        Zombie *new_zombie = new Zombie(name);
        return (new_zombie);
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Cannot allocate memory!!" << std::endl;
        std::cerr << "Error Type: " << e.what() << std::endl;
        return (NULL);
    }
}
