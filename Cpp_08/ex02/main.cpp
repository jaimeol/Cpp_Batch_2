/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42mad.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:09:41 by jolivare          #+#    #+#             */
/*   Updated: 2025/06/09 16:58:52 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <iostream>

#if 0
int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Mutant stack top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Mutant stack top after pop: " << mstack.top() << std::endl;
	std::cout << "Mutant stack size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
#endif


#if 0
int main()
{
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << "List top: " << list.back() << std::endl;
	list.pop_back();
	std::cout << "List top after pop: " << list.back() << std::endl;
	std::cout << "List size: " << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}
#endif

#if 1
int main(void)
{
	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	mstack.push(6);
	
	std::cout << "Normal iterators (begin -> end)" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << *it <<  " ";
	}
	std::cout << std::endl;
	
	std::cout << "Normal const iterator (begin -> end without modifying)" << std::endl;
	for (MutantStack<int>::const_iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << *it <<  " ";
	}
	std::cout << std::endl;
	
	std::cout << "Reverse iterator (end -> begin)"  << std::endl;
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit !=  mstack.rend(); ++rit)
	{
		std::cout << *rit << " ";
	}
	std::cout << std::endl;

	std::cout << "Reverse const iterator (end -> begin without modifying)" << std::endl;
	for (MutantStack<int>::const_reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
	{
		std::cout << *rit << " ";
	}
	std::cout << std::endl;

	return 0;
}
#endif