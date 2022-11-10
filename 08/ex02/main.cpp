/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:19:27 by hrings            #+#    #+#             */
/*   Updated: 2022/10/25 08:57:29 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

void subject_test();
void subject_test_list();
void iter_test();

int main(void)
{
	subject_test();
	subject_test_list();
	iter_test();
	return 0;
}

void subject_test()
{
	std::cout << "\033[0;32m---- Mutant Stack ----\033[0m" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(7);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "\033[0;32m---- Iterate over the Mutant Stack ----\033[0m" << std::endl;
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::cout << "\033[0;32m---- Call of the Copy Constructor of Stack----\033[0m" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "\033[0;32m---- Iterate reverse over the Mutant Stack ----\033[0m" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite) {
		std::cout << *rit << " ";
		++rit;
	}
	std::cout << std::endl;
}

void subject_test_list()
{
	std::cout << "\033[0;32m---- Same now with a list ----\033[0m" << std::endl;

	std::list<int> ls;
	ls.push_back(5);
	ls.push_back(17);
	std::cout << "Top: " << ls.back() << std::endl;
	ls.pop_back();
	std::cout << "Size: " << ls.size() << std::endl;
	ls.push_back(3);
	ls.push_back(7);
	ls.push_back(737);
	ls.push_back(0);
	std::list<int>::iterator lit = ls.begin();
	std::list<int>::iterator lite = ls.end();
	++lit;
	--lit;
	std::cout << "\033[0;32m---- Iterate over the List ----\033[0m" << std::endl;
	while (lit != lite) {
		std::cout << *lit << " ";
		++lit;
	}
	std::cout << std::endl;
	std::cout << "\033[0;32m---- Call of the Copy Constructor of Stack----\033[0m" << std::endl;
	std::list<int> ls2(ls);
	std::cout << "\033[0;32m---- Iterate reverse over the Mutant Stack ----\033[0m" << std::endl;
	std::list<int>::reverse_iterator rlit = ls.rbegin();
	std::list<int>::reverse_iterator rlite = ls.rend();
	++rlit;
	--rlit;
	while (rlit != rlite) {
		std::cout << *rlit << " ";
		++rlit;
	}
	std::cout << std::endl;
}

void iter_test()
{
	std::cout << "\033[0;32m---- more test for the Mutant Stack ----\033[0m" << std::endl;

	MutantStack<int> mstack;
	MutantStack<int> mstack3;
	for (int i = 0; i < 5; i++)
		mstack.push(i);
	std::cout << "\033[0;32m---- Making a Mutant Stack with the numbers 0 - 4----\033[0m" << std::endl;
	std::cout << "\033[0;32m---- Coping that Stack and add a 5----\033[0m" << std::endl;
	MutantStack<int> mstack2(mstack);
	mstack2.push(5);
	std::cout << "\033[0;32m---- Assign that stack to an other and adding a 6----\033[0m" << std::endl;
	mstack3 = mstack2;
	mstack3.push(6);
	std::cout << "\033[0;32m---- The Mutant Stack ----\033[0m" << std::endl;
 	for (MutantStack<int>::iterator i = mstack.begin(); i != mstack.end(); ++i)
    	std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "\033[0;32m---- The Copy----\033[0m" << std::endl;
 	for (MutantStack<int>::iterator i = mstack2.begin(); i != mstack2.end(); ++i)
    	std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "\033[0;32m---- The Assigment Stack: ----\033[0m" << std::endl;
 	for (MutantStack<int>::iterator i = mstack3.begin(); i != mstack3.end(); ++i)
    	std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "\033[0;32m---- The Assigment Stack reverse: ----\033[0m" << std::endl;
 	for (MutantStack<int>::reverse_iterator i = mstack3.rbegin(); i != mstack3.rend(); ++i)
    	std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "\033[0;32m---- Making a const int Mutan stack ----\033[0m" << std::endl;
	MutantStack<int> mstack4;
	const int test = 1;
	mstack4.push(test);
	mstack4.push(test * 2);
	mstack4.push(test * 3);
	mstack4.push(test * 4);
	std::cout << "\033[0;32m---- Printing the const Mutant Stack ----\033[0m" << std::endl;
 	for (MutantStack<int>::const_iterator i = mstack4.begin(); i != mstack4.end(); ++i)
	{
		//(*i)++; // wont work as const
    	std::cout << *i << " ";
	}
	std::cout << std::endl;
	std::cout << "\033[0;32m---- Printing the const Mutant Stack reverse----\033[0m" << std::endl;
 	for (MutantStack<int>::const_reverse_iterator i = mstack4.rbegin(); i != mstack4.rend(); ++i)
	{
		//(*i)++; // wont work as const
    	std::cout << *i << " ";
	}
	std::cout << std::endl;
}
