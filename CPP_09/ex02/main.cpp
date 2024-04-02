#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        (void) ac;
        PmergeMe PM(av[1]);

    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}