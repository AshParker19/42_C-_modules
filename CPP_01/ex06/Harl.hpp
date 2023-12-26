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
    
    public:
        Harl();
        ~Harl();

        enum id
        {
            
        };

        void complain( std::string level );
};

#endif