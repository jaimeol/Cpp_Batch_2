/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:28:39 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/22 16:54:36 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int print_error()
{
	std::cerr << "usage error: arg must only be the input file" << std::endl;
	return (EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (print_error());
	BitcoinExchange btc = BitcoinExchange();
	btc.solve(argv[1]);
}
