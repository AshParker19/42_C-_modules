#include "Animal.hpp"
#include "Brain.hpp"
#include <exception>

Brain::Brain()
{
    std::cout << "Default brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    *this = other;
}

Brain &Brain::operator=(const Brain &other)
{
    if (this == &other)
        return (*this);
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

const std::string &Brain::getIdea(int index) const
{
    if (index < 0 || index >= 100)
        throw std::runtime_error("Out Of Bounds Exception");
    return (this->ideas[index]);
}

void Brain::setIdea(int index, const std::string &idea)
{
    if (index < 0 || index >= 100)
    {
        std::cout << RED << "Wrong index!" << RESET << std::endl;
        return ;
    }
    this->ideas[index] = idea;
}
