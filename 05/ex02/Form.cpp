/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:49:03 by hrings            #+#    #+#             */
/*   Updated: 2022/10/06 12:37:18 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
# include "Bureaucrat.hpp"

// Constructors
Form::Form(): name(""), gradeRequired(1), gradeExecute(1)
{
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(std::string name, int gradeRequired, int gradeExecute): 
		name(name), 
		gradeRequired(gradeRequired), 
		gradeExecute(gradeExecute)
{
	if (this->gradeRequired < 1 || this->gradeExecute < 1)
		throw GradeTooHighException();
	if (this->gradeRequired > 150 || this->gradeExecute > 150)
		throw GradeTooLowException();
		
	this->isSigned = false;
	std::cout << "\e[0;33mConstructor called of Form\e[0m" << std::endl;
}

Form::Form(const Form &copy): 
		name(copy.getName()),
		isSigned(copy.getIsSigned()),
		gradeRequired(copy.getGradeRequired()), 
		gradeExecute(copy.getGradeExecute())
{
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}


// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}

// Operators
Form & Form::operator=(const Form &assign)
{
	std::cout << "\e[0;33mAssignment Operator called of Form\e[0m" << std::endl;
	if (this == &assign)
		return (*this);
	return *this;
}

//getter;
std::string Form::getName() const
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

int Form::getGradeRequired() const
{
	return (this->gradeRequired);
}

int Form::getGradeExecute() const
{
	return (this->gradeExecute);
}

//error
const char* Form::GradeTooHighException::what() const throw()
{
	return ("FormException: Grade too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("FormException: Grade too Low");
}

const char* Form::FormNotSignedException::what() const throw()
{
	return ("FormException: Form is not signed");
}
//methods
void Form::beSigned(Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() > this->gradeRequired)
		throw GradeTooLowException();
	else
		this->isSigned = true;
}

void Form::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned)
		throw FormNotSignedException();
	else if (this->gradeExecute < executor.getGrade() )
		throw GradeTooLowException();
	else
		action();
}

std::ostream& operator<< (std::ostream &out, Form const& obj)
{
	return out << "Form name is: " << obj.getName() << std::endl
		<< "Is the formed signed: " << std::boolalpha << obj.getIsSigned() << std::endl
		<< "The grade to sign is: " << obj.getGradeRequired() << std::endl
		<< "The grade to Execute is: " << obj.getGradeExecute() << std::endl;
}

