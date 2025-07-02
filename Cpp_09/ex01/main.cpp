/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:56:40 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/25 10:47:32 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "fatal: invalid arguments" << std::endl;
		std::cerr << "usage: ./RPN [expr]" << std::endl;
		return 1;
	}
	RPN obj = RPN();
	std::string input = argv[1];
	try
	{
		obj.parse_input(input);
		obj.operate();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}