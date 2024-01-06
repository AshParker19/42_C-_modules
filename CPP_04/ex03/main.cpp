#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

Cure *thingy = new Cure[10];

int main()
{
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }
    std::cout << "\n*********** My tests ***********\n" << std::endl;
    {

        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        // Test creating characters and materias
        ICharacter* me = new Character("me");
        ICharacter* bob = new Character("bob");

        // Testing inventory management
        AMateria* tmp;
        for (int i = 0; i < 4; ++i) {
            tmp = src->createMateria(i % 2 == 0 ? "ice" : "cure");
            me->equip(tmp);
        }

        // Try to equip more than inventory size
        tmp = src->createMateria("ice");
        me->equip(tmp); // Should not equip

        // Use each equipped materia
        for (int i = 0; i < 4; ++i) {
            me->use(i, *bob);
        }

        // // Testing deep copy
        // Character copyOfMe = *(dynamic_cast<Character*>(me));
        // copyOfMe.use(0, *bob); // Should work as deep copy

        // // Testing unequip
        // me->unequip(0); // Unequip first slot
        // me->use(0, *bob); // Should do nothing as slot 0 is empty

        // // Clean up unequipped materia
        // delete tmp; // Remember to delete manually to avoid memory leaks

        // // Test unequipping non-existent slot
        // me->unequip(10); // Should do nothing

        // // Test using non-existent slot
        // me->use(10, *bob); // Should do nothing

        // // Clean up
        // delete bob;
        // delete me;
        delete src;
    }
    return 0;
}