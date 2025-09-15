#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <value>" << std::endl;
		std::cout << "Examples:" << std::endl;
		std::cout << "  ./convert 0" << std::endl;
		std::cout << "  ./convert 'c'" << std::endl;
		std::cout << "  ./convert 42.0f" << std::endl;
		std::cout << "  ./convert 42.0" << std::endl;
		std::cout << "  ./convert nan" << std::endl;
		std::cout << "  ./convert +inff" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
