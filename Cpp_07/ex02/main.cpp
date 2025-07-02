#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> a(10);
	try
	{
		std::cout << "INVALID INDEX TEST" << std::endl;
		std::cout << a[-12] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "--------------------------------------" << std::endl;

	try
	{
		std::cout << "EMPTY ARRAY TEST" << std::endl;
		Array<int> b;
		std::cout << b[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "--------------------------------------" << std::endl;

	std::cout << "VALID ARRAY TEST" << std::endl;
	for (size_t i = 0; i < a.size(); i++) a[i] = i;
	for (size_t i = 0; i < a.size(); i++) std::cout << a[i] << " ";
	std::cout << std::endl;
	
	std::cout << "--------------------------------------" << std::endl;

	std::cout << "DEEP COPY TEST" << std::endl;

	Array<int> copy;
	copy = a;
	a[0] = 12;
	std::cout << "A ELEMENTS" << std::endl;
	for (size_t i = 0; i < a.size(); i++) std::cout << a[i] << " ";
	std::cout << std::endl;
	std::cout << "COPY ELEMENTS" << std::endl;
	for (size_t i = 0; i < copy.size(); i++) std::cout << copy[i] << " ";
	std::cout << std::endl;
}