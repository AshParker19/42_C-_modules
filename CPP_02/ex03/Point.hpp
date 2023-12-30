#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
    
    public:
        Point();
        Point(const float n1, const float n2);
        Point(const Point &other);
        Point &operator=(const Point &other);
        ~Point();

        const Fixed &getX() const;
        const Fixed &getY() const;
};

#endif