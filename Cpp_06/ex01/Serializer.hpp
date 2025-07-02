/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:01:16 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/15 17:08:11 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include <iostream>

typedef struct 
{
	char *ptr;
} Data;

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer &src);
		Serializer &operator=(const Serializer &src);
		~Serializer();
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};