#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : m_index(0)
{
    for (int i = 0; i < 4; i++)
        mat_storage[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    *this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
     if (this == &other)
        return (*this);
    AMateria *copy[4];
    for (int i = 0; i < 4; i++)
    {
        delete mat_storage[i];
        if (other.mat_storage[i])
            copy[i] = other.mat_storage[i]->clone();
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (mat_storage[i])
            delete mat_storage[i];
    }
}

void MateriaSource::learnMateria(AMateria *target)
{
    if (target && m_index > 0 && m_index < 4)
    {
        mat_storage[m_index] = target->clone();
        m_index++;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (type == mat_storage[i]->getType())
            return (mat_storage[i]->clone());
    }
    return (0);
}

