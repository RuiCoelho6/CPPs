/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:01:17 by rpires-c          #+#    #+#             */
/*   Updated: 2025/11/12 17:01:18 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int	main()
{
	std::cout << "=== Test 1: Default constructor ===" << std::endl;
	Array<int>	empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;

	std::cout << "\n=== Test 2: Construct with size ===" << std::endl;
	Array<int>	numbers(5);
	std::cout << "Numbers array size: " << numbers.size() << std::endl;
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		numbers[i] = i * 10;
	}
	std::cout << "Numbers contents: ";
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "\n=== Test 3: Copy constructor ===" << std::endl;
	Array<int>	copy(numbers);
	std::cout << "Copy contents: ";
	for (unsigned int i = 0; i < copy.size(); i++)
	{
		std::cout << copy[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "\n=== Test 4: Assignment operator ===" << std::endl;
	Array<int>	assigned;
	assigned = numbers;
	std::cout << "Assigned contents: ";
	for (unsigned int i = 0; i < assigned.size(); i++)
	{
		std::cout << assigned[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "\n=== Test 5: Modify original, check copy stays same ===" << std::endl;
	numbers[0] = 999;
	std::cout << "Numbers[0] = " << numbers[0] << std::endl;
	std::cout << "Copy[0]    = " << copy[0] << std::endl;

	std::cout << "\nAll tests complete!" << std::endl;
	return (0);
}
