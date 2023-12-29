#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 fixed_point;
        static const int    frac_bit = 8;
    
    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float f);
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;
        float operator++();
        float operator++(int);
        float operator--();
        float operator--(int);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const ;
        int toInt( void ) const;
        static Fixed &min(Fixed &x, Fixed &y);
        static const Fixed &min(const Fixed &x, const Fixed &y);
        static Fixed &max(Fixed &x, Fixed &y);
        static const Fixed &max(const Fixed &x, const Fixed &y);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif