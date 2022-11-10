/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:48:55 by hrings            #+#    #+#             */
/*   Updated: 2022/10/05 16:48:56 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat()
{
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
	std::cout << "\e[0;33mConstructor called of Bureaucrat\e[0m" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): name(copy.getName())
{
	this->grade = copy.getGrade();
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
}


// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}


// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
	std::cout << "\e[0;33mBureaucrat assignment operator called.\e[0m" << std::endl;
	if (this == &assign)
		return (*this);
	this->~Bureaucrat();
	new (this) Bureaucrat(assign);
	return *this;
}

//getter
std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

//setter
void Bureaucrat::incGrade()
{
	if (this->grade <= 1)
		throw GradeTooHighException();
	else
		this->grade--;
}

void Bureaucrat::decGrade()
{
	if (this->grade >= 150)
		throw GradeTooLowException();
	else
		this->grade++;
}
//error
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("BureaucratException: Grade too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("BureaucratException: Grade too Low");
}

//methods
void  Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName()<< std::endl;
	}
	catch(const std::exception& e)
	{
		
		std::cout << this->name << " couldn't sign " << form.getName();
		std::cout << " because " << e.what() << std::endl;
	}
	
	
}

void Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " could not execute " << form.getName() <<std::endl;
		std::cout << "Reason for it was: " << e.what() << std::endl;
	}
	
	
}
std::ostream& operator<< (std::ostream &out, Bureaucrat const& obj)
{
	return out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
}