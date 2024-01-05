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
