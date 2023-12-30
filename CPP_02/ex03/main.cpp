#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
    Point a(0, 0), b(10, 0), c(0, 10), point(0.1, 9.2);
    
    std::cout << "a: x --> " << a.getX() << " | y --> " << a.getY() << std::endl;   
    std::cout << "b: x --> " << b.getX() << " | y --> " << b.getY() << std::endl;   
    std::cout << "c: x --> " << c.getX() << " | y --> " << c.getY() << std::endl; 
    std::cout << "point: x --> " << point.getX() << " | y --> " << point.getY() << std::endl;

    if (bsp(a, b, c, point))
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;
    
    Point a1(0, 0), b1(10, 0), c1(0, 10), point1(0.1, 11.2);

    std::cout << "-----------------------------------------------" << std::endl;

    std::cout << "a: x --> " << a1.getX() << " | y --> " << a1.getY() << std::endl;
    std::cout << "b: x --> " << b1.getX() << " | y --> " << b1.getY() << std::endl;
    std::cout << "c: x --> " << c1.getX() << " | y --> " << c1.getY() << std::endl;
    std::cout << "point: x --> " << point1.getX() << " | y --> " << point1.getY() << std::endl;

    if (bsp(a1, b1, c1, point1))
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;

    std::cout << "-----------------------------------------------" << std::endl;

    Point a2(0, 0), b2(10, 0), c2(0, 10), point2(0, 0);
    // Point a2(0, 0), b2(10, 0), c2(0, 10), point2(0.1, 0.1);

    std::cout << "a: x --> " << a2.getX() << " | y --> " << a2.getY() << std::endl;
    std::cout << "b: x --> " << b2.getX() << " | y --> " << b2.getY() << std::endl;
    std::cout << "c: x --> " << c2.getX() << " | y --> " << c2.getY() << std::endl;
    std::cout << "point: x --> " << point2.getX() << " | y --> " << point2.getY() << std::endl;

    if (bsp(a2, b2, c2, point2))
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;
}
