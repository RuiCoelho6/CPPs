/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 08:51:20 by rpires-c          #+#    #+#             */
/*   Updated: 2025/10/11 08:51:20 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " '<operation in reverse polish notation>'\n";
		return (1);
	}
	RPN	rpn;
	int	ret = rpn.solve(av[1]);
	std::cout << ret << "\n" << std::endl;
	return (0);
}
