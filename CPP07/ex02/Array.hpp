/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:02:15 by rpires-c          #+#    #+#             */
/*   Updated: 2025/11/04 15:08:34 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template<typename T>
class Array
{
	private:
		T	*_elements;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T>& other);
		Array<T>	&operator=(const Array<T>& other);
		~Array();
		
		T	&operator[](unsigned int index);
		const T	&operator[](unsigned int index) const;

		unsigned int size() const;

		class IndexOutOfBounds : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

#include "Array.tpp"

#endif
