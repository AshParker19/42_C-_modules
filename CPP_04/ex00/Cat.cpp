#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Default catto constructor called" << std::endl;
    this->type = "Cat";
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
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Catto destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << YELLOW << "Meow meow!" << RESET << std::endl;
}
