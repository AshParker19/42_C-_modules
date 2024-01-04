
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    std::cout << "\n*********** My tests ***********\n" << std::endl;

    Animal *animals[10];
    
    int x = 0;
    for (x = 0; x < 5; x++)
        animals[x] = new Dog();
    for ( ; x < 10; x++)
        animals[x] = new Cat();
    for (int k = 0; k < 10; k++)
        animals[k]->makeSound();
    for (int k = 0; k < 10; k++)
        delete animals[k];

    std::cout << "\n***** Copy and assignment tests *****\n" << std::endl;

    Dog basic;
    {
        Dog tmp = basic;
    }

    std::cout << "\n*********** My tests ***********\n" << std::endl;

    Animal *beast = new Dog();
    
    for (int x = 0; x < 101; x++)
        beast->getBrain()->setIdea(x, "Thinks in the language of dogs...");

    Animal *copy = new Dog(static_cast<Dog&>(*beast));

    std::cout << std::endl;
    try 
    {
        for (int x = 0; x < 101; x++)
            std::cout << copy->getBrain()->getIdea(x) << std::endl;
    } 
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    delete beast;
    delete copy;

    return 0;
}
