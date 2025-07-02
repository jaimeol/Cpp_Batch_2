/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:43:52 by jolivare          #+#    #+#             */
/*   Updated: 2025/02/28 11:40:46 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

 int main(void)
 {
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	Bureaucrat *a = new Bureaucrat();
	Form *b = new Form("Mbappe's contract", 1,1);

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	try
	{
		a->signForm(*b);
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << a->getName() << " is not able to sign " << b->getName() << " form because of excpetion: " << e.what() << std::endl;
	}
	std::cout << *b;
	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	delete a;
	delete b;
	std::cout << "----------------------------------------------------------" << std::endl;

	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	Bureaucrat *c = new Bureaucrat("CEO", 1);
	Form *d = new Form("Mbappe's contract", 1,1);
	Form *l = new Form(*d);
	std::cout << *d;
	std::cout << *l;
	std::cout << "\033[34mTesting\033[0m" << std::endl;
	try
	{
		c->signForm(*d);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << c->getName() << " is not able to sign " << d->getName() << " form because of exception: " << e.what() << std::endl;
	}
	std::cout << *c;
	std::cout << *d;
	std::cout << *l;
	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	delete l;
	delete c;
	delete d;
	std::cout << "----------------------------------------------------------" << std::endl;
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	Bureaucrat *e = new Bureaucrat("CEO", 1);
	Form *f = NULL;
	std::cout << "\033[34mTesting\033[0m" << std::endl;
	try
	{
		f = new Form(110, 145);
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cerr << "Can not create form because of exception: " << e.what() << std::endl;
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cerr << "Can not create form because of exception: " << e.what() << std::endl;
	}
	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	if (f != NULL)
		delete f;
	delete e;
 }