#include "easyfind.hpp"

int main(int ac, char **av)
{
    if (ac != 3)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return (1);
    }

    try 
    {
        int value;
        {
            value = atoi(av[1]);
            std::vector<int> testVector (5);
            testVector.push_back(10);
            testVector.push_back(20);
            testVector.push_back(30);
            testVector.push_back(40);
            testVector.push_back(50);

            value =  easyfind(testVector, value);
            std::cout << "The value --> " << value << std::endl;
        }
        std::cout << "==================================" << std::endl;
        {
            value = atoi(av[2]);
            std::list<int> testList;
            testList.push_back(11);
            testList.push_front(22);
            testList.push_back(33);
            testList.push_front(44);
            testList.push_back(55);

            value = easyfind(testList, value);
            std::cout << "The value --> " << value << std::endl;
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
}