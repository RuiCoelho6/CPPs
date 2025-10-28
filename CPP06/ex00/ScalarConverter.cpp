/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:57:24 by rpires-c          #+#    #+#             */
/*   Updated: 2025/10/14 15:37:38 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &)
{
	std::cout << "ScalarConverter copy constructor" << std::endl;
}
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &)
{
	std::cout << "ScalarConverter assignment operator" << std::endl;
	return (*this);
}
ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor" << std::endl;
}

bool	ScalarConverter::isChar(const std::string &str)
{
	return (str.length() == 3 && str[0] == '\'' && str[2] == '\'' && std::isprint(str[1]));
}

bool	ScalarConverter::isInt(const std::string &str)
{
	size_t start = 0;

	if (str.empty())
		return (false);
	if (str[0] == '+' || str[0] == '-')
		start = 1;
	if (start >= str.length())
		return (false);

	for (size_t i = start; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isFloat(const std::string &str)
{
	size_t	start = 0;
	bool	hasDot = false;
	bool	hasDigit = false;
	std::string	num = str.substr(0, str.length() - 1);

	if (str.length() < 2 || str[str.length() - 1] != 'f')
		return (false);
	if (num.empty())
		return (false);
	if (num[0] == '+' || num[0] == '-')
		start = 1;

	for (size_t i = start; i < num.length(); i++)
	{
		if (num[i] == '.')
		{
			if (hasDot)
				return (false);
			hasDot = true;
		} else if (std::isdigit(num[i]))
		{
			hasDigit = true;
		} else
		{
			return false;
		}
	}
	return (hasDigit && hasDot);
}

bool	ScalarConverter::isDouble(const std::string &str)
{
	size_t	start = 0;
	bool	hasDot = false;
	bool	hasDigit = false;
	if (str.empty())
		return (false);
	if (str[0] == '+' || str[0] == '-')
		start = 1;
	for (size_t i = start; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			if (hasDot)
				return (false);
			hasDot = true;
		} else if (std::isdigit(str[i]))
		{
			hasDigit = true;
		} else
		{
			return (false);
		}
	}
	return (hasDigit && hasDot);
}

bool	ScalarConverter::isPseudoLiteral(const std::string &str)
{
	return (str == "nan" || str == "+inf" || str == "-inf"
			|| str == "nanf" || str == "+inff" || str == "-inff");
}

void	ScalarConverter::displayChar(double value, bool impossible)
{
	std::cout << "char: ";
	if (impossible || std::isnan(value) || std::isinf(value)
		|| value < 0 || value > 127)
	{
		std::cout << "impossible";
	} else if (value < 32 || value > 126)
	{
		std::cout << "Non displayable";
	} else
	{
		std::cout << "'" << static_cast<char>(value) << "'";
	}
	std::cout << std::endl;
}

void	ScalarConverter::displayInt(double value, bool impossible)
{
	std::cout << "int: ";
	if (impossible || std::isnan(value) || std::isinf(value)
		|| value > INT_MAX || value < INT_MIN)
	{
		std::cout << "impossible";
	} else
	{
		std::cout << static_cast<int>(value);
	}
	std::cout << std::endl;
}

void	ScalarConverter::displayFloat(double value, bool impossible)
{
	std::cout << "float: ";
	if (impossible)
	{
		std::cout << "impossible";
	} else if (std::isnan(value))
	{
		std::cout << "nanf";
	} else if (std::isinf(value))
	{
		std::cout << (value > 0 ? "+inff" : "-inff");
	} else
	{
		float f = static_cast<float>(value);
		std::cout << std::fixed << std::setprecision(1) << f << "f";
	}
	std::cout << std::endl;
}

void	ScalarConverter::displayDouble(double value, bool impossible)
{
	std::cout << "double: ";
	if (impossible)
	{
		std::cout << "impossible";
	} else if (std::isnan(value))
	{
		std::cout << "nan";
	} else if (std::isinf(value))
	{
		std::cout << (value > 0 ? "+inf" : "-inf");
	} else
	{
		std::cout << std::fixed << std::setprecision(1) << value;
	}
	std::cout << std::endl;
}

void	ScalarConverter::convertFromChar(char c)
{
	double	value = static_cast<double>(c);

	displayChar(value);
	displayInt(value);
	displayFloat(value);
	displayDouble(value);
}

void	ScalarConverter::convertFromInt(int value)
{
	double	doubleValue = static_cast<double>(value);

	displayChar(doubleValue);
	displayInt(doubleValue);
	displayFloat(doubleValue);
	displayDouble(doubleValue);
}

void	ScalarConverter::convertFromFloat(float value)
{
	double	doubleValue = static_cast<double>(value);

	displayChar(doubleValue);
	displayInt(doubleValue);
	displayFloat(doubleValue);
	displayDouble(doubleValue);
}

void	ScalarConverter::convertFromDouble(double value)
{
	displayChar(value);
	displayInt(value);
	displayFloat(value);
	displayDouble(value);
}

void	ScalarConverter::handlePseudoLiteral(const std::string &str)
{
	double	value;

	if (str == "nan" || str == "nanf")
	{
		value = std::numeric_limits<double>::quiet_NaN();
	} else if (str == "+inf" || str == "+inff")
	{
		value = std::numeric_limits<double>::infinity();
	} else if (str == "-inf" || str == "-inff")
	{
		value = -std::numeric_limits<double>::infinity();
	} else
	{
		return ;
	}
	convertFromDouble(value);
}

void	ScalarConverter::convert(const std::string &str)
{
	if (str.empty())
	{
		std::cout << "Error: Empty string" << std::endl;
		return ;
	}
	if (isPseudoLiteral(str))
	{
		handlePseudoLiteral(str);
	} else if (isChar(str))
	{
		convertFromChar(str[1]);
	} else if (isInt(str))
	{
		std::stringstream ss(str);
		int	value;
		ss >> value;
		if (ss.fail())
		{
			std::cout << "Error: Invalid integer" << std::endl;
			return ;
		}
		convertFromInt(value);
	} else if (isFloat(str))
	{
		std::string	numStr = str.substr(0, str.length() - 1);
		std::stringstream ss(numStr);
		float	value;
		ss >> value;
		if (ss.fail()) {
			std::cout << "Error: Invalid float" << std::endl;
			return ;
		}
		convertFromFloat(value);
	} else if (isDouble(str))
	{
		std::stringstream ss(str);
		double	value;
		ss >> value;
		if (ss.fail())
		{
			std::cout << "Error: Invalid double" << std::endl;
			return ;
		}
		convertFromDouble(value);
	} else
	{
		std::cout << "Error: Invalid input format" << std::endl;
	}
}
