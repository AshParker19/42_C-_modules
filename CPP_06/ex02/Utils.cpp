#include "Utils.hpp"

Base *generate(void)
{
    int i = rand() % 3;
    
    if (i == 0)
        return (new A);
    else if (i == 1)
        return (new B);
    else
        return (new C);
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A";
    else if (dynamic_cast<B *>(p))
        std::cout << "B";
    else if (dynamic_cast<C *>(p))
        std::cout << "C";
    else
        std::cout << "Unknown";
    std::cout << std::endl;
}

void identify(Base &p)
{
    try{
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::bad_cast &bc)
    {
        try{
            B &b = dynamic_cast<B &>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch (std::bad_cast &bc)
        {
            try{
                C &c = dynamic_cast<C &>(p);
                (void)c;
                std::cout << "C" << std::endl;
            }
            catch (std::bad_cast &bc)
            {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}
