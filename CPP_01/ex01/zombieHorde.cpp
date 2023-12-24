#include <exception>
#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    try
    {
        Zombie *horde = new Zombie[N];
        for (int i = 0; i < N; i++)
            horde[i].set_name(name);
        return (horde);
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Cannot allocate memory!!" << std::endl;
        std::cerr << "Error Type: " << e.what() << std::endl;
        return (NULL);
    }
}
