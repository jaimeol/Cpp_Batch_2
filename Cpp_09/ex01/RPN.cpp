/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:17:15 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/25 11:09:52 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN &src)
{
	this->_stack = src._stack;
	this->_parsed = src._parsed;
}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
	{
		this->_stack = src._stack;
		this->_parsed = src._parsed;
	}
	return (*this);
}

static bool isNum(std::string &input)
{
	int scount = 0;

	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == '+' || input[i] == '-')
			++scount;
		else if (!isdigit(input[i]))
			return (false);
		if (scount > 1)
			return (false);
	}
	if (std::atoi(input.c_str()) == 0 && input != "0")
		return (false);
	return (true);
}

static bool isOperator(std::string &input)
{
	std::string operators[] = {"+", "-", "*", "/"};
	for (int i = 0; i < 4; i++)
	{
		if (operators[i] == input)
			return (true);
	}
	return (false);
}

static void validateInput(std::string &input)
{
	if (isOperator(input))
		return;
	if (!isNum(input))
		throw std::runtime_error("Invalid input");
}

void RPN::parse_input(std::string &input)
{
	std::string token;
	std::stringstream tokenizer(input);

	while (std::getline(tokenizer, token, ' '))
	{
		if (!token.empty())
		{
			validateInput(token);
			this->_parsed.push_back(token);
		}
	}
}

void RPN::operate()
{
	std::list<std::string>::iterator it;
	int a;
	int b;

	for (it = this->_parsed.begin(); it != this->_parsed.end(); it++)
	{
		if (isOperator(*it))
		{
			if (this->_stack.size() < 2)
				throw std::runtime_error("Invalid expression");
			a = this->_stack.top();
			this->_stack.pop();
			b = this->_stack.top();
			this->_stack.pop();
			if (*it == "+")
				this->_stack.push(a + b);
			else if (*it == "-")
				this->_stack.push(b - a);
			else if (*it == "*")
				this->_stack.push(a * b);
			else if (*it == "/")
			{
				if (a == 0)
					throw std::runtime_error("Division by zero");
				this->_stack.push(b / a);
			}
		}
		else
			this->_stack.push(std::atoi((*it).c_str()));
	}
	if (this->_stack.size() != 1)
		throw std::runtime_error("Invalid operation size");
	std::cout << this->_stack.top() << std::endl;
}
