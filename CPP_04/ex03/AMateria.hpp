#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
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
        virtual void use(ICharacter& target); // this function accepts a reference to an interface which means it can accept any class that implements that interface
};

#endif