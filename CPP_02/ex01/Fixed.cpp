#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) 
{
    std::cout << "Int constructor called" << std::endl;
    fixed_point = n << frac_bit;
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    fixed_point = static_cast<int>(roundf(f * (1 << frac_bit)));
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
    return (static_cast<float>(f));
}

int Fixed::toInt( void ) const
{
    return (fixed_point >> frac_bit);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return (os);
}
