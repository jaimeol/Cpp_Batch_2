/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:58:32 by jolivare          #+#    #+#             */
/*   Updated: 2025/03/21 12:42:17 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class AForm;

class RobotomyRequestForm: public AForm
{
	private:
		const std::string _target;
		RobotomyRequestForm(void);
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &src);
		~RobotomyRequestForm(void);

		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
		
		void execute(Bureaucrat const &executor)const;
		
		std::string getTarget(void)const;
};

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &a);