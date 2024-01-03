
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // delete j;//should not create a leak
    // delete i;

    // std::cout << "\n*********** My tests ***********\n" << std::endl;

    // Animal **animals = new Animal*[10];
    // // const Animal *b = new Dog();
    
    // int x = 0;
    // for (x = 0; x < 5; x++)
    //     animals[x] = new Dog();
    // for ( ; x < 10; x++)
    //     animals[x] = new Cat();
    // for (int k = 0; k < 10; k++)
    //     animals[k]->makeSound();
    // for (int k = 0; k < 10; k++)
    //     delete animals[k];

    // delete[] animals;

    std::cout << "\n***** Copy constructor test *****\n" << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
    }
    return 0;
}