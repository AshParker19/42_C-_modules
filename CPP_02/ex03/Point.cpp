#include <iostream>
#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float n1, const float n2) : x(n1), y(n2) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &)
{
    return (*this);
}

Point::~Point() {}

const Fixed &Point::getX() const
{
    return (x);
}

const Fixed &Point::getY() const
{
    return (y);
}
