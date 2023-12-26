#include <string>
#include <iostream>
#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout   << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
                << std::endl ;
}

void Harl::info( void )
{
    std::cout   << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
                << std::endl;
}

void Harl::warning( void )
{
    std::cout   << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
                << std::endl;
}

void Harl::error( void )
{
    std::cout   << "This is unacceptable! I want to speak to the manager now."
                << std::endl;
}


void Harl::complain( std::string level )
{
    void (Harl::*complaints[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    int    index = level[0];

    switch(index)
    {
        case 'D':
            (this->*complaints[0])(); // TODO: know about this syntax better
            break ;

        case 'I':
            (this->*complaints[1])();
            break ;
        
        case 'W':   
            (this->*complaints[2])();
            break ;
        
        case 'E':
            (this->*complaints[3])();
            break ;
        
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break ;
    }
}
