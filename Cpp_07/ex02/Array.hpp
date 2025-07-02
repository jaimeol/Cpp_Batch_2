/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:23:44 by jolivare          #+#    #+#             */
/*   Updated: 2025/06/05 20:03:27 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>
#include <exception>
#include <iostream>

template <class T>

class Array
{
	private:
		T *_array;
		unsigned int _size;
	public:
		Array()
		{
			this->_array = new T[0];
			this->_size = 0;
		}
		
		~Array()
		{
			delete[] this->_array;
		}
		
		Array(unsigned int n)
		{
			this->_array = new T[n];
			if (!this->_array)
			{
				std::cerr << "fatal: can not allocate memory" << std::endl;
				return;
			}
			this->_size = n;
		}
		
		Array(const Array &other)
		{
			this->_array = new T[other._size];
			for (size_t i = 0; i < other._size; i++)
				this->_array[i] = other._array[i];
			this->_size = other._size;
		}
		
		Array &operator=(const Array &rhs)
		{
			delete[] this->_array;
			this->_array = new T[rhs._size];
			for (size_t i = 0; i < rhs._size; i++)
				this->_array[i] = rhs._array[i];
			this->_size = rhs._size;
			return (*this);
		}	
		T &operator[](int i)
		{
			if (i < 0 || (unsigned int) i >= this->_size)
			{
				throw std::runtime_error("fatal: index out of bounds");
				return (this->_array[0]);
			}
			return (this->_array[i]);
		}
		unsigned int size()
		{
			return (this->_size);
		}
};
