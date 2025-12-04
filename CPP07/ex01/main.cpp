/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:01:24 by rpires-c          #+#    #+#             */
/*   Updated: 2025/11/12 17:01:25 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

void	incrementInt(int &n)
{
	n++;
	std::cout << "Incremented to: " << n << std::endl;
}

void	printInt(const int &n)
{
	std::cout << "Value: " << n << std::endl;
}

void	appendExclamation(std::string &s)
{
	s += "!";
	std::cout << "Modified string: " << s << std::endl;
}

void	printString(const std::string &s)
{
	std::cout << "String: " << s << std::endl;
}

void	printDouble(const double &d)
{
	std::cout << "Double: " << d << std::endl;
}

void	doubleValue(double &d)
{
	d *= 2;
	std::cout << "Doubled to: " << d << std::endl;
}

template<typename T>
void	printGeneric(const T &value)
{
	std::cout << "Generic print: " << value << std::endl;
}

template<typename T>
void	resetToZero(T &value)
{
	value = 0;
	std::cout << "Reset to default: " << value << std::endl;
}

int	main()
{
	int	intArray[] = {1, 2, 3, 4, 5};

	std::cout << "=== Testing iter function template ===" << std::endl;

	// Test 1: Non-const int array with modifying function
	std::cout << "\n1. Testing non-const int array with increment function:" << std::endl;
	std::size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Before increment:" << std::endl;
	iter(intArray, intSize, printInt);

	std::cout << "Incrementing:" << std::endl;
	iter(intArray, intSize, incrementInt);


	// Test 2: Const int array with read-only function
	std::cout << "\n2. Testing const int array with read-only function:" << std::endl;
	const int	constIntArray[] = {10, 20, 30, 40};
	std::size_t constIntSize = sizeof(constIntArray) / sizeof(constIntArray[0]);

	iter(constIntArray, constIntSize, printInt);


	// Test 3: String array with modifying function
	std::cout << "\n3. Testing string array with modifying function:" << std::endl;
	std::string stringArray[] = {"Hello", "World", "Test"};
	std::size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);

	std::cout << "Before modification:" << std::endl;
	iter(stringArray, stringSize, printString);

	std::cout << "Adding exclamations:" << std::endl;
	iter(stringArray, stringSize, appendExclamation);


	// Test 4: Const string array with read-only function
	std::cout << "\n4. Testing const string array with read-only function:" << std::endl;
	const std::string	constStringArray[] = {"Const", "String", "Array"};
	std::size_t	constStringSize = sizeof(constStringArray) / sizeof(constStringArray[0]);

	iter(constStringArray, constStringSize, printString);


	// Test 5: Double array with modifying function
	std::cout << "\n5. Testing double array with modifying function:" << std::endl;
	double	doubleArray[] = {1.1, 2.2, 3.3};
	std::size_t	doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);

	std::cout << "Before doubling:" << std::endl;
	iter(doubleArray, doubleSize, printDouble);

	std::cout << "Doubling values:" << std::endl;
	iter(doubleArray, doubleSize, doubleValue);


	// Test 6: Using instantiated function template (const version)
	std::cout << "\n6. Testing with instantiated function template (const):" << std::endl;
	const int	constArray[] = {100, 200, 300};
	std::size_t	constArraySize = sizeof(constArray) / sizeof(constArray[0]);

	iter(constArray, constArraySize, printGeneric<int>);


	// Test 7: Using instantiated function template (non-const version)
	std::cout << "\n7. Testing with instantiated function template (non-const):" << std::endl;
	int	modifyArray[] = {7, 8, 9};
	std::size_t	modifyArraySize = sizeof(modifyArray) / sizeof(modifyArray[0]);

	std::cout << "Before reset:" << std::endl;
	iter(modifyArray, modifyArraySize, printGeneric<int>);

	std::cout << "Resetting to zero:" << std::endl;
	iter(modifyArray, modifyArraySize, resetToZero<int>);


	// Test 8: Empty array (edge case)
	std::cout << "\n8. Testing empty array:" << std::endl;
	int	*emptyArray = NULL;

	iter(emptyArray, 0, printInt); // Should do nothing
	std::cout << "Empty array test completed (no output expected)" << std::endl;


	// Test 9: Single element array
	std::cout << "\n9. Testing single element array:" << std::endl;
	int	singleElement[] = {42};

	iter(singleElement, 1, printInt);

	std::cout << "\n=== All tests completed ===" << std::endl;
	return (0);
}
