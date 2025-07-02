/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:48:06 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/21 19:12:55 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <list>
#include <algorithm>
#include <deque>
#include <stack>


template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack<T>(){}
		MutantStack<T>(const MutantStack<T> &src)
		{
			*this = src;
		}
		MutantStack<T> &operator=(const MutantStack &src)
		{
			(void)src;
			return (*this);
		}
		~MutantStack(){}
		
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

		iterator begin()
		{
			return (this->c.begin());
		}
		iterator end()
		{
			return (this->c.end());
		}
		reverse_iterator rbegin()
		{
			return (this->c.rbegin());
		}
		reverse_iterator rend()
		{
			return (this->c.rend());
		}
		const_iterator begin() const
		{
			return (this->c.begin());
		}
		const_iterator end() const
		{
			return (this->c.end());
		}
		const_reverse_iterator rbegin() const
		{
			return (this->c.rbegin());
		}
		const_reverse_iterator rend() const
		{
			return (this->c.rend());
		}
};