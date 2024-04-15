#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        PmergeMe PM;

        if (ac == 1)
            throw (PmergeMe::ErrorException());

        PM.parse(ac, av);
        PM.generateSequence();
        PM.handleVector();
        PM.handleList();
        PM.displayResults();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
