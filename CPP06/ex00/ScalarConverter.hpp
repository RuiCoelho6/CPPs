#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <climits>
#include <cfloat>

class ScalarConverter
{
	private:
		// Private constructor to prevent instantiation
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter	&operator=(const ScalarConverter &other);
		~ScalarConverter();

		// Type detection functions
		static bool	isChar(const std::string &str);
		static bool	isInt(const std::string &str);
		static bool	isFloat(const std::string &str);
		static bool	isDouble(const std::string &str);
		static bool	isPseudoLiteral(const std::string &str);

		// Conversion functions
		static void	convertFromChar(char c);
		static void	convertFromInt(int value);
		static void	convertFromFloat(float value);
		static void	convertFromDouble(double value);
		static void	handlePseudoLiteral(const std::string &str);

		// Display functions
		static void	displayChar(double value, bool impossible = false);
		static void	displayInt(double value, bool impossible = false);
		static void	displayFloat(double value, bool impossible = false);
		static void	displayDouble(double value, bool impossible = false);

	public:
		static void	convert(const std::string &str);
};

#endif
