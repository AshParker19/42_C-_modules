#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
    this->type = type;
}

AMateria::AMateria() {}

AMateria::AMateria(const AMateria &other)
{
    *this = other;
}

AMateria &AMateria::operator=(const AMateria &)
{
    return (*this);
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter&) {}
