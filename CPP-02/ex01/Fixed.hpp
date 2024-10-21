#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _fixedPoint;
        static const int _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &other);
        ~Fixed();
        Fixed &operator=(const Fixed &other);
        int     getRawBits(void)const;
        void    setRawBits(int const raw);
        Fixed(const int nb);
        Fixed(const float flt);
        float   toFloat(void)const;
        int     toInt(void)const;
}; 

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif