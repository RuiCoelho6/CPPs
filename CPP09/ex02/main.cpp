/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:14:05 by rpires-c          #+#    #+#             */
/*   Updated: 2025/10/13 12:14:05 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

double	getTime()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

int	main(int argc, char **argv)
{
	try
	{
		PmergeMe	pmerge;

		pmerge.parseInput(argc, argv);
		std::vector<int> originalData = pmerge.getVectorData();

		// Sort with vector and measure time
		pmerge.printArray(originalData, "Before");

		double	startVec = getTime();
		pmerge.sortVector();
		double	endVec = getTime();
		double	timeVec = endVec - startVec;

		pmerge.printArray(pmerge.getVectorData(), "After");

		// Sort with deque and measure time
		double	startDeq = getTime();
		pmerge.sortDeque();
		double	endDeq = getTime();
		double	timeDeq = endDeq - startDeq;

		std::cout << std::fixed << std::setprecision(5);
		std::cout << "Time to process a range of " << originalData.size() 
				<< " elements with std::vector : " << timeVec << " us" << std::endl;
		std::cout << "Time to process a range of " << originalData.size() 
				<< " elements with std::deque  : " << timeDeq << " us" << std::endl;

	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}


