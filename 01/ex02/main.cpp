/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:42:19 by hrings            #+#    #+#             */
/*   Updated: 2022/08/17 10:52:38 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <iostream>

int	main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "\e[0;33mThe memory address:\e[0m" << std::endl;
	std::cout << "The memory address of the string variable: " << &brain  << std::endl;
	std::cout << "The memory address held by stringPTR     : " << stringPTR  << std::endl;
	std::cout << "The memory address held by stringREF     : " << &stringREF  << std::endl;

	std::cout << "\e[0;33mThe value:\e[0m" << std::endl;
	std::cout << "The value of the string variable  : " << brain  << std::endl;
	std::cout << "The value pointed to by stringPTR : " << *stringPTR  << std::endl;
	std::cout << "The value pointed to by stringREF : " << stringREF  << std::endl;

	return (0);
}