/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:05:54 by rpires-c          #+#    #+#             */
/*   Updated: 2025/10/10 16:53:32 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

std::string	BitcoinExchange::trim(const std::string &str) const
{
	size_t	start = str.find_first_not_of(" \t\n\r");
	if (start == std::string::npos)
		return ("");
	size_t	end = str.find_last_not_of(" \t\n\r");
	return (str.substr(start, end - start + 1));
}

bool	BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);

	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return (false);
	}

	int	year = atoi(date.substr(0, 4).c_str());
	int	month = atoi(date.substr(5, 2).c_str());
	int	day = atoi(date.substr(8, 2).c_str());

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);

	if (month == 2)
	{
		bool	isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (isLeap ? 29 : 28))
			return (false);
	} else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return (false);
	}
	return (true);
}

bool	BitcoinExchange::isValidValue(const std::string &valueStr, float &value) const
{
	char	*end;
	value = strtof(valueStr.c_str(), &end);

	if (*end != '\0' && *end != '\n' && *end != '\r')
		return (false);

	return (true);
}

bool	BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return (false);
	}

	std::string	line;
	bool	firstLine = true;

	while (std::getline(file, line))
	{
		if (firstLine)
		{
			firstLine = false;
			continue ; // Skip header
		}

		size_t	commaPos = line.find(',');
		if (commaPos == std::string::npos)
			commaPos = line.find('|');

		std::string date = trim(line.substr(0, commaPos));
		std::string valueStr = trim(line.substr(commaPos + 1));

		if (!isValidDate(date))
			continue ;

		float	value;
		if (!isValidValue(valueStr, value))
			continue ;

		_priceDatabase[date] = value;
	}

	file.close();
	return (!_priceDatabase.empty());
}

std::string	BitcoinExchange::findClosestDate(const std::string &date) const
{
	std::map<std::string, float>::const_iterator	it = _priceDatabase.lower_bound(date);

	// If exact match found
	if (it != _priceDatabase.end() && it->first == date)
		return (it->first);

	// If we need the lower date, go back one
	if (it == _priceDatabase.begin())
		return ""; // No lower date exists

	it--;
	return (it->first);
}

void	BitcoinExchange::processLine(const std::string &line)
{
	size_t	pipePos = line.find(',');
	if (pipePos == std::string::npos)
			pipePos = line.find('|');
	
	if (pipePos == std::string::npos)
	{
		std::cout << "Error: bad input => " << trim(line) << std::endl;
		return ;
	}

	std::string	date = trim(line.substr(0, pipePos));
	std::string	valueStr = trim(line.substr(pipePos + 1));

	if (!isValidDate(date))
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return ;
	}

	float	value;
	if (!isValidValue(valueStr, value))
	{
		std::cout << "Error: bad input => " << trim(line) << std::endl;
		return ;
	}

	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return ;
	}

	if (value > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return ;
	}

	std::string	closestDate = findClosestDate(date);
	if (closestDate.empty())
	{
		std::cout << "Error: no data available for date => " << date << std::endl;
		return ;
	}

	float	exchangeRate = _priceDatabase[closestDate];
	float	result = value * exchangeRate;

	std::cout << date << " => " << value << " = " << result << std::endl;
}

bool	BitcoinExchange::initialize(const std::string &dbFilename)
{
	return (loadDatabase(dbFilename));
}

void	BitcoinExchange::processInputFile(const std::string &filename)
{
	std::ifstream	file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}

	std::string	line;
	bool	firstLine = true;

	while (std::getline(file, line))
	{
		if (firstLine)
		{
			firstLine = false;
			continue; // Skip header
		}

		processLine(line);
	}

	file.close();
}