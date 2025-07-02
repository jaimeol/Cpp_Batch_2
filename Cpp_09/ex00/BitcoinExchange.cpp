/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:33:51 by jolivare          #+#    #+#             */
/*   Updated: 2025/06/16 16:18:38 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		this->_map = src._map;
	return (*this);
}

static void trimFrontBack(std::string &str)
{
	str.erase(str.find_last_not_of(' ') + 1);
	str.erase(0, str.find_first_not_of(' '));
}

// static bool isLeapYear(int year)
// {
// 	return (year % 4 == 0 && year % 100 != 0 ) || (year % 400 == 0);
// }

bool BitcoinExchange::validDate(const std::string &date)
{
	const char *format = "%Y-%m-%d";
	struct tm timestamp = {};
	char *end = strptime(date.c_str(), format, &timestamp);

	if (!end || *end != '\0')
		return false;

	struct tm copy = timestamp;
	time_t t = mktime(&copy);
	if (t == -1)
		return false;

	struct tm *check = localtime(&t);
	if (!check)
		return false;

	return (check->tm_year == timestamp.tm_year &&
	        check->tm_mon == timestamp.tm_mon &&
	        check->tm_mday == timestamp.tm_mday);
}


std::string BitcoinExchange::getKey(std::string str, char delimiter)
{
	size_t delimPos = str.find(delimiter);

	if (delimPos == std::string::npos)
		throw std::runtime_error("cannot find delimiter");
	str = str.substr(0, delimPos);
	trimFrontBack(str);
	return (str);
}

float BitcoinExchange::getValue(std::string str, char delimiter)
{
	size_t delimPos = str.find(delimiter);
	if (delimPos == std::string::npos)
		throw std::runtime_error("cannot find delimiter");
	trimFrontBack(str);
	str = str.substr(delimPos + 1, str.size());
	char *ptr;
	float res = strtof(str.c_str(), &ptr);
	if (*ptr)
		throw std::runtime_error("invalid value");
	if (res < 0)
		throw std::runtime_error("not a positive number");
	return (res);
}

void BitcoinExchange::loadDatabase()
{
	std::ifstream database(DATABASE_PATH);
	if (!database.is_open())
		throw std::runtime_error("fatal: cannot open data base");
	std::string line;
	std::getline(database, line);
	while (std::getline(database, line))
	{
		std::string key = BitcoinExchange::getKey(line, ',');
		if (validDate(key) == false)
			throw std::runtime_error("Error parsing data.csv: invalid date");
		float value = BitcoinExchange::getValue(line, ',');
		this->_map[key] = value;
	}
}

void BitcoinExchange::ParseInputValues(std::string &str) const
{
	std::ifstream infile(str.c_str());
	if (!infile.is_open())
		throw std::runtime_error("fatal: cannot open file");
	std::string line;
	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		std::string aux = line.substr(0, line.find("|"));
		trimFrontBack(aux);
		std::cout << aux << "=>";
		try
		{
			std::string key = getKey(line, '|');
			if (!(validDate(key)))
				std::cout << "bad input" << std::endl;
			else
			{
				float value = BitcoinExchange::getValue(line, '|');
				if (value > 1000)
					throw std::runtime_error("number too large");
				std::cout << value << " = " << value * (this->_map.lower_bound(key))->second;
			}
		}
		catch  (std::exception &e)
		{
			std::cout << e.what();
		}
		std::cout << std::endl;
	}
}

void BitcoinExchange::solve(std::string input)
{
	try
	{
		this->loadDatabase();
	}
	catch (std::exception &e)
	{	
		std::cerr << "error while parsing data base (" << e.what() << ")" << std::endl;
		return ;
	}
	try
	{
		this->ParseInputValues(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

const std::map<std::string, double> &BitcoinExchange::getDataBase() const
{
	return (this->_map);
}
