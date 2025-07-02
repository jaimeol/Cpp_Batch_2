/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:55:41 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/15 09:45:53 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Default constructor called for " << this->getName() << " with a grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName() + "_copy")
{
	std::cout << "Default copy constructor called for " << src.getName() << " into " << this->getName() << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Default bureaucrat deconstructor called for " << this->getName() << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("Default")
{
	std::cout << "Bureaucrat constructor called for " << this->getName() << " with a grade of " << grade << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(150)
{
	std::cout << "Bureaucrat constructor called for " << this->getName() << " with a grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor called for " << this->getName() << " with a grade of " << grade << std::endl;
	this->setGrade(grade);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_grade = src.getGrade();
	return (*this);
}

void Bureaucrat::incrementGrade(void)
{
	std::cout << "Trying to increment grade of " << this->getName() << std::endl;
	this->setGrade(this->_grade - 1);
}

void Bureaucrat::decrementGrade(void)
{
	std::cout << "Trying to decrement grade of " << this->getName() << std::endl;
	this->setGrade(this->_grade + 1);
}

void Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm &form)
{
	form.execute(*this);
}

const std::string Bureaucrat::getName(void) const
{
	return(this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &a)
{
	o << "Bureaucrat " << a.getName() << ":\n\tgrade: " << a.getGrade() << std::endl;
	return (o);
}
