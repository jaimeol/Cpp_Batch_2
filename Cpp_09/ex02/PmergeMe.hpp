/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:16:17 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/25 14:24:10 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <deque>
#include <algorithm>
#include <cctype>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <bits/types/clock_t.h>
#include <string>

#define CHUNK_SIZE 10
enum containers
{
	VECTOR,
	DEQUE
};

class PmergeMe
{
	private:
		std::vector<unsigned int> _vector;
		std::deque<unsigned int> _deque;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

		void parse_input(const char **input);
		void sortVector();
		void sortDeque();
		
		void print_input(enum containers type);

	double displayVectorTimeStamp();
	double displayDequeTimeStamp();
};