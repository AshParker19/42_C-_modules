#include <string>
#include <iostream>
#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

std::string Harl::complaints[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

void (Harl::*Harl::funcs[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

void Harl::debug( void )
{
    std::cout   << "[ DEBUG ]\n"
                << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n"
                << std::endl ;
}

void Harl::info( void )
{
    std::cout   << "[ INFO ]\n"
                << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n"
                << std::endl;
}

void Harl::warning( void )
{
    std::cout   << "[ WARNING ]\n"
                << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n"
                << std::endl;
}

void Harl::error( void )
{
    std::cout   << "[ ERROR ]\n"
                << "This is unacceptable! I want to speak to the manager now.\n"
                << std::endl;
}

void Harl::complain( std::string level )
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (level == complaints[i])
            break ;
    }

    switch(i)
    {
        // fall through
        case (0):
            (this->*funcs[0])();

        // fall through
        case (1):
            (this->*funcs[1])();

        // fall through
        case (2):
            (this->*funcs[2])();
        
        // fall through
        case (3):
            (this->*funcs[3])();
            break ;

        // fall through
        default :
            std::cout   << "[ Probably complaining about insignificant problems ]"
                        << std::endl;

    }
}
