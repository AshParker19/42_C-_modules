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
        static std::string complaints[4];
        static void (Harl::*funcs[])();
    
    public:
        Harl();
        ~Harl();

        void complain( std::string level );
};

#endif