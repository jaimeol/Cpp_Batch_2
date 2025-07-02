/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:51:34 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/14 16:45:22 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("trees.txt")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called for target " << this->getTarget() << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src): AForm("ShrubberyCreationForm", 145, 137), _target(src.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor called to copy " << src.getName() << " into " << this->getName() << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm deconstructor called for " << this->getName() << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)const
{
	if (executor.getGrade() > this->getExecGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->isSigned() == false)
		throw(AForm::FormNotSignedException());
	else
	{
		std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());
		for (int i =0; i < 5; i++)
		{
			outfile <<
		    "     ccee88oo" << std::endl <<
		  "  C8O8O8Q8PoOb o8oo" << std::endl <<
		 " dOB69QO8PdUOpugoO9bD" << std::endl <<
		"CgggbU8OU qOp qOdoUOdcb" << std::endl <<
    		"        6OuU  /p u gcoUodpP" << std::endl <<
    		  "         |||||  /douUP" << std::endl <<
    		   "      |||||" << std::endl <<
    		    "      ||||| " << std::endl <<
    		    "      |||||" << std::endl <<
    		    "    |||||" << std::endl <<
   			"....|||||...." << std::endl <<
			std::endl;
		}
		outfile.close();
	}
}

std::string ShrubberyCreationForm::getTarget(void)const
{
	return (this->_target);
}

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &a)
{
	o << "Form "<< a.getName() << ":\n\tsign grade: " << a.getSignGrade() << "\n\texec grade: " << a.getExecGrade() << std::endl;
	if (a.isSigned() == true)
		o << "\tis signed: true" << std::endl;
	else if (a.isSigned() == false)
		o << "\tis signed: false" << std::endl;
	return (o);
}
