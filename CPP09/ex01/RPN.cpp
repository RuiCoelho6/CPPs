/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 08:51:06 by rpires-c          #+#    #+#             */
/*   Updated: 2025/12/10 16:19:40 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

bool RPN::solve(const char *str, int &result)
{
	std::istringstream	iss(str);
	std::string			token;
	
	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error: insufficient operands for operator '" << token << "'" << std::endl;
				return (false);
			}

			int	b = _stack.top();
			_stack.pop();
			int	a = _stack.top();
			_stack.pop();
			int	res;

			if (token == "+")
				res = a + b;
			else if (token == "-")
				res = a - b;
			else if (token == "*")
				res = a * b;
			else if (token == "/")
			{
				if (b == 0)
				{
					std::cerr << "Error: division by zero" << std::endl;
					return (false);
				}
				res = a / b;
			}

			_stack.push(res);
		}
		else
		{
			char	*end;
			errno = 0;
			long	val = std::strtol(token.c_str(), &end, 10);

			if (*end != '\0')
			{
				std::cerr << "Error" << std::endl;
				return (false);
			}
			if (errno == ERANGE || val < 0 || val > 9)
			{
				std::cerr << "Error: number out of valid range (0 to 9): " << val << std::endl;
				return (false);
			}

			_stack.push(static_cast<int>(val));
		}
	}
	
	if (_stack.size() != 1)
	{
		std::cerr << "Error: invalid expression" << std::endl;
		return (false);
	}
	
	result = _stack.top();
	return (true);
}
