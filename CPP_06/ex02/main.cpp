#include "Utils.hpp"

int main()
{
    {
        Base *base = generate();
        identify(base);
        identify(*base);
        delete base;
    }
    std::cout << std::endl;
    {
        Wrong *w = new Wrong;
        Base *base = w;
        identify(base);
        identify(*base);
        delete base;
    }
}