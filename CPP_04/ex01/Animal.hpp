#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define PURPLE  "\033[35m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

class Animal
{
    protected:
        std::string type;
    
    public:
        Animal();
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();

        std::string getType() const;
        virtual void makeSound() const;
        virtual Brain* getBrain() const = 0;
};

#endif