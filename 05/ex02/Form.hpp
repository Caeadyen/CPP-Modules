/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:49:07 by hrings            #+#    #+#             */
/*   Updated: 2022/10/06 13:08:05 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
//# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		// Constructors
		Form(std::string name, int gradeRequired, int gradeExecute);
		Form(const Form &copy);
		Form();
		// Operators		
		Form & operator=(const Form &assign);
		
		// Destructor
		~Form();
		
		//getter;
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeRequired() const;
		int getGradeExecute() const;
		//error
		class GradeTooLowException: public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooHighException: public std::exception
		{
			virtual const char* what() const throw();
		};
		class FormNotSignedException: public std::exception
		{
			virtual const char* what() const throw();
		};
		//methods
		void beSigned(Bureaucrat &bureaucrat);
		void execute(Bureaucrat const & executor) const;
		virtual void action() const = 0;
	private:
		const std::string name;
		bool isSigned;
		const int gradeRequired;
		const int gradeExecute;

};

std::ostream& operator<< (std::ostream &out, Form const& obj);

#endif