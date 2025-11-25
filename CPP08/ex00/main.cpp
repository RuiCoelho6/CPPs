/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:01:19 by rpires-c          #+#    #+#             */
/*   Updated: 2025/11/25 12:12:50 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int	main()
{
	std::cout << "=== Testing with std::vector ===" << std::endl;
	{
		std::vector<int>	vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);

		try
		{
			std::vector<int>::iterator	it = easyFind(vec, 3);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}

		try
		{
			std::vector<int>::iterator	it = easyFind(vec, 42);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Testing with std::list ===" << std::endl;
	{
		std::list<int>	lst;
		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(30);
		lst.push_back(40);

		try
		{
			std::list<int>::iterator	it = easyFind(lst, 20);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}

		try
		{
			std::list<int>::iterator	it = easyFind(lst, 100);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Testing with std::deque ===" << std::endl;
	{
		std::deque<int>	deq;
		deq.push_back(5);
		deq.push_back(15);
		deq.push_back(25);

		try
		{
			std::deque<int>::iterator	it = easyFind(deq, 15);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}

		try
		{
			std::deque<int>::iterator	it = easyFind(deq, 35);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Testing with empty container ===" << std::endl;
	{
		std::vector<int>	empty;

		try
		{
			std::vector<int>::iterator	it = easyFind(empty, 1);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Testing with duplicate values ===" << std::endl;
	{
		std::vector<int>	vec;
		vec.push_back(7);
		vec.push_back(7);
		vec.push_back(7);

		try
		{
			std::vector<int>::iterator	it = easyFind(vec, 7);
			std::cout << "Found first occurrence: " << *it << std::endl;
			std::cout << "Position: " << (it - vec.begin()) << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	return (0);
}