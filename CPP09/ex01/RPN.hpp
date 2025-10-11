/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 08:51:14 by rpires-c          #+#    #+#             */
/*   Updated: 2025/10/11 08:51:14 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cerrno>
#include <climits>

class RPN
{
	private:
		std::stack<int>	_stack;
	public:
		RPN();
		~RPN();

		int	solve(const char *str);
};

#endif