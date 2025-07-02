/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:03:02 by jolivare          #+#    #+#             */
/*   Updated: 2025/02/28 11:36:13 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) :  _name("Default"), _signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "Default form constructor called" << std::endl;
}

Form::Form(const Form &src): _name(src.getName() + "_copy"), _signed(src.isSigned()), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	std::cout << "Form copy constructor called to copy " << src.getName() << " into " << this->getName() << std::endl;
	*this = src;
}

Form::Form(int sign_grade, int exec_grade): _name("default"), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Form constructor called for " << this->_name << " with a signing grade of " << _sign_grade << " and an execution grade of " << _exec_grade << std::endl;
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if (i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(const std::string name): _name(name), _signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "Only name constructor called for " << this->getName() << " with a signing grade of " << _sign_grade << " and an execution grade of " << _exec_grade << std::endl;
}

Form::Form(const std::string name, int sign_grade, int exec_grade): _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Complete constructor called for " << this->_name << " with a signing grade of " << _sign_grade << "and an execution grade of " << _exec_grade << std::endl;
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if (i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}
Form::~Form(void)
{
	std::cout << "Default form deconstructor called for " << this->getName() << " called" << std::endl;
}

Form &Form::operator=(const Form &src)
{
	std::cout << "Form assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

void Form::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() > this->getSignGrade())
		throw(Form::GradeTooLowException());
	else if (this->isSigned() == false)
	{
		this->_signed = true;
		std::cout << this->getName() << " form has been signed by " << signer.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " form has already been signed" << std::endl;
}

const std::string Form::getName(void)const
{
	return (this->_name);
}

bool Form::isSigned(void)const
{
	return (this->_signed);
}

int Form::getSignGrade(void)const
{
	return (this->_sign_grade);
}

int Form::getExecGrade(void)const
{
	return (this->_exec_grade);
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &o, const Form &a)
{
	o << "Form "<< a.getName() << ":\n\tsign grade: " << a.getSignGrade() << "\n\texec grade: " << a.getExecGrade() << std::endl;
	if (a.isSigned() == true)
		o << "\tis signed: true" << std::endl;
	else if (a.isSigned() == false)
		o << "\tis signed: false" << std::endl;
	return (o);
}

