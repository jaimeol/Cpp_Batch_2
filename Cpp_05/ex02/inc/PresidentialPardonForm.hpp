/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:25:09 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/14 16:45:22 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class AForm;

class PresidentialPardonForm: public AForm
{
	private:
		const std::string _target;
		PresidentialPardonForm(void);
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &src);

		~PresidentialPardonForm(void);
		
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
		
		void execute(Bureaucrat const &executor)const;

		std::string getTarget(void)const;
};

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &a);
