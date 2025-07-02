/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:50:37 by jolivare          #+#    #+#             */
/*   Updated: 2025/03/21 12:46:14 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Bureaucrat.hpp"
#include "inc/AForm.hpp"
#include "inc/PresidentialPardonForm.hpp"
#include "inc/RobotomyRequestForm.hpp"
#include "inc/ShrubberyCreationForm.hpp"

int main(void)
{
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	Bureaucrat *a = new Bureaucrat(1);
	AForm *b = new PresidentialPardonForm("Luis");

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	try
	{
		b->beSigned(*a);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << a->getName() << " is not able to sign " << b->getName() << " because of exception: " << e.what() << std::endl;
	}
	try
	{
		b->execute(*a);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << a->getName() << " is not able to sign " << b->getName() << " because of exception: " << e.what() << std::endl;
	}
	catch (AForm::FormNotSignedException &e)
	{
		std::cerr << a->getName() << " is not able to execute " << b->getName() << " because of exception: " << e.what() << std::endl;
	}
	std::cout << *b;
	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	delete a;
	delete b;
	std::cout << "----------------------------------------------------------" << std::endl;
	
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	Bureaucrat *c = new Bureaucrat(1);
	AForm *d = new ShrubberyCreationForm("Edu");
	std::cout << "\033[34mTesting\033[0m" << std::endl;
	try
	{
		c->signForm(*d);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << c->getName() << " is not able to sign " << d->getName() << " because of exception: " << e.what() << std::endl;
	}
	try
	{
		c->executeForm(*d);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << c->getName() << " is not able to sign " << d->getName() << " because of exception: " << e.what() << std::endl;
	}
	catch (AForm::FormNotSignedException &e)
	{
		std::cerr << c->getName() << " is not able to execute " << d->getName() << " because of exception: " << e.what() << std::endl;
	}
	std::cout << *b;
	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	delete c;
	delete d;
	std::cout << "----------------------------------------------------------" << std::endl;
	
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	Bureaucrat *f = new Bureaucrat("Prueba", 1);
	AForm *g = new RobotomyRequestForm("target");
	try
	{
		f->signForm(*g);
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cerr << f->getName() << " is not able to sign " << g->getExecGrade() << " because of exception " << e.what() << std::endl;
	}
	try
	{
		f->executeForm(*g);
	}
	catch (AForm::FormNotSignedException &e)
	{
		std::cerr << f->getName() << " is not able to execute " << g->getName() << " because of exception " << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << f->getName() << " is not able to execute " << g->getName() << " because of exception " << e.what() << std::endl;
	}
	std::cout << *f;
	std::cout << *g;
	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	delete f;
	delete g;
	std::cout << "----------------------------------------------------------" << std::endl;
}