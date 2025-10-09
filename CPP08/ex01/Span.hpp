/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:00:23 by rpires-c          #+#    #+#             */
/*   Updated: 2025/10/09 12:13:28 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
	private:
		unsigned int	_maxSize;
		std::vector<int>	_numbers;
		Span();

	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span	&operator=(const Span &other);
		~Span();

		void	addNumber(int number);
		template <typename Iterator>
		void	addRange(Iterator begin, Iterator end);

		int	shortestSpan() const;
		int	longestSpan() const;

		class SpanFullException : public std::exception
		{
		public:
			virtual const char	*what() const throw();
		};

		class NoSpanException : public std::exception
		{
		public:
			virtual const char	*what() const throw();
		};
};

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

#endif