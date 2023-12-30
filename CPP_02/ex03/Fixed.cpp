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
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
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

Fixed Fixed::operator+(const Fixed &other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed Fixed::operator++()
{
    ++fixed_point;
    return (toFloat());
}

Fixed Fixed::operator++(int)
{
    Fixed orig(*this);

    this->fixed_point++;
    return (orig);
}

Fixed Fixed::operator--()
{
    --fixed_point;
    return (toFloat());
}

Fixed Fixed::operator--(int)
{
    Fixed orig(*this);

    this->fixed_point--;
    return (orig);
}

Fixed::~Fixed() {}

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

Fixed &Fixed::min(Fixed &x, Fixed &y)
{
    return ((x < y) ? x : y);
}

const Fixed &Fixed::min(const Fixed &x, const Fixed &y)
{
    return ((x < y) ? x : y);
}

Fixed &Fixed::max(Fixed &x, Fixed &y)
{
    return (x > y ? x : y);
}

const Fixed &Fixed::max(const Fixed &x, const Fixed &y)
{
    return (x > y ? x : y);
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
