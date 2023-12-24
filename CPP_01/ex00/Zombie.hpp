#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
    private:
        std::string name;
    
    public:
        Zombie(std::string new_name) : name(new_name) {} // TODO: know if can we have initializing list in a header
        ~Zombie();

        void announce( void );
};

#endif