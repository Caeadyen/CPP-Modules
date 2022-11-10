/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:49:50 by hrings            #+#    #+#             */
/*   Updated: 2022/10/07 10:36:45 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Constructors
Intern::Intern()
{
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
}


// Destructor
Intern::~Intern()
{
	std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}


// Operators
Intern & Intern::operator=(const Intern &assign)
{
	(void) assign;
	return *this;
}

Form * Intern::makeForm(std::string formName, std::string target)
{
	Form *result = NULL;
	forms index;
	
	index = convert(formName);
	
	switch (index)
	{
		case PresidentialPardon:
			result = new PresidentialPardonForm(target);
			std::cout << "Intern creates " << formName << std::endl;
			break;
		case RobotomyRequest:
			result = new RobotomyRequestForm(target);
			std::cout << "Intern creates " << formName << std::endl;
			break;
		case ShrubberyCreation:
			result = new ShrubberyCreationForm(target);
			std::cout << "Intern creates " << formName << std::endl;
			break;
		default:
			std::cout << "Intern can't find the \"" << formName << "\" Form." << std::endl;
			break;
	}
	return (result);
}

Intern::forms Intern::convert(std::string input)
{
	if( input == "PresidentialPardon")
		return PresidentialPardon;
	if( input == "RobotomyRequest")
		return RobotomyRequest;
	if( input == "ShrubberyCreation")
		return ShrubberyCreation;
	return none;
}