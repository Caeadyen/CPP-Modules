/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:12:10 by hrings            #+#    #+#             */
/*   Updated: 2022/10/05 16:12:11 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Bureaucrat
{
	public:
		// Constructors
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		
		// Destructor
		~Bureaucrat();
		
		// Operators
		Bureaucrat & operator=(const Bureaucrat &assign);
		
		//getter
		std::string getName() const;
		int getGrade() const;

		//setter
		void incGrade();
		void decGrade();
		//error
		class GradeTooLowException: public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooHighException: public std::exception
		{
			virtual const char* what() const throw();
		};
		//methods
		void  signForm(Form &form);
	private:
		Bureaucrat();
		const std::string name;
		int grade;
};

std::ostream& operator<< (std::ostream &out, Bureaucrat const& obj);

#endif