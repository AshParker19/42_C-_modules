#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0) {}

Fixed::Fixed(const int n) 
{
    fixed_point = n << frac_bit;
}

Fixed::Fixed(const float f)
{
    fixed_point = roundf(f * (1 << frac_bit));
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;

    fixed_point = other.getRawBits();
    return (*this);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->fixed_point > other.fixed_point);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->fixed_point < other.fixed_point);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->fixed_point >= other.fixed_point);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->fixed_point <= other.fixed_point);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->fixed_point == other.fixed_point);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (!(*this == other));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    return (fixed_point);
}

void Fixed::setRawBits( int const raw )
{
    fixed_point = raw;
}

float Fixed::toFloat( void ) const
{
    float f = fixed_point / (1.0 * (1 << frac_bit));
    return (f);
}

int Fixed::toInt( void ) const
{
    return (fixed_point >> frac_bit);
}

/* 
    we need to return a ref to the same output stream object here to enable
    chaining of the operator
    std::cout << fixedObj1 << " " << fixedObj2 << std::endl;
*/
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return (os);
}
