/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:03:18 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/17 12:17:47 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	srand(time(NULL) - rand());
	int res = rand() % 3;

	switch (res)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
	return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C";
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e)
	{
	}
}

int main() {

	Base* a = new A;
	Base* b = new B;
	Base* c = new C;

	std::cout << "ptr | ref" << std::endl;

	identify(a);
	std::cout << "\t";
	identify(*a);
	std::cout << std::endl;
	identify(b);
	std::cout << "\t";
	identify(*b);
	std::cout << std::endl;
	identify(c);
	std::cout << "\t";
	identify(*c);
	std::cout << std::endl;

	std::cout << "Lets test generate()" << std::endl;
	Base* g = generate();
	Base* gg = generate();
	Base* ggg = generate();

	identify(g);
	std::cout << std::endl;
	identify(gg);
	std::cout << std::endl;
	identify(ggg);
	std::cout << std::endl;

	delete a;
	delete b;
	delete c;
	delete g;
	delete gg;
	delete ggg;

	return 0;
}
