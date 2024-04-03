#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw (PmergeMe::ErrorException());
        
        PmergeMe PM(av[1]);
        PM.sortVector();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}