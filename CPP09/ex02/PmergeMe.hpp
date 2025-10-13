/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:13:41 by rpires-c          #+#    #+#             */
/*   Updated: 2025/10/13 12:13:41 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <stdexcept>
#include <sys/time.h>
#include <iomanip>

class PmergeMe
{
	private:
		std::vector<int>	_vecData;
		std::deque<int>		_deqData;

		// Jacobsthal number sequence generation
		static size_t	jacobsthal(size_t n);
		static void	generateJacobsthalSequence(std::vector<size_t> &seq, size_t limit);

		// Vector implementation
		void	mergeInsertSortVector(std::vector<int> &arr);
		void	sortPairsVector(std::vector<std::pair<int, int> > &pairs);
		void	insertionSortVector(std::vector<int> &arr, int value, size_t end);
		size_t	binarySearchVector(const std::vector<int> &arr, int value, size_t end);
		
		// Deque implementation
		void	mergeInsertSortDeque(std::deque<int>& arr);
		void	sortPairsDeque(std::deque<std::pair<int, int> > &pairs);
		void	insertionSortDeque(std::deque<int> &arr, int value, size_t end);
		size_t	binarySearchDeque(const std::deque<int> &arr, int value, size_t end);

	public:
		PmergeMe();
		~PmergeMe();
		
		void	parseInput(int argc, char **argv);
		void	sortVector();
		void	sortDeque();
		
		const std::vector<int>	&getVectorData() const;
		const std::deque<int>	&getDequeData() const;
		
		void	printBefore(const std::vector<int> &data) const;
		void	printAfter(const std::vector<int> &data) const;
};

#endif