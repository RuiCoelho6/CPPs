/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:41:35 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/09 10:40:41 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

// Constructors

Fixed::Fixed(): _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Constructor with int raw bits called" << std::endl;
	this->_rawBits = num << 8;
}

Fixed::Fixed(const float num)
{
	std::cout << "Constructor with float raw bits called" << std::endl;
	this->_rawBits = roundf(num * 256);
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_rawBits = other._rawBits;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Conversions

int	Fixed::toInt() const
{
	return (_rawBits >> 8);
}

float	Fixed::toFloat() const
{
	return ((float)_rawBits / 256.0f);
}

// Getter
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

// Setter
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

// Assignment operator
Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return (*this);
}

// Comparison operators

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->_rawBits < other._rawBits);
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->_rawBits > other._rawBits);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->_rawBits <= other._rawBits);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->_rawBits >= other._rawBits);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->_rawBits == other._rawBits);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->_rawBits != other._rawBits);
}

// Arithmetic operators

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;

	result._rawBits = this->_rawBits + other._rawBits;
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;

	result._rawBits = this->_rawBits - other._rawBits;
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;

	result._rawBits = (this->_rawBits * other._rawBits) >> 8;
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;

	result._rawBits = this->_rawBits / other._rawBits;
	return (result);
}

// Increment/Decrement operators

Fixed	&Fixed::operator++()
{
	this->_rawBits ++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	this->_rawBits++;
	return (temp);
}

Fixed	&Fixed::operator--()
{
	this->_rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	this->_rawBits--;
	return (temp);
}

// Return min/max

Fixed	&Fixed::min(Fixed &num1, Fixed &num2)
{
	return (num1 < num2 ? num1 : num2);
}

const Fixed	&Fixed::min(const Fixed &num1, const Fixed &num2)
{
	return (num1 < num2 ? num1 : num2);
}

Fixed	&Fixed::max(Fixed &num1, Fixed &num2)
{
	return (num1 > num2 ? num1 : num2);
}

const Fixed	&Fixed::max(const Fixed &num1, const Fixed &num2)
{
	return (num1 > num2 ? num1 : num2);
}

// Insertion operator
std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
