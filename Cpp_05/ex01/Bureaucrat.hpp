/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:58:33 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/15 09:47:36 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int	_grade;
		void setGrade(int grade);
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(int grade);
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, int grade);
		
		~Bureaucrat();
		
		Bureaucrat &operator=(const Bureaucrat &src);
		
		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(Form &form);

		const std::string getName(void)const;
		int getGrade(void)const;

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
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &a);