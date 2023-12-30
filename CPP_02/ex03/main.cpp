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
    
}
