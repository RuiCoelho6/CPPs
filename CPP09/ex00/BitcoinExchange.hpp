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

# include <string>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_exchangeRates;
		
		bool	isValidDate(const std::string &date) const;
		bool	isValidValue(const std::string &valueStr, float &value) const;
		std::string	trim(const std::string &str) const;
		std::string	findClosestDate(const std::string &date) const;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange	&operator=(const BitcoinExchange &other);
		
		bool	loadDatabase(const std::string &filename);
		void	processInputFile(const std::string &filename);
};

#endif
