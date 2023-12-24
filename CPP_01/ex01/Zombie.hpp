#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
    private:
        std::string name;
    
    public:
        Zombie();
        // ~Zombie(); TODO: know if we still need to have a destructor because we're not asked to print anything when an object is destroyed

        void announce( void );
        void set_name(const std::string &name);
};

#endif