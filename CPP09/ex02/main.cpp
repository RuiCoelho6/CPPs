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

		// Parse input
		pmerge.parseInput(argc, argv);

		// Get original data for printing
		std::vector<int> originalData = pmerge.getVectorData();

		// Print before
		pmerge.printBefore(originalData);

		// Sort with vector and measure time
		double	startVec = getTime();
		pmerge.sortVector();
		double	endVec = getTime();
		double	timeVec = endVec - startVec;

		// Print after
		pmerge.printAfter(pmerge.getVectorData());

		// Sort with deque and measure time
		double	startDeq = getTime();
		pmerge.sortDeque();
		double	endDeq = getTime();
		double	timeDeq = endDeq - startDeq;

		// Print timing results
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


