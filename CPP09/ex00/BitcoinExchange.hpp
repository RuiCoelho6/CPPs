/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:05:33 by rpires-c          #+#    #+#             */
/*   Updated: 2025/10/09 15:19:18 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _priceDatabase;
		
		bool	loadDatabase(const std::string &filename);
		bool	isValidDate(const std::string &date) const;
		bool	isValidValue(const std::string &valueStr, float &value) const;
		std::string	findClosestDate(const std::string &date) const;
		void	processLine(const std::string &line);
		std::string	trim(const std::string &str) const;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		
		bool	initialize(const std::string &dbFilename);
		void	processInputFile(const std::string &filename);
	};

#endif