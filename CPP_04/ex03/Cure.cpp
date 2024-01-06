#include "Cure.hpp"

Cure::Cure()
{
    this->type = "cure";
}

Cure::Cure(const Cure &other)
{
    *this = other;
}

Cure &Cure::operator=(const Cure &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

Cure::~Cure() {}

void Cure::use(ICharacter& target)
{
    std::cout << ("* heals " + target.getName() + "'s wounds *");
}

AMateria *Cure::clone() const
{
    return (new Cure);
}
