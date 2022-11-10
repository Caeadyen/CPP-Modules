/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:49:19 by hrings            #+#    #+#             */
/*   Updated: 2022/10/06 12:48:07 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <time.h>
#include <stdlib.h>
// Constructors
RobotomyRequestForm::RobotomyRequestForm(): Form("Robotomy Request Form", 72, 45)
{
	std::cout << "\e[0;33mDefault Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("Robotomy Request Form", 72, 45)
{
	this->target = target;
	std::cout << "\e[0;33mConstructor called of RobotomyRequestForm\e[0m" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): Form("Robotomy Request Form", 72, 45)
{
	this->target = copy.target;
	std::cout << "\e[0;33mCopy Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}


// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\e[0;31mDestructor called of RobotomyRequestForm\e[0m" << std::endl;
}


// Operators
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	this->target = assign.target;
	return *this;
}

//methods

void RobotomyRequestForm::action() const
{
	srand(time(NULL));
	if (rand() % 2 == 1)
		std::cout << this->target << " has been robotomized." << std::endl;
	else
		std::cout << "The Robotomy of " << this->target << " has been failed." << std::endl;
}