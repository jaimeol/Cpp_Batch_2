/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:45:19 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/21 18:24:01 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <functional>
#include <numeric>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _vec;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &src);
		Span &operator=(Span &src);
		~Span();

		void addNumber(int num);
		int longestSpan();
		int shortestSpan();
		void addRange(std::vector<int>::iterator first, std::vector<int>::iterator last);
		void printVector();
};