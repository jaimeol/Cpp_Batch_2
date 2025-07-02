/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:50:37 by jolivare          #+#    #+#             */
/*   Updated: 2025/03/21 12:57:23 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Bureaucrat.hpp"
#include "inc/AForm.hpp"
#include "inc/PresidentialPardonForm.hpp"
#include "inc/RobotomyRequestForm.hpp"
#include "inc/ShrubberyCreationForm.hpp"
#include "inc/Intern.hpp"

int main(void)
{
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	Intern someRandonIntern;
	Bureaucrat *a = new Bureaucrat("CEO", 1);
	AForm *rff;

	rff = someRandonIntern.makeForm("RobotomyRequestForm", "Bender");
	
	std::cout << "\033[34mTesting\033[0m" << std::endl;
	if (rff)
	{
		try
		{
			a->signForm(*rff);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			a->executeForm(*rff);
		}
		catch(AForm::FormNotSignedException &e)
		{
			std::cerr << a->getName() << " is not able to execute " << rff->getName() << " because of exception: " <<  e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << *rff;
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete rff;
		std::cout << "----------------------------------------------------------" << std::endl;	
	}
	delete a;
}