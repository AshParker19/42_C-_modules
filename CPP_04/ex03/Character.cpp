#include "Character.hpp"

Character::Character() {}

Character::Character(const std::string &new_name) : name(new_name) 
{
    for (int i = 0; i < 4; i++)
        materials[i] = NULL;
}

Character::Character(const Character &other)
{
    *this = other;
}

Character &Character::operator=(const Character &other)
{
    if (this == &other)
        return (*this);
    AMateria *copy[4];
    for (int i = 0; i < 4; i++)
    {
        delete materials[i];
        if (other.materials[i])
            copy[i] = other.materials[i]->clone();
    }
    return (*this);
}

Character::~Character() {}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{

}

void Character::unequip(int idx)
{

}

void Character::use(int idx, ICharacter& target)
{

}
