/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:41:35 by rpires-c          #+#    #+#             */
/*   Updated: 2025/05/28 18:18:34 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed()
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

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::toInt() const
{
	return (_rawBits >> 8);
}

float	Fixed::toFloat() const
{
	return ((float)_rawBits / 256.0f);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

std::ostream	&operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.float();
	return (os);
}
