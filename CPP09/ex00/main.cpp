/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:34:20 by rpires-c          #+#    #+#             */
/*   Updated: 2025/10/09 15:21:41 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <csv_file>/<txt_file>\n";
		return (1);
	}

	std::string	filename = argv[1];

	if (filename.size() > 4)
	{
		std::string	extension = filename.substr(filename.size() - 4);

		if (!(extension == ".csv" || extension == ".txt"))
		{
			std::cout << "Not a CSV or TXT file\n";
			return (1);
		}
	} else
	{
		std::cout << "String too short\n";
		return (1);
	}

	BitcoinExchange	exchange;

	// Initialize with the database file (you need to provide data.csv)
	if (!exchange.initialize("data.csv"))
	{
		return (1);
	}

	// Process the input file
	exchange.processInputFile(argv[1]);

	return (0);
}
