#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        PmergeMe PM;

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
