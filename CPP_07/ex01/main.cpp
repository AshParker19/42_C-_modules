#include "iter.hpp"

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::cout << "intArray: ";
    ::iter(intArray, 5, ::example);

    std::cout << std::endl << "charArray: ";
    ::iter(charArray, 5, ::example);

    std::cout << std::endl << "floatArray: ";
    ::iter(floatArray, 5, ::example);

    std::cout << std::endl;
}