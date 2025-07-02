/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:40:35 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/18 12:43:57 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

template <typename T>

void swap(T &a, T &b)
{
	T aux = a;
	a = b;
	b = aux; 
}

template <typename T>
T const &min (T const &a, T const &b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

template <typename T>
T const &max (T const &a, T const &b)
{
	if (a <= b)
		return (b);
	else
		return (a);
}
