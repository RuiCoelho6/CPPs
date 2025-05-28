/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:41:44 by rpires-c          #+#    #+#             */
/*   Updated: 2025/05/28 17:08:33 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	_rawBits;
		static const int	_fractionalBits;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed	&operator=(const Fixed& other);
		~Fixed();

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
