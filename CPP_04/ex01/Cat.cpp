#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Default catto constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this == &other)
        return (*this);
    this->Animal::operator=(other);
        delete this->brain;
    this->brain = new Brain(*other.brain);
    
    return (*this);
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Catto destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << PURPLE << "Meow meow!" << RESET << std::endl;
}

Brain*  Cat::getBrain() const
{
    return (this->brain);
}
