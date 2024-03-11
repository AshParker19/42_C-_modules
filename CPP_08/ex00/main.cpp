#include "easyfind.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return (1);
    }

    {
        std::vector<int> testVector (5);
        testVector.push_back(10);
        testVector.push_back(20);
        testVector.push_back(30);
        testVector.push_back(40);
        testVector.push_back(50);

        int value;
        value =  easyfind(testVector, std::atoi(av[1]));
        std::cout << "The value --> " << value << std::endl;
    }
}