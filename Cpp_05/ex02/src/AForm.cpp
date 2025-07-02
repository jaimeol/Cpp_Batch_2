/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:48:23 by jolivare          #+#    #+#             */
/*   Updated: 2025/03/21 12:22:49 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm(void) :  _name("Default"), _signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "Default form constructor called" << std::endl;
}

AForm::AForm(const AForm &src): _name(src.getName() + "_copy"), _signed(src.isSigned()), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	std::cout << "AForm copy constructor called to copy " << src.getName() << " into " << this->getName() << std::endl;
	// *this = src;
}

AForm::AForm(int sign_grade, int exec_grade): _name("default"), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "AForm constructor called for " << this->_name << " with a signing grade of " << _sign_grade << " and an execution grade of " << _exec_grade << std::endl;
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(AForm::GradeTooLowException());
	else if (i < 1 || j < 1)
		throw(AForm::GradeTooHighException());
}

AForm::AForm(const std::string name): _name(name), _signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "Only name constructor called for " << this->getName() << " with a signing grade of " << _sign_grade << " and an execution grade of " << _exec_grade << std::endl;
}

AForm::AForm(const std::string name, int sign_grade, int exec_grade): _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Complete constructor called for " << this->_name << " with a signing grade of " << _sign_grade << " and an execution grade of " << _exec_grade << std::endl;
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(AForm::GradeTooLowException());
	else if (i < 1 || j < 1)
		throw(AForm::GradeTooHighException());
}
AForm::~AForm(void)
{
	std::cout << "Default form deconstructor called for " << this->getName() << " called" << std::endl;
}

AForm &AForm::operator=(const AForm &src)
{
	std::cout << "AForm assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

void AForm::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() > this->getSignGrade())
		throw(AForm::GradeTooLowException());
	else if (this->isSigned() == false)
	{
		this->_signed = true;
		std::cout << this->getName() << " form has been signed by " << signer.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " form has already been signed" << std::endl;
}

void AForm::execute(Bureaucrat const &executor)const
{
	(void)executor;
}

const std::string AForm::getName(void)const
{
	return (this->_name);
}

bool AForm::isSigned(void)const
{
	return (this->_signed);
}

int AForm::getSignGrade(void)const
{
	return (this->_sign_grade);
}

int AForm::getExecGrade(void)const
{
	return (this->_exec_grade);
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form has not been signed");
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &o, const AForm &a)
{
	o << "AForm "<< a.getName() << ":\n\tsign grade: " << a.getSignGrade() << "\n\texec grade: " << a.getExecGrade() << std::endl;
	if (a.isSigned() == true)
		o << "\tis signed: true" << std::endl;
	else if (a.isSigned() == false)
		o << "\tis signed: false" << std::endl;
	return (o);
}

