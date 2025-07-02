/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:51:20 by jolivare          #+#    #+#             */
/*   Updated: 2025/03/21 12:53:05 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called for target " << this->getTarget() << std::endl; 
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src): AForm("RobotomyRequestForm", 72, 45), _target(src.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called to copy " << src.getName() << " into " << this->getName();
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequest deconstructor called for " << this->getName() << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
	if (executor.getGrade() > this->getExecGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->isSigned() == false)
		throw(AForm::FormNotSignedException());
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << "**intense machine noises**\n" << this->getTarget() << " was robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}

std::string RobotomyRequestForm::getTarget(void)const
{
	return (this->_target);
}

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &a)
{
	o << "Form "<< a.getName() << ":\n\tsign grade: " << a.getSignGrade() << "\n\texec grade: " << a.getExecGrade() << std::endl;
	if (a.isSigned() == true)
		o << "\tis signed: true" << std::endl;
	else if (a.isSigned() == false)
		o << "\tis signed: false" << std::endl;
	return (o);
}
