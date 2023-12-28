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
        bool operator>(const Fixed &other) const ;
        bool operator<(const Fixed &other) const ;
        bool operator>=(const Fixed &other) const ;
        bool operator<=(const Fixed &other) const ;
        bool operator==(const Fixed &other) const ;
        bool operator!=(const Fixed &other) const ;
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const ;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif