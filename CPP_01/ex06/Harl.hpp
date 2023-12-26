#ifndef GUARD_H
#define GUARD_H

#include <string>

class Harl
{
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    
    public:
        void complain( std::string level );
};

#endif