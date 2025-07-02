/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:12:01 by jolivare          #+#    #+#             */
/*   Updated: 2025/06/09 17:22:00 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	Span A = Span(10);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest and longest span test" << std::endl;
	std::cout << "Shortest span: "<< sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	std::cout << "-------------------------------" << std::endl;
	try
	{
		std::cout << "Adding an element to a full span test" << std::endl;
		std::cout << "Lets add a vector full of 1 to the A span" << std::endl;
		std::vector<int> prueba(10, 1);
		A.addRange(prueba.begin(), prueba.end());
		std::cout << "a span vector: ";
		A.printVector();
		std::cout << "Vector added successfully" << std::endl;
		std::cout << "Now lets try to add the number 10: ";
		A.addNumber(10);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------" << std::endl;
	try
	{
		std::cout << A.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}