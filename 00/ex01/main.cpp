/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:31:56 by hrings            #+#    #+#             */
/*   Updated: 2022/09/14 13:36:53 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string command;
	PhoneBook phonebook;

	while (1)
	{
		std::cout << "Enter Command [ADD; SEARCH; EXIT]:";
		if (!std::getline(std::cin, command))
			break;
		if (command.compare("ADD") == 0)
			phonebook.addContact();
		else if (command.compare("SEARCH") == 0)
			phonebook.searchBook();
		else if (command.compare("EXIT") == 0)
			break ;
		else if (!command.length())
			continue ;
		else
			std::cout << command << " is an invalid command" << std::endl;
	}
	return (0);
}
