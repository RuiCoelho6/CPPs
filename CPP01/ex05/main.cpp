/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:05:45 by rpires-c          #+#    #+#             */
/*   Updated: 2025/05/20 18:00:36 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string stringToLowerCase(std::string str)
{
	for (char &c: str)
		c = std::toupper(c);
	return (str);
}

int	main()
{
	Harl	harl;

	std::string input;
	std::cout << "Enter command: ";
	std::cin >> input;
	input = stringToLowerCase(input);
	harl.complain(input);
}