/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:42:40 by jolivare          #+#    #+#             */
/*   Updated: 2025/04/10 16:34:44 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.ptr = (char *)"Hello World!";

	uintptr_t ptr = Serializer::serialize(&data);
	std::cout << "Serialized address: " << &ptr << std::endl;
	std::cout << "Serialized value: " << ptr << std::endl;
	Data *deserialized = Serializer::deserialize(ptr);
	std::cout << "Original data pointer address: " << &data << std::endl;
	std::cout << "Deserialized address: " << deserialized << std::endl;
	std::cout << "Original data pointer value: " << data.ptr << std::endl;
	std::cout << "Desearilized value: " << deserialized->ptr << std::endl;
}