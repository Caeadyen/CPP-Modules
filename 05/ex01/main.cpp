/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:19:27 by hrings            #+#    #+#             */
/*   Updated: 2022/10/11 09:39:15 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void testBureaucrat();
void testForm();


int main(void)
{
	testBureaucrat();
	testForm();
	return (0);
}

void testForm()
{
	Form test = Form("A", 5 , 5);
	Form test2 = Form("B", 15 , 15);
	Form test3 = Form("C", 25 , 25);
	Bureaucrat bureaucrat = Bureaucrat("test", 5);
	Bureaucrat bureaucrat2 = Bureaucrat("test2", 50);
	
	std::cout << "\e[0;32mtesting copy and assignment contructor\e[0m" << std::endl;
	std::cout << "\e[0;32mForms before copy and assignment\e[0m" << std::endl;
	std::cout << test << std::endl;
	std::cout << test2 << std::endl;
	std::cout << test3 << std::endl;
	test2 = test;
	test3 = Form(test);
	std::cout << "\e[0;32mForms after copy and assignment\e[0m" << std::endl;
	std::cout << test << std::endl;
	std::cout << test2 << std::endl;
	std::cout << test3 << std::endl;

	std::cout << "\e[0;32mtesting 'beSigned' a Form by a Bureaucrat\e[0m" << std::endl;
	std::cout << "\e[0;32mForms before\e[0m" << std::endl;
	std::cout << test << std::endl;
	test.beSigned(bureaucrat);
	std::cout << "\e[0;32mForms after\e[0m" << std::endl;
	std::cout << test << std::endl << std::endl;
	
	std::cout << "\e[0;32mTest grade to low to sign\e[0m" << std::endl;
	std::cout << "\e[0;32mForms before\e[0m" << std::endl;
	std::cout << test2 << std::endl;
	try
	{
		test2.beSigned(bureaucrat2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\e[0;32mForms after\e[0m" << std::endl;
	std::cout << test2 << std::endl;

	Form project = Form("A", 5, 10);
	Form project2 = Form("A", 5, 10);
	Bureaucrat	worker = Bureaucrat("test", 5);
	Bureaucrat	worker2 = Bureaucrat("test", 77);
	std::cout << "\e[0;32mtesting 'signForm' of the Bureaucrat class\e[0m" << std::endl;
	std::cout << "\e[0;32mForms before\e[0m" << std::endl;
	std::cout << project << std::endl;
	worker.signForm(project);
	std::cout << "\e[0;32mForms after\e[0m" << std::endl;
	std::cout << project << std::endl << std::endl;
	
	std::cout << "\e[0;32mTest grade to low to sign\e[0m" << std::endl;
	std::cout << "\e[0;32mForms before\e[0m" << std::endl;
	std::cout << project2 << std::endl;
	worker2.signForm(project2);
	std::cout << "\e[0;32mForms after\e[0m" << std::endl;
	std::cout << project2 << std::endl;
}

void testBureaucrat()
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
	std::cout << "after 1 inc" << std::endl;
	std::cout << test << std::endl;
	std::cout << std::endl;
	test.decGrade();
	std::cout << "after 1 dec" << std::endl;
	std::cout << test << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << test2 << std::endl;

	std::cout << "\e[0;32mTesting dec on a 150 grade Bureaucrat\e[0m" << std::endl;
	std::cout << "\e[0;32mBefore: " << std::endl;
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
}
