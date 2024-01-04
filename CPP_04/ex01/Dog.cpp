#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Default doggo constructor called" << std::endl;
    this->brain = new Brain();
    this->type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other), brain(NULL)
{
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this == &other)
        return (*this);
    this->Animal::operator=(other);
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*other.brain);
    return (*this);
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Doggo destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << YELLOW << "Woof woof!" << RESET << std::endl;
}

Brain* Dog::getBrain() const
{
    return (this->brain);
}
