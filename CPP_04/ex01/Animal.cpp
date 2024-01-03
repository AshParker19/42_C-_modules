#include "Animal.hpp"

Animal::Animal() : type("Beast")
{
    std::cout << "Default beasty constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Beasty destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound() const
{
    std::cout << YELLOW << "Beasty sound!" << RESET << std::endl;
}
