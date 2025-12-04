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
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _exchangeRates(other._exchangeRates) {}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_exchangeRates = other._exchangeRates;

	return (*this);
}

std::string	BitcoinExchange::trim(const std::string &str) const
{
	size_t	first = str.find_first_not_of(" \t\r\n");

	if (first == std::string::npos)
		return ("");
	size_t	last = str.find_last_not_of(" \t\r\n");

	return (str.substr(first, last - first + 1));
}

bool	BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);

	for (size_t i = 0; i < date.length(); ++i)
	{
		if (i != 4 && i != 7 && !isdigit(date[i]))
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

bool	BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const
{
	char	*end;
	value = strtof(valueStr.c_str(), &end);

	if (*end != '\0' && *end != '\n' && *end != '\r')
		return (false);

	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}

	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}

	return (true);
}

std::string	BitcoinExchange::findClosestDate(const std::string &date) const
{
	std::map<std::string, float>::const_iterator	it = _exchangeRates.lower_bound(date);

	if (it == _exchangeRates.end() || it->first != date)
	{
		if (it == _exchangeRates.begin())
			return ("");
		--it;
	}

	return (it->first);
}

bool	BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream	file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return (false);
	}

	std::string	line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		size_t	commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue ;

		std::string	date = trim(line.substr(0, commaPos));
		std::string	rateStr = trim(line.substr(commaPos + 1));

		if (!isValidDate(date))
			continue ;

		float rate = strtof(rateStr.c_str(), NULL);
		_exchangeRates[date] = rate;
	}

	file.close();
	return (true);
}

void	BitcoinExchange::processInputFile(const std::string &filename)
{
	std::ifstream	file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}

	std::string	line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		size_t	pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cout << "Error: bad input => " << trim(line) << std::endl;
			continue ;
		}

		std::string	date = trim(line.substr(0, pipePos));
		std::string	valueStr = trim(line.substr(pipePos + 1));

		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue ;
		}

		float	value;
		if (!isValidValue(valueStr, value))
			continue ;

		std::string	closestDate = findClosestDate(date);
		if (closestDate.empty())
		{
			std::cout << "Error: no exchange rate available for date." << std::endl;
			continue ;
		}

		float	rate = _exchangeRates[closestDate];
		float	result = value * rate;
		
		std::cout << date << " => " << value << " = " << result << std::endl;
	}

	file.close();
}