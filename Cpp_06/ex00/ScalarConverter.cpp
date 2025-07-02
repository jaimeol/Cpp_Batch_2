/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:26:19 by jolivare          #+#    #+#             */
/*   Updated: 2025/04/10 16:15:05 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static std::string pseudoLiterals[]=
{
	"-inff",
	"+inff",
	"nanf",
	"-inf",
	"+inf",
	"nan"
};	

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter &src)
{
	(void)src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

static bool isInt(std::string &input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (!std::isdigit(input[i]))
			return (false);		
	}
	return (true);
}

static bool isFloat(std::string &input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == '.')
			continue ;
		else if (i == input.size() - 1 && input[i] == 'f' && std::isdigit(input[i - 1]))
			return (true);
		else if ((!std::isdigit(input[i])) || (i == input.size() - 1 && input[i] != 'f'))
			return (false);
	}
	return (true);
}

static bool isDouble(std::string &input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == '.')
			continue ;
		else if (!std::isdigit(input[i]))
			return (false);
	}
	return (true);
}

static bool isPseudoLiteral(std::string &input)
{
	for (size_t i = 0; i < _PSEUDO_LITERAL_ARRAY_SIZE; i++)
	{
		if (pseudoLiterals[i] == input)
			return (true);
	}
	return (false);
}

enum type ScalarConverter::getType(std::string &input)
{
	if (input.size() == 1 && !std::isdigit(input[0]))
		return (CHAR);
	if (input.find(".") == std::string::npos)
	{
		if (!isInt(input) && !isPseudoLiteral(input))
			return (UNKNOWN);
		else if (isPseudoLiteral(input))
			return PSEUDOLITERAL;
		return (INT);
	}
	if (isFloat(input))
		return (FLOAT);
	else if (isDouble(input))
		return (DOUBLE);
	return UNKNOWN;
}

void ScalarConverter::displayChar(std::string &input)
{
	std::cout << "char: '" << input[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
}

void ScalarConverter::displayInt(std::string &input)
{
	std::string error = "";
	int conversion = std::atoi(input.c_str());
	
	if (!std::isprint(conversion) || !isascii(conversion))
		error = "Non displayable";
	std::cout << "char: ";
	if (error.empty())
		std::cout << static_cast<char>(conversion) << "'" << std::endl;
	else
		std::cout << error << std::endl;
	std::cout << "int: " << conversion << std::endl;
	std::cout << "float: " << static_cast<float>(conversion) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<int>(conversion) << ".0" << std::endl;
}

void ScalarConverter::displayFloat(std::string &input)
{
	std::string error = "";
	int conversion = std::atof(input.c_str());

	if (!std::isprint(conversion) || !isascii(conversion))
		error = "Non displayable";
	std::cout << "char: '";
	if (error.empty())
		std::cout << static_cast<char>(conversion) << "'" << std::endl;
	else
		std::cout << error << std::endl;
	std::cout << "int: " << static_cast<int>(conversion) << std::endl;
	std::cout << "float: " << input << std::endl;
	std::cout << "double: " << static_cast<double>(conversion) << ".0"<< std::endl;
}

void ScalarConverter::displayDouble(std::string &input)
{
	std::string error = "";
	int conversion = std::atof(input.c_str());

	if (!std::isprint(conversion) || !isascii(conversion))
		error = "Non displayable";
	std::cout << "char: '";
	if (error.empty())
		std::cout << static_cast<char>(conversion) << "'" << std::endl;
	else
		std::cout << error << std::endl;
	std::cout << "int: " << static_cast<int>(conversion) << std::endl;
	std::cout << "float: " << input << "f" << std::endl;
	std::cout << "double: " << input << std::endl;
}

void ScalarConverter::displayPseudoLiteral(std::string &input)
{
	int pos;
	int factor;
	std::string float_value;
	std::string double_value;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	for (pos = 0; pos < _PSEUDO_LITERAL_ARRAY_SIZE; pos++)
	{
		if (pseudoLiterals[pos] == input)
			break;
	}
	if (pos >= 3)
	{
		factor = 3;
		float_value = pseudoLiterals[pos - factor];
		double_value = pseudoLiterals[pos];
	}
	else
	{
		factor = -3;
		float_value = pseudoLiterals[pos];
		double_value = pseudoLiterals[pos - factor];
	}
	std::cout << "float: " << float_value << std::endl;
	std::cout << "double: " << double_value << std::endl;
}

void ScalarConverter::displayUnknown(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(std::string &input)
{
	enum type type = ScalarConverter::getType(input);
	
	switch(type)
	{
		case CHAR:
			ScalarConverter::displayChar(input);
			break;
		case INT:
			ScalarConverter::displayInt(input);
			break;
		case DOUBLE:
			ScalarConverter::displayDouble(input);
			break;
		case FLOAT:
			ScalarConverter::displayFloat(input);
			break;
		case PSEUDOLITERAL:
			ScalarConverter::displayPseudoLiteral(input);
			break;
		default:
			ScalarConverter::displayUnknown();
	}
}
