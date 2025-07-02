/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:17:24 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/24 16:22:19 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <list>
#include <stack>
#include <string>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>

class RPN
{
	private:
		std::stack<int> _stack;
		std::list<std::string> _parsed;
	public:
		RPN();
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
		~RPN();

		void parse_input(std::string &input);
		void operate(void);
};