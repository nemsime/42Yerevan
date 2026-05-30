#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int raw)
{
    std::cout << "Int constructor called" << std::endl;
    value = raw << fractionalBits;
}

Fixed::Fixed(const float raw)
{
    std::cout << "Float constructor called" << std::endl;
    value = static_cast<int>(roundf(raw * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->value = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits( int const raw )
{
    value = raw;
}

float Fixed::toFloat( void ) const
{
    return static_cast<float>(value) / (1 << fractionalBits);
}

int Fixed::toInt( void ) const
{
    return value >> fractionalBits;
}

std::ostream& operator<<( std::ostream& os, Fixed const& fixed )
{
    os << fixed.toFloat();
    return os;
}
