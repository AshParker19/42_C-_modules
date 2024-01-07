#include "Character.hpp"

Character::Character() : name(""), index(0), trash_index(0)
{
    for (int i = 0; i < 4; i++)
    {
        materials[i] = NULL;
        trash[i] = NULL;
    }
}

Character::Character(const std::string &new_name) : name(new_name), index(0), trash_index(0)
{
    for (int i = 0; i < 4; i++)
    {
        materials[i] = NULL;
        trash[i] = NULL;
    }
}

Character::Character(const Character &other)
{
    for (int i = 0; i < 4; i++)
    {
        materials[i] = NULL;
        trash[i] = NULL;
    }
    *this = other;
}

Character &Character::operator=(const Character &other)
{
    if (this == &other)
        return (*this);
    
    for (int i = 0; i < 4; i++)
    {   
        if (this->materials[i])
            delete this->materials[i];
        if (other.materials[i])
            this->materials[i] = other.materials[i]->clone();
        else
            this->materials[i] = NULL;
    }
    this->name = other.name;
    this->index = other.index;
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (materials[i])
            delete materials[i];
        if (trash[i])
            delete trash[i];
    }
}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    if (index < 4)
        this->materials[index++] = m;
    else if (m)
        delete m;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        AMateria *m = this->materials[idx];
        if (!m)
            return;
        this->materials[idx] = this->materials[--index];
        this->materials[index] = NULL;
        if (this->trash[trash_index])
            delete this->trash[trash_index];
        this->trash[trash_index++] = m;
        if (trash_index == 4)
            trash_index = 0;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && index < 4)
    {
        AMateria *to_use = materials[idx];
        if (!to_use)
            return ;
        to_use->use(target);
    }
}
