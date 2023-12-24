#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

Zombie *return_heap(void)
{
    return (newZombie("bro"));
}

Zombie return_stack(void)
{
    Zombie zombie_buddy("buddy");
    return (zombie_buddy);
}

int main()
{
    // test a dynamically allocated object in the scope of the same fucntion
    Zombie *zombie_guy = newZombie("guy"); 
    zombie_guy->announce();
    delete(zombie_guy);

    std::cout << std::endl;

    // test a dynamically allocated object in the other function which returns a pointer to it
    Zombie *zombie_bro = return_heap();
    zombie_bro->announce();
    delete zombie_bro;

    std::cout << std::endl;

    // test how a stack allocated object works in the scope of another function
    randomChump("mate");

    std::cout << std::endl;

    // test a stack allocated object, copy of which was returned from another function
    Zombie zombie_buddy = return_stack();
    zombie_buddy.announce();
}
