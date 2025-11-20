/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:12:15 by rpires-c          #+#    #+#             */
/*   Updated: 2025/11/20 15:13:27 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

template <typename Iterator>
void	Span::addRange(Iterator begin, Iterator end)
{
	for (Iterator it = begin; it != end; ++it)
	{
		if (_numbers.size() >= _maxSize)
			throw SpanFullException();
		_numbers.push_back(*it);
	}
}
