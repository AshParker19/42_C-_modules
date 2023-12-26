#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
    private:
        std::string name;
    
    public:
        Zombie(const std::string &new_name);
        ~Zombie();

        void announce( void );
};

#endif