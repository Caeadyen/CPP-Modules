/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:49:26 by hrings            #+#    #+#             */
/*   Updated: 2022/10/06 12:51:32 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"
#include <fstream>

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(): Form("Shrubbery Creation Form", 145, 137)
{
	std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): 
										Form("Shrubbery Creation Form", 145, 137)
{
	this->target = target;
	std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):
										Form("Shrubbery Creation Form", 145, 137)
{
	this->target = copy.target;
	std::cout << "\e[0;33mCopy Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}


// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\e[0;31mDestructor called of ShrubberyCreationForm\e[0m" << std::endl;
}


// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	this->target = assign.target;
	return *this;
}

//errors
const char* ShrubberyCreationForm::FormFileOpenFail::what() const throw()
{
	return ("FormException: Failed to open file");
}
//methods

void ShrubberyCreationForm::action() const
{
	std::string fileName = this->target + "_shrubbery";
	std::ofstream output;
	output.open(fileName.c_str());
	if (output.fail())
		throw FormFileOpenFail();
	else
	{
		output << "                                              ." << std::endl;
		output << "                                   .         ;" << std::endl;
		output << "      .              .              ;%     ;;" << std::endl;
		output << "        ,           ,                :;%  %;" << std::endl;
		output << "         :         ;                   :;%;'     .," << std::endl;
		output << ",.        %;     %;            ;        %;'    ,;" << std::endl;
		output << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
		output << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl;
		output << "    ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
		output << "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
		output << "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
		output << "         `:%;.  :;bd%;          %;@%;'" << std::endl;
		output << "           `@%:.  :;%.         ;@@%;'" << std::endl;
		output << "             `@%.  `;@%.      ;@@%;" << std::endl;
		output << "               `@%%. `@%%    ;@@%;" << std::endl;
		output << "                 ;@%. :@%%  %@@%;" << std::endl;
		output << "                   %@bd%%%bd%%:;" << std::endl;
		output << "                     #@%%%%%:;;" << std::endl;
		output << "                     %@@%%%::;" << std::endl;
		output << "                     %@@@%(o);  . '" << std::endl;
		output << "                     %@@@o%;:(.,'" << std::endl;
		output << "                 `.. %@@@o%::;" << std::endl;
		output << "                    `)@@@o%::;" << std::endl;
		output << "                     %@@(o)::;" << std::endl;
		output << "                    .%@@@@%::;" << std::endl;
		output << "                    ;%@@@@%::;." << std::endl;
		output << "                   ;%@@@@%%:;;;." << std::endl;
		output << "               ...;%@@@@@%%:;;;;,.." << std::endl;
		output.close();
	}
}