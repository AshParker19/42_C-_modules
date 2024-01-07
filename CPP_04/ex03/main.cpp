#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

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

        ICharacter* me = new Character("me");
        ICharacter* bob = new Character("bob");

        AMateria* ice = src->createMateria("ice");
        AMateria* cure = src->createMateria("cure");
        me->equip(ice);
        me->equip(cure);

        // use materias
        me->use(0, *bob);
        me->use(1, *bob);
        
        Character* clone = new Character(*static_cast<Character*>(me));
        clone->use(0, *bob);
        clone->use(1, *bob);

        // unequip materias
        me->unequip(0);
        me->unequip(1);

        // test inventory limits and invalid operations
        for (int i = 0; i < 5; i++)
            me->equip(src->createMateria("ice"));
        me->use(4, *bob);
        me->unequip(4); 

        delete bob;
        delete me;
        delete clone;
        delete src;
    }
    return 0;
}