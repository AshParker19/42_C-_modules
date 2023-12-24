#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
    int N = 10;

    Zombie *dead_dudes = zombieHorde(N, "Dudes");
    if (dead_dudes)
    {
        for (int i = 0; i < N; i++)
            dead_dudes[i].announce();
        delete[] dead_dudes;
    }

    std::cout << std::endl;
    
    N = 5;
    Zombie *dead_folks = zombieHorde(N, "Folks");
    if (dead_folks)
    {
        for (int i = 0; i < N; i++)
            dead_folks[i].announce();
        delete[] dead_folks;
    }
}