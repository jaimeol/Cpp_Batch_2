/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:46:58 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/14 16:45:22 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string _name;
		bool _signed;
		const int _sign_grade;
		const int _exec_grade;
		
		AForm(void);
		AForm(int sign_grade, int exec_grade);
		AForm(const std::string name);
		AForm(const std::string name, int sign_grade, int exec_grade);
	public:
		AForm(const AForm &src);

		virtual ~AForm(void);

		AForm &operator=(const AForm &src);

		void beSigned(Bureaucrat &signer);
		virtual void execute(Bureaucrat const &executor)const = 0;

		const std::string getName(void)const;
		bool isSigned(void)const;
		int getSignGrade(void)const;
		int getExecGrade(void)const;

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const AForm &a);