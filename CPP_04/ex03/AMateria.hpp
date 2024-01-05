#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string type;

    public:
        AMateria(std::string const & type);
        AMateria();
        AMateria(const AMateria &other);
        AMateria &operator=(const AMateria &other);
        ~AMateria();
        
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif