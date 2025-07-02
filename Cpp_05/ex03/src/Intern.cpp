/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:55:04 by jolivare          #+#    #+#             */
/*   Updated: 2025/02/28 11:53:40 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern &src)
{
	std::cout << "Intern copy constructor" << std::endl;
	*this = src;	
}

Intern::~Intern(void)
{
	std::cout << "Intern deconstructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	std::cout << "Intern assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

static AForm *makePresidential(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *makeRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makeForm(const std::string form_name, std::string form_target)
{
	AForm *(*all_forms[])(const std::string target) = {&makePresidential, &makeShrubbery, &makeRobotomy};
	std::string forms[] = {"PresidentialPardonForm", "ShrubberyCreationForm", "RobotomyRequestForm"};
	for (int i = 0; i < 3; i++)
	{
		if (form_name == forms[i])
		{
			std::cout << "Intern creates " << form_name << " now" << std::endl;
			return (all_forms[i](form_target));
		}
	}
	std::cout << "Intert can not create a form called " << form_name << std::endl;
	return (NULL);
}
