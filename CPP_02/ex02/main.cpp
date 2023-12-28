#include <iostream>
#include "Fixed.hpp"

int main( void )
{
    {
        // Fixed a;
        // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
        // std::cout << a << std::endl;
        // std::cout << ++a << std::endl;
        // std::cout << a << std::endl;
        // std::cout << a++ << std::endl;
        // std::cout << a << std::endl;
        // std::cout << b << std::endl;
        // std::cout << Fixed::max( a, b ) << std::endl;
        // return 0;
    }
    std::cout << "----My tests---" << std::endl;
    {
        Fixed b, c;
        b.setRawBits(42);
        c.setRawBits(10);

        std::cout << "<> <= =>" << std::endl;
        std::cout << (b > c) << std::endl;
        std::cout << (b < c) << std::endl;
        c.setRawBits(42);
        std::cout << (b <= c) << std::endl;
        std::cout << (b >= c) << std::endl;

        std::cout << "== !=" << std::endl;
        b.setRawBits(100);
        std::cout << (b == c) << std::endl;
        std::cout << (c == c) << std::endl;
        std::cout << (b != c) << std::endl;
    }
}
