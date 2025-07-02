/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:09:23 by jolivare          #+#    #+#             */
/*   Updated: 2025/06/16 15:39:47 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, const char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return (1);
	}
	
	PmergeMe m = PmergeMe();
	
	try
	{
		m.parse_input(argv + 1);
		// std::cout << "Vector before: ";
		// m.print_input(VECTOR);
		// std::cout << "Deque before: ";
		// m.print_input(DEQUE);
		double vector_time = m.displayVectorTimeStamp();
		double deque_time = m.displayDequeTimeStamp();
		// std::cout << "Vector after: ";
		// m.print_input(VECTOR);
		// std::cout << "Deque after: ";
		// m.print_input(DEQUE);
		std::cout << "Time to process a range of " << argc - 1 << " with std::vector : " << vector_time << " us" << std::endl;
		std::cout << "Time to process a range of " << argc - 1 << " with std::deque : " << deque_time << " us" <<std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (2);
	}
	return (0);
}