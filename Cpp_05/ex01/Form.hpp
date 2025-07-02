/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:49:36 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/13 00:21:57 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _sign_grade;
		const int _exec_grade;
	public:
		Form(void);
		Form(const Form &src);
		Form(int sign_grade, int exec_grade);
		Form(const std::string name);
		Form(const std::string name, int sign_grade, int exec_grade);

		~Form(void);

		Form &operator=(const Form &src);

		void beSigned(Bureaucrat &signer);

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
};

std::ostream &operator<<(std::ostream &o, const Form &a);