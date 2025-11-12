/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:01:27 by rpires-c          #+#    #+#             */
/*   Updated: 2025/11/12 17:01:28 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template<typename T, typename Func>
void	iter(T* array, std::size_t length, Func func)
{
	for (std::size_t i = 0; i < length; ++i)
	{
		func(array[i]);
	}
}

#endif
