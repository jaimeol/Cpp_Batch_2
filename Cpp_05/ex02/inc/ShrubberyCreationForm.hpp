/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:06:39 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/14 16:45:22 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class AForm;
class ShrubberyCreationForm: public AForm
{
	private:
		const std::string _target;
		ShrubberyCreationForm(void);
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &src);
		
		~ShrubberyCreationForm(void);
		
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		
		void execute(Bureaucrat const &executor)const;
	
		std::string getTarget(void)const;
};
std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &a);