/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:05:37 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/18 14:18:16 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

template <typename T>

void iter(T *addr, size_t len, void (*f)(T &a))
{
	if (!addr || !f)
		return ;
	for (size_t i = 0; i < len; i++)
		f(*(addr + i));
}