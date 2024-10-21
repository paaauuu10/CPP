#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Dafault constructor called" << std::endl;
    this->_fixedPoint = 0;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_fixedPoint = other.getRawBits();
    }
    return (*this);
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void)const
{
    return (this->_fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPoint = raw;
}

Fixed::Fixed(const int nb)
{
    std::cout << "INT constructor called" << std::endl;
    this->_fixedPoint = nb << this->_fractionalBits;
}
Fixed::Fixed(const float flt)
{
    std::cout << "FLOAT constructor called" << std::endl;
    this->_fixedPoint = roundf(flt * (1 << this->_fractionalBits));
}

float Fixed::toFloat(void)const
{
    return ((float)this->_fixedPoint / (1 << this->_fractionalBits));
}

int Fixed::toInt(void)const
{
    return (this->_fixedPoint >> this->_fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}