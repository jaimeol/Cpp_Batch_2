/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:20:20 by jolivare          #+#    #+#             */
/*   Updated: 2025/06/12 15:05:45 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &src) : _vector(src._vector), _deque(src._deque){}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		this->_vector = src._vector;
		this->_deque = src._deque;
	}
	return (*this);
}

template <typename T>
static bool sorted(T &input)
{
	if (input.size() <= 1)
		return true;

	typename T::iterator current = input.begin();
	typename T::iterator next = current;
	++next;
	
	while (next != input.end())
	{
		if (*current > *next)
			return false;
		++current;
		++next;
	}
	return (true);
}

static void checkInput(std::string input)
{
	int signCount = 0;

	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == '+')
			signCount++;
		else if (!std::isdigit(input[i]))
			throw std::runtime_error("Invalid input detected: not a number");
		if (signCount > 1)
			throw std::runtime_error("Invalid input detected: more than one sign in one number");
	}
	long result = std::atol(input.c_str());
	if (result > INT_MAX)
		throw std::runtime_error("Invalid input detected: not an integer");
	else if (result < 0)
		throw std::runtime_error("Invalid input detected: negative number");
}

template <typename T>
static void printContainer(T &container)
{
	for(typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		std::cout << *it;
		if (it + 1 == container.end())
			std::cout << std::endl;
		else
			std::cout << " ";
	}
}

void PmergeMe::parse_input(const char **input)
{
	for (int i = 0; input[i]; i++)
	{
		checkInput(input[i]);
		this->_vector.push_back(std::atoi(input[i]));
	}
	this->_deque = std::deque<unsigned int>(this->_vector.begin(), this->_vector.end());
}


static std::vector<size_t> generateJacobsthalIndex(size_t n)
{
	std::vector<size_t> indexes;
	if (n == 0)
		return indexes;
	size_t i = 0, j = 1;
	indexes.push_back(j);
	while (true)
	{
		size_t k = j + 2 * i;
		if (k >= n)
			break;
		indexes.push_back(k);
		i = j;
		j = k;
	}
	return indexes;
}

static void FordJohnsonSort(std::vector<unsigned int> &arr)
{
	if (arr.size() <= 1)
		return ;
	std::vector<unsigned int> mainChain;
	std::vector<unsigned int> pending;

	for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
		if (arr[i] < arr[i + 1])
		{
			mainChain.push_back(arr[i + 1]);
			pending.push_back(arr[i]);
		}
		else
		{
			mainChain.push_back(arr[i]);
			pending.push_back(arr[i + 1]);
		}
	}
	
	if (arr.size() % 2 != 0)
		pending.push_back(arr.back());
	if (mainChain.size() > 1)
		FordJohnsonSort(mainChain);
	
	std::vector<size_t> jacobIndex = generateJacobsthalIndex(pending.size());
	std::vector<bool> inserted(pending.size(), false);

	for (size_t i = 0; i < jacobIndex.size(); ++i)
	{
		size_t index = jacobIndex[i];
		if (index < pending.size() && !inserted[index])
		{
			std::vector<unsigned int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[index]);
			mainChain.insert(pos, pending[index]);
			inserted[index] = true;
		}
	}

	for (size_t i = 0; i < pending.size(); ++i)
	{
		if (!inserted[i])
		{
			std::vector<unsigned int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);
			mainChain.insert(pos, pending[i]);
		}
	}

	arr = mainChain;
}

static void FordJohnsonSort(std::deque<unsigned int> &arr)
{
	if (arr.size() <= 1)
		return ;
	std::deque<unsigned int> mainChain;
	std::deque<unsigned int> pending;

	for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
		if (arr[i] < arr[i + 1])
		{
			mainChain.push_back(arr[i + 1]);
			pending.push_back(arr[i]);
		}
		else
		{
			mainChain.push_back(arr[i]);
			pending.push_back(arr[i + 1]);
		}
	}

	if (arr.size() % 2 != 0)
		pending.push_back(arr.back());
	if (mainChain.size() > 1)
		FordJohnsonSort(mainChain);
	
	std::vector<size_t> jacobIndex = generateJacobsthalIndex(pending.size());
	std::vector<bool> inserted(pending.size(), false);

	for (size_t i = 0; i < jacobIndex.size(); ++i)
	{
		size_t index = jacobIndex[i];
		if (index < pending.size() && !inserted[index])
		{
			std::deque<unsigned int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[index]);
			mainChain.insert(pos, pending[index]);
			inserted[index] = true;
		}
	}
	for (size_t i = 0; i < pending.size(); ++i)
	{
		if (!inserted[i])
		{
			std::deque<unsigned int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);
			mainChain.insert(pos, pending[i]);
		}
	}
	arr = mainChain;
}


void PmergeMe::sortVector()
{
	FordJohnsonSort(this->_vector);
	if (!sorted(this->_vector))
		throw std::runtime_error("Error: Vector not sorted");
}

void PmergeMe::sortDeque()
{
	FordJohnsonSort(this->_deque);
	if (!sorted(this->_deque))
		throw std::runtime_error("Error: Deque not sorted");
}

double PmergeMe::displayVectorTimeStamp()
{
	std::clock_t start = clock();
	this->sortVector();
	std::clock_t end = clock();
	return (double(end - start) / (CLOCKS_PER_SEC / 1000.0));
}

double PmergeMe::displayDequeTimeStamp()
{
	std::clock_t start = clock();
	this->sortDeque();
	std::clock_t end = clock();
	return (double(end - start) / (CLOCKS_PER_SEC / 1000.0));
}

void PmergeMe::print_input(enum containers type)
{
	switch (type)
	{
		case VECTOR:
			printContainer(this->_vector);
			break;
		case DEQUE:
			printContainer(this->_deque);
			break;
	}
}