/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:25:42 by jolivare          #+#    #+#             */
/*   Updated: 2025/02/28 11:20:28 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat *a = new Bureaucrat("Jaime", 1);

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	try
	{
		a->incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Increment of bureaucrat " << a->getName() << " failed because of exception: " << e.what() << std::endl;
	}
	std::cout << *a;
	try
	{
		a->decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Decrement of bureaucrat " << a->getName() << " failed because of exception: " << e.what() << std::endl;
	}
	std::cout << *a;
	try
	{
		a->incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Increment of bureaucrat " << a->getName() << " failed because of exception: " << e.what() << std::endl;
	}
	std::cout << *a;
	delete a;

	std::cout << "-------------------------------------------------------------" << std::endl;

	Bureaucrat *b = new Bureaucrat("Luis");
	
	std::cout << "\033[34mTesting\033[0m" << std::endl;
	try
	{
		b->decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Decrement of bureaucrat " << b->getName() << " failed because of exception: " << e.what() << std::endl;
	}
	std::cout << *b;
	try
	{
		b->incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Increment of bureaucrat " << b->getName() << " failed because of exception: " << e.what() << std::endl;
	}
	std::cout << *b;
	delete b;

	std::cout << "-------------------------------------------------------------" << std::endl;

	Bureaucrat *c = new Bureaucrat();

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	
	try
	{
		c->incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Increment of bureaucrat " << c->getName() << " failed because of exception: " << e.what() << std::endl;
	}
	std::cout << *c;
	try
	{
		c->decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Decrement of bureaucrat " << c->getName() << " failed because of exception: " << e.what() << std::endl;
	}
	std::cout << *c;
	try
	{
		c->incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Increment of bureaucrat " << c->getName() << " failed because of exception: " << e.what() << std::endl;
	}
	std::cout << *c;
	delete c;

	std::cout << "-------------------------------------------------------------" << std::endl;
	
	Bureaucrat *d = NULL;

	std::cout << "\033[34mTesting\033[0m" << std::endl;

	try
	{
		d = new Bureaucrat("Prueba", 151);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Creation of Bureaucrat failed because of exception: " << e.what() << std::endl;
	}
	if (d != NULL)
	{
		std::cout << *d;
		delete d;
	}
}