/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:19:27 by hrings            #+#    #+#             */
/*   Updated: 2022/10/11 09:43:21 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat test = Bureaucrat("test", 10);
	Bureaucrat test2 = Bureaucrat("test2", 150);
	Bureaucrat test3 = Bureaucrat("test3", 1);
	Bureaucrat test5 = Bureaucrat("test5", 1);
	std::cout << "\e[0;32mtesting copy and assignment contructor\e[0m" << std::endl;
	std::cout << "\e[0;32mcopy constructor\e[0m" << std::endl;
	std::cout << "\e[0;32mmaking a Bureaucrat with the copy constructor and highering the grade on the original\e[0m" << std::endl;
	Bureaucrat test4 = Bureaucrat(test);
	test.incGrade();
	std::cout << "\e[0;32mthis is original\e[0m" << std::endl;
	std::cout << test << std::endl;
	std::cout << "\e[0;32mthis is the copy:\e[0m" << std::endl;
	std::cout << test4 << std::endl;
	std::cout << "\e[0;32massignment constructor\e[0m" << std::endl;
	std::cout << "\e[0;32mmaking a Bureaucrat with the assignment constructor and highering the grade on the original\e[0m" << std::endl;
	std::cout << "\e[0;32mthis is Bureaucrat before the assigment:\e[0m" << std::endl;
	std::cout << test5 << std::endl;
	test5 = test;
	test.incGrade();
	std::cout << "\e[0;32mthis is original\e[0m" << std::endl;
	std::cout << test << std::endl;
	std::cout << "\e[0;32mthis is Bureaucrat after the assigment:\e[0m" << std::endl;
	std::cout << test5 << std::endl << std::endl;
	
	std::cout << "\e[0;32mTesting to make a Bureaucrat with garde 151 and -1\e[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat low = Bureaucrat("low", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat high = Bureaucrat("high", -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\e[0;32mTesting inc and dec on a Bureaucrat\e[0m" << std::endl << std::endl;
	std::cout << test << std::endl;
	test.incGrade();
	std::cout << std::endl;
	std::cout << "\e[0;32mafter 1 inc\e[0m" << std::endl;
	std::cout << test << std::endl;
	std::cout << std::endl;
	test.decGrade();
	std::cout << "\e[0;32mafter 1 dec\e[0m" << std::endl;
	std::cout << test << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << test2 << std::endl;

	std::cout << "\e[0;32mTesting dec on a 150 grade Bureaucrat\e[0m" << std::endl;
	std::cout << "\e[0;32mBefore: \e[0m" << std::endl;
	std::cout << test2 << std::endl;
	try
	{
		test2.decGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\e[0;32mafter: \e[0m" << std::endl;
	std::cout << test2 << std::endl;
	std::cout << "\e[0;32mTesting inc on a 1 grade Bureaucrat\e[0m" << std::endl;
	std::cout << "\e[0;32mBefore: \e[0m" << std::endl;
	std::cout << test3 << std::endl;
	try
	{
		test3.incGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\e[0;32mAfter: \e[0m" << std::endl;
	std::cout << test3 << std::endl;
	return (0);
}
