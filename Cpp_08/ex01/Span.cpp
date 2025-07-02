/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:51:46 by jolivare          #+#    #+#             */
/*   Updated: 2025/06/09 17:19:37 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void): _N(0){}

Span::Span(unsigned int n): _N(n){}

Span::Span(const Span &src): _N(src._N), _vec(src._vec){}

Span::~Span(void){}

Span &Span::operator=(Span &src)
{
	std::cout << "Span assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_N = src._N;
		this->_vec = src._vec;
	}
	return (*this);
}

void Span::addNumber(int num)
{
	if (this->_vec.size() + 1 > this->_N)
		throw std::runtime_error("Span is full");
	this->_vec.push_back(num);
}

int Span::longestSpan(void)
{
	if (this->_vec.size() <= 1)
		throw std::runtime_error("Cannot detect span");
	std::vector<int> aux = this->_vec;
	std::sort(aux.begin(), aux.end());
	return(aux.back() - aux.front());
}

int Span::shortestSpan(void)
{
	if (this->_vec.size() <= 1)
		throw std::runtime_error("Cannot detect span");
	std::vector<int> aux = this->_vec;
	std::sort(aux.begin(), aux.end());
	if (this->_vec.size() == 2)
		return (this->longestSpan());
	int shortestSpan = aux[1] - aux[0];
	int currSpan = shortestSpan;
	for (std::vector<int>::iterator it = aux.begin() + 1; it != aux.end(); it++)
	{
		currSpan = *it - *(it -1);
		if (currSpan < shortestSpan)
			shortestSpan = currSpan;
	}
	return (shortestSpan);
}

void Span::addRange(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	if ((unsigned int)std::distance(first, last) > this->_N - this->_vec.size())
		throw std::runtime_error("Cannot bulk insert into span");
	for(; first != last; first++)
	{
		this->addNumber(*first);
	}
}

static void printElem(int n)
{
	std::cout << n << " ";
}

void Span::printVector()
{
	std::for_each(this->_vec.begin(), this->_vec.end(), &printElem);
	std::cout << std::endl;
}
