/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:05:45 by rpires-c          #+#    #+#             */
/*   Updated: 2025/05/20 18:47:00 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string	stringToLowerCase(std::string str)
{
	for (char &c: str)
		c = std::toupper(c);
	return (str);
}

int	main(int ac, char **av)
{
	Harl	harl;
	std::string	input;

	if (ac != 2)
	{
		std::cout << "Too many arguments" << std::endl << "Proper format is: " << av[0] << " [level to display]" << std::endl;
		return (1); 
	}
	input = stringToLowerCase(av[1]);
	harl.complain(input);
	return (0);
}