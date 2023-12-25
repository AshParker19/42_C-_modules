#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
{
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
}
{
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club); // we can change weapon because we use not pointer but refercne here
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
}
    std::cout << std::endl;
// my tests
{

    HumanB paul("Paul");
    paul.attack();

    Weapon sword = Weapon("sword");
    paul.setWeapon(sword);
    paul.attack();

    //sword.setType(NULL); // will not work because Weapon constructor expects a valid string
    paul.unsetWeapon();
    paul.attack();

    sword = Weapon("bigger sword"); // reasigning sword to a new object
    paul.setWeapon(sword);
    paul.attack();

    sword.setType("even bigger sword");
    paul.attack();
}
    return 0;
}