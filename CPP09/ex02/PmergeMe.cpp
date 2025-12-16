/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:13:34 by rpires-c          #+#    #+#             */
/*   Updated: 2025/12/10 16:26:33 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void	PmergeMe::parseInput(int argc, char **argv)
{
	if (argc < 2)
		throw std::runtime_error("Error: No arguments provided");

	for (int i = 1; i < argc; ++i)
	{
		std::string	arg = argv[i];

		if (arg.empty())
			throw std::runtime_error("Error: Empty argument");

		if (arg[0] == '-')
			throw std::runtime_error("Error: Negative numbers not allowed");

		for (size_t j = 0; j < arg.length(); ++j)
		{
			if (!isdigit(arg[j]))
				throw std::runtime_error("Error: Invalid input");
		}

		char	*end;
		long	num = std::strtol(arg.c_str(), &end, 10);

		if (*end != '\0' || num < 0 || num > 2147483647)
			throw std::runtime_error("Error: Invalid number");

		_vecData.push_back(static_cast<int>(num));
		_deqData.push_back(static_cast<int>(num));
	}

	if (_vecData.empty() || _deqData.empty())
		throw std::runtime_error("Error: Array empty");
}

size_t	PmergeMe::jacobsthal(size_t n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);

	size_t	a = 0;
	size_t	b = 1;
	for (size_t i = 2; i <= n; ++i)
	{
		size_t	temp = b;
		b = b + 2 * a;
		a = temp;
	}

	return (b);
}

void	PmergeMe::generateJacobsthalSequence(std::vector<size_t> &seq, size_t limit)
{
	seq.clear();
	size_t	idx = 3;

	while (true)
	{
		size_t	j = jacobsthal(idx);
		if (j >= limit)
			break ;
		seq.push_back(j);
		idx++;
	}
}

// Vector implementation
size_t	PmergeMe::binarySearchVector(const std::vector<int> &arr, int value, size_t end)
{
	size_t	left = 0;
	size_t	right = end;

	while (left < right)
	{
		size_t	mid = left + (right - left) / 2;
		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}

	return (left);
}

void	PmergeMe::insertionSortVector(std::vector<int> &arr, int value, size_t end)
{
	size_t	pos = binarySearchVector(arr, value, end);
	arr.insert(arr.begin() + pos, value);
}

void	PmergeMe::sortPairsVector(std::vector<std::pair<int, int> > &pairs)
{
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		for (size_t j = i + 1; j < pairs.size(); ++j)
		{
			if (pairs[i].second > pairs[j].second)
				std::swap(pairs[i], pairs[j]);
		}
	}
}

void	PmergeMe::mergeInsertSortVector(std::vector<int> &arr)
{
	if (arr.size() <= 1)
		return ;

	bool	hasStraggler = (arr.size() % 2 != 0);
	int	straggler = hasStraggler ? arr.back() : 0;

	// Create pairs and ensure larger is second
	std::vector<std::pair<int, int> >	pairs;
	size_t	pairCount = arr.size() / 2;

	for (size_t i = 0; i < pairCount; ++i)
	{
		int	a = arr[2 * i];
		int	b = arr[2 * i + 1];
		if (a > b)
			pairs.push_back(std::make_pair(b, a));
		else
			pairs.push_back(std::make_pair(a, b));
	}

	// Sort pairs by larger element
	sortPairsVector(pairs);

	// Build main chain with larger elements
	std::vector<int>	mainChain;
	std::vector<int>	pend;

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		mainChain.push_back(pairs[i].second);
		pend.push_back(pairs[i].first);
	}

	// Insert first pend element at beginning
	if (!pend.empty())
	{
		mainChain.insert(mainChain.begin(), pend[0]);

		// Insert remaining pend elements using Jacobsthal sequence
		std::vector<size_t>	jacobSeq;
		generateJacobsthalSequence(jacobSeq, pend.size());

		std::vector<bool>	inserted(pend.size(), false);
		inserted[0] = true;

		size_t	lastIdx = 1;
		for (size_t i = 0; i < jacobSeq.size(); ++i)
		{
			size_t	currIdx = jacobSeq[i];

			// Insert from currIdx down to lastIdx
			for (size_t j = currIdx; j >= lastIdx && j > 0; --j)
			{
				if (!inserted[j])
				{
					insertionSortVector(mainChain, pend[j], mainChain.size());
					inserted[j] = true;
				}
			}
			lastIdx = currIdx + 1;
		}

		// Insert any remaining elements
		for (size_t i = lastIdx; i < pend.size(); ++i)
		{
			if (!inserted[i])
			{
				insertionSortVector(mainChain, pend[i], mainChain.size());
			}
		}
	}

	// Insert straggler if exists
	if (hasStraggler)
	{
		insertionSortVector(mainChain, straggler, mainChain.size());
	}

	arr = mainChain;
}

void	PmergeMe::sortVector()
{
	mergeInsertSortVector(_vecData);
}

// Deque implementation
size_t	PmergeMe::binarySearchDeque(const std::deque<int> &arr, int value, size_t end)
{
	size_t	left = 0;
	size_t	right = end;

	while (left < right)
	{
		size_t	mid = left + (right - left) / 2;
		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

void	PmergeMe::insertionSortDeque(std::deque<int> &arr, int value, size_t end)
{
	size_t	pos = binarySearchDeque(arr, value, end);
	arr.insert(arr.begin() + pos, value);
}

void	PmergeMe::sortPairsDeque(std::deque<std::pair<int, int> > &pairs)
{
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		for (size_t j = i + 1; j < pairs.size(); ++j)
		{
			if (pairs[i].second > pairs[j].second)
			{
				std::swap(pairs[i], pairs[j]);
			}
		}
	}
}

void	PmergeMe::mergeInsertSortDeque(std::deque<int> &arr)
{
	if (arr.size() <= 1)
		return ;

	bool	hasStraggler = (arr.size() % 2 != 0);
	int	straggler = hasStraggler ? arr.back() : 0;

	// Create pairs and ensure larger is second
	std::deque<std::pair<int, int> >	pairs;
	size_t	pairCount = arr.size() / 2;

	for (size_t i = 0; i < pairCount; ++i)
	{
		int	a = arr[2 * i];
		int	b = arr[2 * i + 1];
		if (a > b)
			pairs.push_back(std::make_pair(b, a));
		else
			pairs.push_back(std::make_pair(a, b));
	}

	// Sort pairs by larger element
	sortPairsDeque(pairs);

	// Build main chain with larger elements
	std::deque<int>	mainChain;
	std::deque<int>	pend;

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		mainChain.push_back(pairs[i].second);
		pend.push_back(pairs[i].first);
	}

	// Insert first pend element at beginning
	if (!pend.empty())
	{
		mainChain.insert(mainChain.begin(), pend[0]);

		// Insert remaining pend elements using Jacobsthal sequence
		std::vector<size_t>	jacobSeq;
		generateJacobsthalSequence(jacobSeq, pend.size());

		std::vector<bool> inserted(pend.size(), false);
		inserted[0] = true;

		size_t	lastIdx = 1;
		for (size_t i = 0; i < jacobSeq.size(); ++i)
		{
			size_t	currIdx = jacobSeq[i];

			// Insert from currIdx down to lastIdx
			for (size_t j = currIdx; j >= lastIdx && j > 0; --j)
			{
				if (!inserted[j])
				{
					insertionSortDeque(mainChain, pend[j], mainChain.size());
					inserted[j] = true;
				}
			}
			lastIdx = currIdx + 1;
		}

		// Insert any remaining elements
		for (size_t i = lastIdx; i < pend.size(); ++i)
		{
			if (!inserted[i])
			{
				insertionSortDeque(mainChain, pend[i], mainChain.size());
			}
		}
	}

	// Insert straggler if exists
	if (hasStraggler)
	{
		insertionSortDeque(mainChain, straggler, mainChain.size());
	}

	arr = mainChain;
}

void	PmergeMe::sortDeque()
{
	mergeInsertSortDeque(_deqData);
}

const std::vector<int>	&PmergeMe::getVectorData() const
{
	return (_vecData);
}

const std::deque<int>	&PmergeMe::getDequeData() const
{
	return (_deqData);
}

void	PmergeMe::printArray(const std::vector<int> &data, std::string beforeOrAfter) const
{
	std::string	out = (beforeOrAfter == "After") ? "After" : "Before";
	std::cout << out << ": ";
	size_t	limit = std::min(data.size(), static_cast<size_t>(5));
	for (size_t i = 0; i < limit; ++i)
	{
		std::cout << data[i];
		if (i < limit - 1)
			std::cout << " ";
	}
	if (data.size() > 5)
		std::cout << " [...]";
	std::cout << std::endl;
}
