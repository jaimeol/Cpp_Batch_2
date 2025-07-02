/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:02:36 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/15 13:01:17 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <cctype>
#include <exception>
#include <iostream>
#include <string>

enum type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDOLITERAL,
	UNKNOWN,
};

#define _PSEUDO_LITERAL_ARRAY_SIZE 6

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter();
		
		static enum type getType(std::string &input);
		
		static void displayChar(std::string &input);
		static void displayInt(std::string &input);
		static void displayFloat(std::string &input);
		static void displayDouble(std::string &input);
		static void displayPseudoLiteral(std::string &input);
		
		static void displayUnknown();
	
	public:
		static void convert(std::string &input);
};
