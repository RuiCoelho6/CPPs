/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 08:51:06 by rpires-c          #+#    #+#             */
/*   Updated: 2025/10/11 08:51:06 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

int	RPN::solve(const char *str)
{
	std::istringstream	iss(str);
	std::string	token;

	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error: insufficient operands for operator '" << token << "'\n";
				return (1);
			}
			
			// Pop two operands (note the order!)
			int	b = _stack.top();
			_stack.pop();
			int	a = _stack.top();
			_stack.pop();
			
			int result;
			if (token == "+")
				result = a + b;
			else if (token == "-")
				result = a - b;
			else if (token == "*")
				result = a * b;
			else if (token == "/")
			{
				if (b == 0)
				{
					std::cerr << "Error: division by zero\n";
					return (1);
				}
				result = a / b;
			}
			_stack.push(result);
		}
		else
		{
			// Try to parse as number
			char	*end;
			errno = 0;
			long	val = std::strtol(token.c_str(), &end, 10);

			if (*end != '\0')
			{
				std::cerr << "Error: invalid token '" << token << "'\n";
				return (1);
			}
			if (errno == ERANGE || val < 0 || val > 9)
			{
				std::cerr << "Error: number out of valid range (0 to 9): " << val << "\n";
				return (1);
			}
			_stack.push(static_cast<int>(val));
		}
	}
	return (_stack.top());
}
