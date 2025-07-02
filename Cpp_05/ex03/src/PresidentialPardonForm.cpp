/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:51:02 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/14 16:45:22 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called for target: " << this->getTarget() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src): AForm(src), _target(src.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor called to copy " << src.getName() << " into " << this->getName();
	*this = src; 
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm deconstructor called for " << this->getName() << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor)const
{
	if (this->getExecGrade() < executor.getGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->isSigned() == false)
		throw(AForm::FormNotSignedException());
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string PresidentialPardonForm::getTarget(void)const
{
	return (this->_target);
}

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &a)
{
	o << "Form "<< a.getName() << ":\n\tsign grade: " << a.getSignGrade() << "\n\texec grade: " << a.getExecGrade() << std::endl;
	if (a.isSigned() == true)
		o << "\tis signed: true" << std::endl;
	else if (a.isSigned() == false)
		o << "\tis signed: false" << std::endl;
	return (o);
}