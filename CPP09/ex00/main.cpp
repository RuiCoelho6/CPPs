/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:34:20 by rpires-c          #+#    #+#             */
/*   Updated: 2025/12/10 14:12:08 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;

		return (1);
	}

	BitcoinExchange	exchange;

	std::string	databaseFile = (argc == 3) ? argv[2] : "data.csv";

	if (!exchange.loadDatabase(databaseFile))
		return (1);

	exchange.processInputFile(argv[1]);

	return (0);
}
