#include <iostream>
#include <string>

#define GREEN "\033[32m"
#define ORANGE "\033[33m"
#define RESET "\033[0m"

int main()
{
    std::string stringSTR = "HI THIS IS BRAIN";
    std::string *stringPTR = &stringSTR;
    std::string &stringREF = stringSTR;

    std::cout   << "Memory address of stringSTR --> " << GREEN
                << &stringSTR << RESET << std::endl;
    std::cout   << "Memory address of stringPTR --> " << GREEN
                << stringPTR << RESET << std::endl;
    std::cout   << "Memory address of stringREF --> " << GREEN
                << &stringREF << RESET << std::endl;
    
    std::cout   << "         Value of stringSTR --> " << ORANGE
                << stringSTR << RESET << std::endl;
    std::cout   << "         Value of stringPTR --> " << ORANGE 
                << *stringPTR << RESET << std::endl;
    std::cout   << "         Value of stringREF --> " << ORANGE
                << stringREF << RESET << std::endl;
}