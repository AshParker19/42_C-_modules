#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Default doggo constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this == &other)
        return (*this);
    this->Animal::operator=(other);
    Brain *temp = new Brain();
    *temp = *other.brain;
    if (this->brain)
        delete this->brain;
    this->brain = temp;

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
