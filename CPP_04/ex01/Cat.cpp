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
    Brain *temp = new Brain();
    *temp = *other.brain;
    if (this->brain)
        delete this->brain; // we need to fre old data because we want to rewrite it but now we don't have memory leak
    this->brain = temp;
    
    return (*this);
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Catto destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << YELLOW << "Meow meow!" << RESET << std::endl;
}
