#include "Ice.hpp"

Ice::Ice()
{
    this->type = "ice";
}

Ice::Ice(const Ice &other)
{
    *this = other;
}

Ice &Ice::operator=(const Ice &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

Ice::~Ice() {}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << (target.getName() + " *"); 
}
