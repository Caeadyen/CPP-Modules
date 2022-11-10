/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:19:27 by hrings            #+#    #+#             */
/*   Updated: 2022/10/25 09:34:20 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define NRELEMENTS 100000
#include <limits.h>

void basic_test();
void basic_span_test();
void big_Span_test();

int main(void)
{
	basic_test();
	basic_span_test();
	big_Span_test();
		
	return (0);
}

void basic_test()
{
	Span sp = Span(5);
	Span sp3 = Span(10);
	Span sp4 = Span(5);

	std::cout << "\033[0;32m---- Testing basic functions of Span ----\033[0m" << std::endl;
	std::cout << "\033[0;32m---- Making a copy when 3 items are in and an assigment when 4 ----\033[0m" << std::endl;
	sp.addNumber(6);
	sp.addNumber(1);
	sp.addNumber(17);
	Span sp2(sp);
	sp.addNumber(9);
	sp3 = sp;
	sp.addNumber(11);
	std::cout << "\033[0;32m---- Made a Span of 5 elements ----\033[0m" << std::endl;
    std::cout << sp << std::endl;
	std::cout << "\033[0;32m---- The Copy with 3 elements ----\033[0m" << std::endl;
	std::cout << sp2 << std::endl;
	std::cout << "\033[0;32m---- The Assigment with 4 elements----\033[0m" << std::endl;
	std::cout << sp3 << std::endl;
	std::cout << "\033[0;32m---- Testing to access elements of the 4 element Span but place for 5----\033[0m" << std::endl;
	try
	{
		for (int i = 0; i < 5;i++)
			std::cout << sp3.getElement(i) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "\033[0;32m---- Added one more to Span ----\033[0m" << std::endl;
	try
	{
		sp.addNumber(11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[0;32m---- Testing to add multiple numbers ----\033[0m" << std::endl;
	int myints[] = {16,5,77,29};
    std::vector<int> vec(myints, myints + sizeof(myints) / sizeof(int) );
    sp4.addNumber(vec.begin(), vec.end());
	std::cout << "\033[0;32m---- added 4 numbers to the Span ----\033[0m" << std::endl;
    std::cout << sp4 << std::endl;
	std::cout << "\033[0;32m---- tried to add 4 more numbers to the Span ----\033[0m" << std::endl;
	try
	{
		sp4.addNumber(vec.begin(), vec.end());	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << sp4 << std::endl;
}

void basic_span_test()
{
	Span sp = Span(5);
	Span sp4 = Span(5);
	Span sp5 = Span(5);
	Span sp6 = Span(5);
	Span sp7 = Span(5);
	std::cout << "\033[0;32m---- Testing functions of Span ----\033[0m" << std::endl;
	std::cout << "\033[0;32m---- Making a copy when 1 and 2 items are in it ----\033[0m" << std::endl;
	sp.addNumber(6);
	Span sp2(sp);
	sp.addNumber(1);
	Span sp3(sp);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "\033[0;32m---- Made a Span of 5 elements ----\033[0m" << std::endl;
    std::cout << sp << std::endl;
	std::cout << "\033[0;32m---- Testing the Span functions on the 5 Element Span ----\033[0m" << std::endl;
	std::cout << "\033[0;32mShortest Span expected 2 (9-11)  , got: \033[0m" << sp.shortestSpan() << std::endl;
	std::cout << "\033[0;32mLongest Span expected 16 (1 - 17), got: \033[0m" << sp.longestSpan() << std::endl;
	std::cout << "\033[0;32m---- Testing the Span functions on the 0 Element Span ----\033[0m" << std::endl;
	std::cout << "\033[0;32m---- A Span with 0 elements----\033[0m" << std::endl;
	std::cout << sp4 << std::endl;
	std::cout << "\033[0;32mExpecting an Error on both\033[0m" << std::endl;
	try
	{
		std::cout << sp4.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << sp4.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[0;32m---- A Span with 1 elements----\033[0m" << std::endl;
	std::cout << sp2 << std::endl;
	std::cout << "\033[0;32mExpecting an Error on both\033[0m" << std::endl;
	try
	{
		std::cerr << sp2.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
		try
	{
		std::cerr << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[0;32m---- A Span with 2 elements----\033[0m" << std::endl;
	std::cout << sp3 << std::endl;
	std::cout << "\033[0;32mShortest Span expected 5 (1-6), got: \033[0m" << sp3.shortestSpan() << std::endl;
	std::cout << "\033[0;32mLongest Span expected  5 (1-6), got: \033[0m" << sp3.longestSpan() << std::endl;
	std::cout << "\033[0;32m---- A Span with 5 also negative elements----\033[0m" << std::endl;
	sp5.addNumber(-10);
	sp5.addNumber(6);
	sp5.addNumber(0);
	sp5.addNumber(-3);
	sp5.addNumber(10);
	std::cout << sp5 << std::endl;
	std::cout << "\033[0;32mShortest Span expected 3 , got: \033[0m" << sp5.shortestSpan() << std::endl;
	std::cout << "\033[0;32mLongest Span expected 20 , got: \033[0m" << sp5.longestSpan() << std::endl;
	std::cout << "\033[0;32m---- A Span with 5 same Numbers----\033[0m" << std::endl;
	sp6.addNumber(10);
	sp6.addNumber(10);
	sp6.addNumber(10);
	sp6.addNumber(10);
	sp6.addNumber(10);
	std::cout << sp6 << std::endl;
	std::cout << "\033[0;32mShortest Span expected 0 , got: \033[0m" << sp6.shortestSpan() << std::endl;
	std::cout << "\033[0;32mLongest Span expected  0 , got: \033[0m" << sp6.longestSpan() << std::endl;
	std::cout << "\033[0;32m---- Testing with int min and max----\033[0m" << std::endl;
	sp7.addNumber(INT_MAX);
	sp7.addNumber(INT_MIN);
	std::cout << sp7 << std::endl;
	std::cout << "\033[0;32mShortest Span expected 4294967295 , got: \033[0m" << sp7.shortestSpan() << std::endl;
	std::cout << "\033[0;32mLongest Span expected  4294967295 , got: \033[0m" << sp7.longestSpan() << std::endl;

}
void big_Span_test()
{
	srand(time(NULL));
	Span sp = Span(NRELEMENTS);
	for (unsigned int i = 0; i < NRELEMENTS; i++)
		sp.addNumber(i * 2);
	std::cout << "\033[0;32m---- Testing the Span functions on a " << NRELEMENTS << " Element Span. ----\033[0m" << std::endl;
	std::cout << "\033[0;32m---- Value is always index * 2 ----\033[0m" << std::endl;
	std::cout << "\033[0;32mShortest Span expexted 2,     got: \033[0m" << sp.shortestSpan() << std::endl;
	std::cout << "\033[0;32mLongest Span expected "<< (NRELEMENTS - 1)* 2 << " got : \033[0m" << sp.longestSpan() << std::endl;

	Span sp2 = Span(NRELEMENTS);
	for (unsigned int i = 0; i < NRELEMENTS; i++)
		sp2.addNumber(rand());
	std::cout << "\033[0;32m---- Testing the Span functions on a " << NRELEMENTS << " Element Span with random value. ----\033[0m" << std::endl;
	std::cout << "\033[0;32mShortest Span: \033[0m" << sp2.shortestSpan() << std::endl;
	std::cout << "\033[0;32mLongest Span : \033[0m" << sp2.longestSpan() << std::endl;		
}
