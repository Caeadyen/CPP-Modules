/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:19:27 by hrings            #+#    #+#             */
/*   Updated: 2022/10/24 14:38:05 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

void vector_test();
void list_test();
int main(void)
{
	
	vector_test();
	list_test();
	return (0);
}

void vector_test()
{
	std::vector<int>::iterator found;
	std::vector<int> vec(6);
	std::cout << "\033[0;32m---- Testing with an vector as container ----\033[0m" << std::endl;
	std::cout << "\033[0;32m---- Making a vector with the numbers 0-4 ----\033[0m" << std::endl;
	for (int i = 0; i < 5; i++)
		vec[i] = i;
	vec[5] = 2;
 	for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); ++i)
    	std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "\033[0;32m---- using easy find to fine 4 ----\033[0m" << std::endl;
	found = easyfind(vec, 4);
	if (found == vec.end())
		std::cout << "cannot find 4 in vector" << std::endl;
	else
		std::cout << "Element found in vector: " << *found << std::endl;

	std::cout << "\033[0;32m---- using easy find to fine 2 ----\033[0m" << std::endl;
	found = easyfind(vec, 2);
	if (found == vec.end())
		std::cout << "cannot find 2 in vector" << std::endl;
	else
		std::cout << "Element found in vector: " << *found << std::endl;
	std::cout << "\033[0;32m---- making sure its actually the first 2----\033[0m" << std::endl;
	std::cout << "\033[0;32mnext element is: \033[0m" << *(++found) << std::endl;		
	std::cout << "\033[0;32m---- using easyfind to find 99 ----\033[0m" << std::endl;
	if (easyfind(vec, 99) == vec.end())
		std::cout << "99 not found in vector" << std::endl;
	else
		std::cout << "somehow found something o.O" << std::endl;
}

void list_test()
{
	std::list<int>::iterator found;
	std::list<int> list;

	for (int i = 0; i < 5; i++)
		list.push_back(i);
	list.push_back(2);
	std::cout << "\033[0;32m---- Testing with an list as container ----\033[0m" << std::endl;
	std::cout << "\033[0;32m---- Making a list with the numbers 0-4 and 2----\033[0m" << std::endl;
 	for (std::list<int>::iterator i = list.begin(); i != list.end(); ++i)
    	std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "\033[0;32m---- using easy find to fine 4 ----\033[0m" << std::endl;
	found = easyfind(list, 4);
	if (found == list.end())
		std::cout << "cannot find 4 in vector" << std::endl;
	else
		std::cout << "Element found in vector: " << *found << std::endl;
	std::cout << "\033[0;32m---- using easy find to fine 2 ----\033[0m" << std::endl;
	found = easyfind(list, 2);
	if (found == list.end())
		std::cout << "cannot find 2 in vector" << std::endl;
	else
		std::cout << "Element found in vector: " << *found << std::endl;
	std::cout << "\033[0;32m---- making sure its actually the first 2----\033[0m" << std::endl;
	std::cout << "\033[0;32mnext element is: \033[0m" << *(++found) << std::endl;		
	std::cout << "\033[0;32m---- using easyfind to find 99 ----\033[0m" << std::endl;
	if (easyfind(list, 99) == list.end())
		std::cout << "99 not found in vector" << std::endl;
	else
		std::cout << "somehow found something o.O" << std::endl;
}
