/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:41:44 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/09 10:21:24 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	_rawBits;
		static const int	_fractionalBits;

	public:
// Constructors
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& other);

// Assignment operator
		Fixed	&operator=(const Fixed& other);

// Comparison operators
		bool	operator<(const Fixed &other) const;
		bool	operator>(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

// Arithmetic operators
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

// Increment/Decrement operators
		Fixed	&operator++(); // Pre-increment
		Fixed	operator++(int); // Post-increment
		Fixed	&operator--(); // Pre-decrement
		Fixed	operator--(int); // Post-decrement

// Destructor
		~Fixed();

// Conversions
		float	toFloat( void ) const;
		int	toInt( void ) const;

// Return min/max
		static Fixed		&min(Fixed &num1, Fixed &num2);
		static const Fixed	&min(const Fixed &num1, const Fixed &num2);

		static Fixed		&max(Fixed &num1, Fixed &num2);
		static const Fixed	&max(const Fixed &num1, const Fixed &num2);

// Getter
		int	getRawBits(void) const;

//Setter
		void	setRawBits(int const raw);
};

// Insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif