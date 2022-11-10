/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:19:27 by hrings            #+#    #+#             */
/*   Updated: 2022/10/11 09:33:02 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testScrubbery();
void testRobotomy();
void testPresidential();

int main(void)
{
	testScrubbery();
	testRobotomy();
	testPresidential();		
	return (0);
}

void testScrubbery()
{
	ShrubberyCreationForm	test("happy");
	ShrubberyCreationForm	testa("super_happy");
	ShrubberyCreationForm	testc("copy");
	ShrubberyCreationForm	testinsigned("happy");
	Bureaucrat				worker("worker", 77);

	std::cout << "\e[0;32m----ShrubberyCreationForm copy/assignment test ----\e[0m" << std::endl;
	std::cout << testa << std::endl;
	std::cout << "\e[0;32m----ShrubberyCreationForm copy constructor ----\e[0m" << std::endl;
	std::cout << "\e[0;32mTarget of the copied Form is copy\e[0m" << std::endl;
	ShrubberyCreationForm	test2 = ShrubberyCreationForm(testc);
	std::cout << test2 << std::endl;
	test2.beSigned(worker);
	test2.execute(worker);
	std::cout << std::endl;
	worker.executeForm(test2);
	std::cout << "\e[0;32mBoth forms after signing the copy but not the original\e[0m" << std::endl;
	std::cout << test2 << std::endl;
	std::cout << testa << std::endl;
	std::cout << "\e[0;32m----ShrubberyCreationForm assignment operator ----\e[0m" << std::endl;
	ShrubberyCreationForm	test3("unhappy");
	std::cout << "\e[0;32mBefore target was unhappy: \e[0m" << std::endl;
	test3.beSigned(worker);
	test3.execute(worker);
	std::cout << std::endl;
	worker.executeForm(test3);
	std::cout << test3 << std::endl;
	test3 = testa;
	std::cout << "\e[0;32mAfter target was super_happy: \e[0m" << std::endl;
	test3.beSigned(worker);
	test3.execute(worker);
	std::cout << std::endl;
	worker.executeForm(test3);
	std::cout << test3 << std::endl;
	std::cout << testa << std::endl;
		
	std::cout << "\e[0;32m----ShrubberyCreationForm basic test ----\e[0m" << std::endl;
	std::cout << std::endl;
	std::cout << test << std::endl;
	test.beSigned(worker);
	test.execute(worker);
	
	std::cout << std::endl;
	worker.executeForm(test);
	std::cout << std::endl;
	std::cout << "\e[0;32m----low grade failure----\e[0m" << std::endl;
	Bureaucrat				workerlow("worker", 140);
	try
	{
		test.execute(workerlow);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		workerlow.executeForm(test);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\e[0;32m----not signed failure----\e[0m" << std::endl;
	try
	{
		testinsigned.execute(workerlow);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		workerlow.executeForm(testinsigned);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void testRobotomy()
{
	RobotomyRequestForm	test("happy");
	RobotomyRequestForm	testa("super_happy");
	RobotomyRequestForm	testc("copy");
	RobotomyRequestForm	testinsigned("happy");
	Bureaucrat 			worker("worker", 7);
	
	std::cout << "\e[0;32m----RobotomyRequestForm copy/assignment test ----\e[0m" << std::endl;
	std::cout << testa << std::endl;
	std::cout << "\e[0;32m----RobotomyRequestForm copy constructor ----\e[0m" << std::endl;
	std::cout << "\e[0;32mTarget of the copied Form is copy\e[0m" << std::endl;
	RobotomyRequestForm	test2 = RobotomyRequestForm(testc);
	std::cout << test2 << std::endl;
	test2.beSigned(worker);
	test2.execute(worker);
	std::cout << std::endl;
	worker.executeForm(test2);
	std::cout << test2 << std::endl;
	std::cout << testa << std::endl;
	std::cout << "\e[0;32m----RobotomyRequestForm assignment operator ----\e[0m" << std::endl;
	RobotomyRequestForm	test3("unhappy");
	std::cout << "\e[0;32mBefore target was unhappy: \e[0m" << std::endl;
	test3.beSigned(worker);
	test3.execute(worker);
	std::cout << std::endl;
	worker.executeForm(test3);
	std::cout << test3 << std::endl;
	test3 = testa;
	std::cout << "\e[0;32mAfter target was super_happy: \e[0m" << std::endl;
	test3.beSigned(worker);
	test3.execute(worker);
	std::cout << std::endl;
	worker.executeForm(test3);
	std::cout << test3 << std::endl;
	std::cout << testa << std::endl;

	std::cout << "\e[0;32m----RobotomyRequestForm test ----\e[0m" << std::endl;
	std::cout << std::endl;
	std::cout << test << std::endl;
	test.beSigned(worker);
	test.execute(worker);
	std::cout << std::endl;
	worker.executeForm(test);
	std::cout << std::endl;
	std::cout << "\e[0;32m----low grade failure----\e[0m" << std::endl;
	Bureaucrat workerlow("worker", 50);
	try
	{
		test.execute(workerlow);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		workerlow.executeForm(test);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\e[0;32m----not signed failure----\e[0m" << std::endl;
	try
	{
		testinsigned.execute(workerlow);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		workerlow.executeForm(testinsigned);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void testPresidential()
{
	PresidentialPardonForm	test("happy");
	PresidentialPardonForm	testinsigned("happy");
	Bureaucrat				worker("worker", 2);
	PresidentialPardonForm	testa("super_happy");
	PresidentialPardonForm	testc("copy");

	std::cout << "\e[0;32m----PresidentialPardonForm copy/assignment test ----\e[0m" << std::endl;
	std::cout << testa << std::endl;
	std::cout << "\e[0;32m----PresidentialPardonForm copy constructor ----\e[0m" << std::endl;
	std::cout << "\e[0;32mTarget of the copied Form is copy\e[0m" << std::endl;
	PresidentialPardonForm	test2 = PresidentialPardonForm(testc);
	std::cout << test2 << std::endl;
	test2.beSigned(worker);
	test2.execute(worker);
	std::cout << std::endl;
	worker.executeForm(test2);
	std::cout << test2 << std::endl;
	std::cout << testc << std::endl;
	std::cout << "\e[0;32m----PresidentialPardonForm assignment operator ----\e[0m" << std::endl;
	PresidentialPardonForm	test3("unhappy");
	std::cout << "\e[0;32mBefore target was unhappy: \e[0m" << std::endl;
	test3.beSigned(worker);
	test3.execute(worker);
	std::cout << std::endl;
	worker.executeForm(test3);
	std::cout << test3 << std::endl;
	test3 = testa;
	std::cout << "\e[0;32mAfter target was super_happy: \e[0m" << std::endl;
	test3.beSigned(worker);
	test3.execute(worker);
	std::cout << std::endl;
	worker.executeForm(test3);
	std::cout << test3 << std::endl;
	std::cout << testa << std::endl;
		
	std::cout << "\e[0;32m----PresidentialPardonForm test ----\e[0m" << std::endl;
	std::cout << std::endl;
	std::cout << test << std::endl;
	test.beSigned(worker);
	test.execute(worker);
	std::cout << std::endl;
	worker.executeForm(test);
	std::cout << std::endl;
	std::cout << "\e[0;32m----low grade failure----\e[0m" << std::endl;
	Bureaucrat				workerlow("worker", 20);
	try
	{
		test.execute(workerlow);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		workerlow.executeForm(test);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\e[0;32m----not signed failure----\e[0m" << std::endl;
	try
	{
		testinsigned.execute(workerlow);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		workerlow.executeForm(testinsigned);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void testBureaucrat()
{
	Bureaucrat test = Bureaucrat("test", 10);
	Bureaucrat test2 = Bureaucrat("test2", 150);
	Bureaucrat test3 = Bureaucrat("test3", 1);
	Bureaucrat test5 = Bureaucrat("test5", 1);
	std::cout << "\e[0;32mtesting copy and assignment contructor\e[0m" << std::endl;
	std::cout << "\e[0;32mcopy constructor" << std::endl;
	std::cout << "\e[0;32mmaking a Bureaucrat with the copy constructor and highering the grade on the original\e[0m" << std::endl;
	Bureaucrat test4 = Bureaucrat(test);
	test.incGrade();
	std::cout << "\e[0;32mthis is original" << std::endl;
	std::cout << test << std::endl;
	std::cout << "\e[0;32mthis is the copy:" << std::endl;
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
