/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:03:22 by rpires-c          #+#    #+#             */
/*   Updated: 2025/11/18 15:11:52 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::iterator	easyFind(T &container, int value)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::runtime_error("Value not found in container");

	return (it);
}

/* 
//reverse iterator version
template <typename T>
typename T::iterator	easyFind(T &container, int value)
{
	typename T::reverse_iterator rit = std::find(container.rbegin(), container.rend(), value);

	if (rit == container.rend())
		throw std::runtime_error("Value not found in container");

	return (--(rit.base()));
}
*/
