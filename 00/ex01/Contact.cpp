/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:06:09 by hrings            #+#    #+#             */
/*   Updated: 2022/09/14 13:36:46 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

void    Contact::setFirstName(std::string str)
{
	firstName.clear();
	this->firstName = str;
}

std::string Contact::getFirstName(void)
{
	return (firstName);
}

void    Contact::setLastName(std::string str)
{
	lastName.clear();
	this->lastName = str;
}

std::string Contact::getLastName(void)
{
	return (lastName);
}

void    Contact::setNickname(std::string str)
{
	nickname.clear();
	this->nickname = str;
}

std::string Contact::getNickname(void)
{
	return (nickname);
}

void    Contact::setPhoneNumber(std::string str)
{
	phoneNumber.clear();
	this->phoneNumber = str;
}
std::string Contact::getPhoneNumber(void)
{
	return (phoneNumber);
}

void    Contact::setDarkestSecret(std::string str)
{
	darkestSecret.clear();
	this->darkestSecret = str;
}

std::string Contact::getDarkestSecret(void)
{
	return (darkestSecret);
}

void	Contact::setIndex(int ind)
{
	this->index = ind;
}

void    Contact::printContact(void)
{
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << modifyString(firstName) << "|";
	std::cout << std::setw(10) << modifyString(lastName) << "|";
	std::cout << std::setw(10) << modifyString(nickname) << "|" << std::endl;
}

void    Contact::printContactFull(void)
{
	std::cout << "First Name    : " << firstName << std::endl;
	std::cout << "Last Name     : " << lastName << std::endl;
	std::cout << "Nickname      : " << nickname << std::endl;
	std::cout << "Phone Number  : " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

std::string Contact::modifyString(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0,9) + ".");
	return (str);
}
