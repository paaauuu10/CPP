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
        Fixed(const int nb);
        Fixed(const float flt);

        int     getRawBits(void)const;
        void    setRawBits(int const raw);
       
        float   toFloat(void)const;
        int     toInt(void)const;

        //Compare operations
        bool operator>(conts Fixed &other)const;
        bool operator<(conts Fixed &other)const;
        bool operator>=(conts Fixed &other)const;
        bool operator<=(conts Fixed &other)const;
        bool operator==(conts Fixed &other)const;
        bool operator!=(conts Fixed &other)const;

        //Aritmetic operations
        Fixed operator+(const Fixed &other)const;  
        Fixed operator-(const Fixed &other)const;  
        Fixed operator*(const Fixed &other)const;  
        Fixed operator/(const Fixed &other)const;

        //Increment/Decrement operations
        Fixed operator++(void);
        Fixed operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);

        //Overloaded functions
        static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
}; 

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif