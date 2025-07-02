/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:30:51 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/22 16:47:16 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <stdexcept>

# define DATABASE_PATH "./data.csv"

class BitcoinExchange
{
	private:
		std::map<std::string, double> _map;

		static bool validDate(const std::string &date);
		static std::string getKey(std::string str, char delimiter);
		static float getValue(std::string str, char delimiter);
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();
		

		void loadDatabase();
		void ParseInputValues(std::string &str) const;
		
		void solve(std::string input);
		
		const std::map<std::string, double> &getDataBase() const;
};
