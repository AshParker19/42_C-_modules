#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
    private:
        int                 fixed_point;
        static const int    frac_bit = 8;
    
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif