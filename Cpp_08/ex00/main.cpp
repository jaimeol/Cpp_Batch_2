/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:21:27 by jolivare          #+#    #+#             */
/*   Updated: 2025/06/09 17:24:17 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::cout << "First we'll use vectors" << std::endl;

	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	try
	{
		std::cout << "to find: 4 :: " << *(easyfind(vec, 4)) << std::endl;
		std::cout << "to find: 1 :: " << *(easyfind(vec, 1)) << std::endl;
		std::cout << "to find: 2 :: " << *(easyfind(vec, 2)) << std::endl;
		std::cout << "to find: 42 :: " << *(easyfind(vec, 42)) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;	
	}

	std::cout << "Now we'll use a list" << std::endl;

	std::list<int> list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	try
	{
		std::cout << "to find: 4 :: " << *(easyfind(list, 4)) << std::endl;
		std::cout << "to find: 1 :: " << *(easyfind(list, 1)) << std::endl;
		std::cout << "to find: 2 :: " << *(easyfind(list, 2)) << std::endl;
		std::cout << "to find: 3 :: " << *(easyfind(list, 3)) << std::endl;
		std::cout << "to find: 42 :: " << *(easyfind(list, 42)) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;	
	}
}