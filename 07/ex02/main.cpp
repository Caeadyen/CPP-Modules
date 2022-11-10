/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:19:27 by hrings            #+#    #+#             */
/*   Updated: 2022/10/20 13:47:41 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <stdlib.h>
#define MAX_VAL 750

int eval_sheet(void);
void test_empty_array(void);
void test_with_int(void);
void test_with_string(void);

int main(void)
{
	test_empty_array();
    std::cout << "\033[0;32m---- Testing with an int array ----\033[0m" << std::endl << std::endl;
	test_with_int();
    std::cout << "\033[0;32m---- Testing with an string array ----\033[0m" << std::endl << std::endl;
    test_with_string();
    std::cout << "\033[0;32m---- running the test from the eval sheet ----\033[0m" << std::endl;
    std::cout << "\033[0;32m---- added some output to it o.O ----\033[0m" << std::endl;
    if (eval_sheet())
        return (1);
    std::cout << "\033[0;32m---- all fine with the eval sheet tests ----\033[0m" << std::endl;
    return (0);
}

void test_empty_array(void)
{
	std::cout << "\033[0;32m---- Testing making empty Arrays ----\033[0m" << std::endl << std::endl;
	Array<int> test;
	Array<int> test3(10);
	Array<int> test4;
	std::cout << "\033[0;32m---- calling the size function----\033[0m" << std::endl;
	std::cout << "Length of the int array: " << test.size() << std::endl;
	std::cout << "\033[0;32m---- Testing the [] operator ----\033[0m" << std::endl;
    std::cout << "\033[0;32m---- out of bounce for an empty ----\033[0m" << std::endl;
	try
	{
		std::cout << test[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\033[0;32m---- Testing the Copy Constructor ----\033[0m" << std::endl;
	Array<int> test2(test);
    std::cout << "\033[0;32m---- making a copy of test ----\033[0m" << std::endl;
    std::cout << "\033[0;32m---- Test Array ----\033[0m" << std::endl;
	std::cout << "Length of the int array: " << test.size() << std::endl;
    std::cout << "\033[0;32m---- Copyed Array ----\033[0m" << std::endl;
	std::cout << "Length of the int array: " << test2.size() << std::endl;
	std::cout << "\033[0;32m---- Testing the [] operator on the copy Array----\033[0m" << std::endl;
    std::cout << "\033[0;32m---- out of bounce test ----\033[0m" << std::endl;
	try
	{
		std::cout << test2[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << "\033[0;32m---- Testing the Assignment operator ----\033[0m" << std::endl;
    std::cout << "\033[0;32m---- assign test to test3 and test4 ----\033[0m" << std::endl;
    std::cout << "\033[0;32m---- Test Array ----\033[0m" << std::endl;
	std::cout << "Length of the int test array: " << test.size() << std::endl;
	std::cout << "Length of the int test3 array: " << test3.size() << std::endl;
	std::cout << "Length of the int test4 array: " << test4.size() << std::endl;
	test3 = test;
	test4 = test;
    std::cout << "\033[0;32m---- Test3 Array ----\033[0m" << std::endl;
	std::cout << "Length of the int test3 array: " << test3.size() << std::endl;
	std::cout << "Length of the int test4 array: " << test4.size() << std::endl;
	std::cout << "\033[0;32m---- Testing the [] operator on test3 (size was 10 before)----\033[0m" << std::endl;
    std::cout << "\033[0;32m---- out of bounce first left side then right side ----\033[0m" << std::endl;
	try
	{
		std::cout << test3[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
void test_with_int(void)
{
    Array<int> test(5);
    Array<int> test3(10);
	int index = 0;

	while (index < 5)
	{
		test[index] = index * 2;
		index++;
	}
	std::cout << "\033[0;32m---- Testing the [] operator ----\033[0m" << std::endl;
    std::cout << "\033[0;32m---- out of bounce first left side then right side ----\033[0m" << std::endl;
	try
	{
		std::cout << test[-2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << test[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    
    std::cout << "\033[0;32m---- Testing the Copy Constructor ----\033[0m" << std::endl;
	Array<int> test2(test);
    std::cout << "\033[0;32m---- making a copy of test and then increasing all value in test by 1 ----\033[0m" << std::endl;
    std::cout << "\033[0;32m---- Test Array ----\033[0m" << std::endl;
	for (unsigned int i = 0; i < test.size(); i++)
		std::cout << test[i] << " ";
    std::cout << std::endl;
    std::cout << "\033[0;32m---- Test Array increased by 1 ----\033[0m" << std::endl;
    for (unsigned int i = 0; i < test.size(); i++)
		test[i]++;
	for (unsigned int i = 0; i < test.size(); i++)
		std::cout << test[i] << " ";
    std::cout << std::endl;
    std::cout << "\033[0;32m---- Copyed Array ----\033[0m" << std::endl;
	for (unsigned int i = 0; i < test2.size(); i++)
		std::cout << test2[i] << " ";
    std::cout << std::endl;
	std::cout << "\033[0;32m---- Testing the [] operator on the copy Array----\033[0m" << std::endl;
    std::cout << "\033[0;32m---- out of bounce first left side then right side ----\033[0m" << std::endl;
	try
	{
		std::cout << test2[-2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << test2[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << "\033[0;32m---- Testing the Assignment operator ----\033[0m" << std::endl;
    std::cout << "\033[0;32m---- assign test to test3 and then increasing all value in test by 1 ----\033[0m" << std::endl;
    test3 = test;
    std::cout << "\033[0;32m---- Test Array ----\033[0m" << std::endl;
	for (unsigned int i = 0; i < test.size(); i++)
		std::cout << test[i] << " ";
    std::cout << std::endl;
    std::cout << "\033[0;32m---- Test Array increased by 1----\033[0m" << std::endl;
    for (unsigned int i = 0; i < test.size(); i++)
		test[i]++;
	for (unsigned int i = 0; i < test.size(); i++)
		std::cout << test[i] << " ";
    std::cout << std::endl;
    std::cout << "\033[0;32m---- Test3 Array ----\033[0m" << std::endl;
	for (unsigned int i = 0; i < test3.size(); i++)
		std::cout << test3[i] << " ";
    std::cout << std::endl;
	std::cout << "\033[0;32m---- Testing the [] operator on test3 (size was 10 before)----\033[0m" << std::endl;
    std::cout << "\033[0;32m---- out of bounce first left side then right side ----\033[0m" << std::endl;
	try
	{
		std::cout << test3[-2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << test3[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void test_with_string(void)
{
    Array<std::string> test(5);
    Array<std::string> test3(10);
    
    test[0] = "Hello";
    test[1] = "World";
    test[2] = "how";
    test[3] = "is";
    test[4] = "it?";
    
	std::cout << "\033[0;32m---- Testing the [] operator ----\033[0m" << std::endl;
    std::cout << "\033[0;32m---- out of bounce first left side then right side ----\033[0m" << std::endl;
	try
	{
		std::cout << test[-2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << test[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    
    std::cout << "\033[0;32m---- Testing the Copy Constructor ----\033[0m" << std::endl;
	Array<std::string> test2(test);
    std::cout << "\033[0;32m---- making a copy of test and adding an a to every word ----\033[0m" << std::endl;
    std::cout << "\033[0;32m---- Test Array ----\033[0m" << std::endl;
	for (unsigned int i = 0; i < test.size(); i++)
		std::cout << test[i] << " ";
    std::cout << std::endl;
    std::cout << "\033[0;32m---- Test Array with the added a----\033[0m" << std::endl;
    for (unsigned int i = 0; i < test.size(); i++)
		test[i].push_back('a');
	for (unsigned int i = 0; i < test.size(); i++)
		std::cout << test[i] << " ";
    std::cout << std::endl;
    std::cout << "\033[0;32m---- Copyed Array ----\033[0m" << std::endl;
	for (unsigned int i = 0; i < test2.size(); i++)
		std::cout << test2[i] << " ";
    std::cout << std::endl;
	std::cout << "\033[0;32m---- Testing the [] operator on the copy Array----\033[0m" << std::endl;
    std::cout << "\033[0;32m---- out of bounce first left side then right side ----\033[0m" << std::endl;
	try
	{
		std::cout << test2[-2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << test2[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << "\033[0;32m---- Testing the Assignment operator ----\033[0m" << std::endl;
    std::cout << "\033[0;32m---- assign test to test3 and adding an b to every word ----\033[0m" << std::endl;
    test3 = test;
    std::cout << "\033[0;32m---- Test Array ----\033[0m" << std::endl;
	for (unsigned int i = 0; i < test.size(); i++)
		std::cout << test[i] << " ";
    std::cout << std::endl;
    std::cout << "\033[0;32m---- Test Array with the added b----\033[0m" << std::endl;
    for (unsigned int i = 0; i < test.size(); i++)
		test[i].push_back('b');
	for (unsigned int i = 0; i < test.size(); i++)
		std::cout << test[i] << " ";
    std::cout << std::endl;
    std::cout << "\033[0;32m---- Test3 Array ----\033[0m" << std::endl;
	for (unsigned int i = 0; i < test3.size(); i++)
		std::cout << test3[i] << " ";
    std::cout << std::endl;
	std::cout << "\033[0;32m---- Testing the [] operator on test3 (size was 10 before)----\033[0m" << std::endl;
    std::cout << "\033[0;32m---- out of bounce first left side then right side ----\033[0m" << std::endl;
	try
	{
		std::cout << test3[-2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << test3[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int eval_sheet(void)
{
    std::cout << "\033[0;32m---- Making 2 arrays (1 with our Array template 1 normal)----\033[0m" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    std::cout << "\033[0;32m---- testing the Copy Constructor ----\033[0m" << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    std::cout << "\033[0;32m---- checking if array safe the value, no msg means all is fine ----\033[0m" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "\033[0;32m---- checking out of bounds ----\033[0m" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\033[0;32m---- doing stuff: assign new value and deleting the normal array ----\033[0m" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
