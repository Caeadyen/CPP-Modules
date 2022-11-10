/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:19:27 by hrings            #+#    #+#             */
/*   Updated: 2022/10/11 09:39:02 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void testScrubbery();
void testRobotomy();
void testPresidential();
void testIntern();

int main(void)
{
	testScrubbery();
	testRobotomy();
	testPresidential();
	testIntern();
	return (0);
}

void testIntern()
{
	Intern		someRandomIntern;
	Bureaucrat	b("Odin", 1);
	Form		*form;

	std::cout << "\e[0;32m---- Testing Intern ----\e[0m" << std::endl;
	std::cout << "\e[0;32mMaking a form of all 3 kind and executing it\e[0m" << std::endl << std::endl;
	std::cout << "\e[0;32m---- RobotomyRequest ----\e[0m" << std::endl;
	form = someRandomIntern.makeForm("RobotomyRequest", "Roboto");
	b.signForm(*form);
	b.executeForm(*form);
	delete (form);

	std::cout << std::endl << std::endl;
	std::cout << "\e[0;32m---- PresidentialPardon ----\e[0m" << std::endl;
	form = someRandomIntern.makeForm("PresidentialPardon", "Pardon");
	b.signForm(*form);
	b.executeForm(*form);
	delete (form);

	std::cout << std::endl << std::endl;
	std::cout << "\e[0;32m---- ShrubberyCreation ----\e[0m" << std::endl;
	form = someRandomIntern.makeForm("ShrubberyCreation", "Tree");
	b.signForm(*form);
	b.executeForm(*form);
	delete (form);

	std::cout << "\e[0;32mTrying to make an unknown Form\e[0m" << std::endl;
	std::cout << std::endl << std::endl;
	form = someRandomIntern.makeForm("wrong creation", "Tree");
	
	std::cout << "\e[0;32mReturning a NULL pointer if it fails:\e[0m" << std::endl;
	std::cout << form << std::endl;

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
	std::cout << testa << std::endl;
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
