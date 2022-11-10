/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:50:01 by hrings            #+#    #+#             */
/*   Updated: 2022/09/14 13:36:57 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->count = 0;
	this->index = 0;
	std::cout << "Starting a fresh Phonebook ...." << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Closing the Phonebook and all entries are gone ...." << std::endl;
}

void PhoneBook::addContact(void)
{
	std::cout << "Enter the Entry" << std::endl;
	std::cout << "(enter a empty line to abort the add)" << std::endl;
	if (!addFirstName())
		return ;
	if (!addLastName())
		return ;
	if (!addNickname())
		return ;
	if (!addPhonenumber())
		return ;
	if (!addDarkestSecret())
		return ;
	this->tmp.setIndex(index);
	contacts[index] = this->tmp;
	this->index = ( this->index + 1) % COUNT;
	if (this->count < COUNT)
		this->count++;
}

void PhoneBook::searchBook(void)
{
	std::string line;

	if (count == 0)
		std::cout << "Phonebook is empty" << std::endl;
	else
	{
		printall();
		while (1)
		{
			std::cout << "Enter Index of entry to print or MAIN for the maim menu:";
			if (!std::getline(std::cin, line))
				break;
			if (!line.length())
				continue ;
			if (line.length() == 1 && line[0] >= '0' &&
				(line[0] <= this->count + '0' - 1))
			{
				this->contacts[line[0] - '0'].printContactFull();
				break;
			}
			if (line.length() && !line.compare("MAIN"))
				break;
			std::cout << line << " is not a valid Index" << std::endl;
		}
	}
}

bool    PhoneBook::addFirstName(void)
{
	std::string line;
	std::cout << "First Name: ";
	if (std::getline(std::cin, line) && line.length())
	{
		this->tmp.setFirstName(line);
		return (true);
	}
	else
		return (false);
}

bool    PhoneBook::addLastName(void)
{
	std::string line;
	std::cout << "Last Name: ";
	if (std::getline(std::cin, line) && line.length())
	{
		this->tmp.setLastName(line);
		return (true);
	}
	else
		return (false);
}
bool    PhoneBook::addNickname(void)
{
	std::string line;
	std::cout << "Nickname: ";
	if (std::getline(std::cin, line) && line.length())
	{
		this->tmp.setNickname(line);
		return (true);
	}
	else
		return (false);
}
bool    PhoneBook::addPhonenumber(void)
{
	std::string line;
	std::cout << "Phone Number: ";
	if (std::getline(std::cin, line) && line.length())
	{
		this->tmp.setPhoneNumber(line);
		return (true);
	}
	else
		return (false);
}
bool    PhoneBook::addDarkestSecret(void)
{
	std::string line;
	std::cout << "Darkest Secret: ";
	if (std::getline(std::cin, line) && line.length())
	{
		this->tmp.setDarkestSecret(line);
		return (true);
	}
	else
		return (false);
}
void PhoneBook::printall(void)
{
	std::cout << std::setw(10) << "Index Nr." << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < this->count; i++)
		printone(i);
}

void PhoneBook::printone(int ind)
{
	this->contacts[ind].printContact();
}
