/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:02:22 by jolivare          #+#    #+#             */
/*   Updated: 2025/06/09 17:26:31 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>

template <typename T>

typename T::iterator easyfind(T &array, int toFind)
{
	typename T::iterator it = std::find(array.begin(), array.end(), toFind);
	if (it == array.end() && *it != toFind)
		throw std::runtime_error("Cannot find element in container");
	return (it);
}