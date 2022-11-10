/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:05:35 by hrings            #+#    #+#             */
/*   Updated: 2022/09/27 09:27:42 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "\e[0;33mDefault Constructor called of FragTrap\e[0m" << std::endl;
	this->hp = 100;
	this->ep = 100;
	this->attackdamge = 30;
	this->class_name = "FragTrap";
	this->name = "";
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "\e[0;33mName Constructor called of FragTrap called " << name << "\e[0m" << std::endl;
	this->hp = 100;
	this->ep = 100;
	this->attackdamge = 30;
	this->class_name = "FragTrap";
	this->name = name;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of FragTrap\e[0m" << std::endl;
}


// Destructor
FragTrap::~FragTrap()
{
	if (this->name == "")
		std::cout << "\e[0;31mDestructor called of an unnamed FragTrap\e[0m" << std::endl;
	else
		std::cout << "\e[0;31mDestructor called of FragTrap called " << ClapTrap::getName() << "\e[0m" << std::endl;

}


// Operators
FragTrap & FragTrap::operator=(const FragTrap &assign)
{
	if (this==&assign)
		return *this;
	this->hp = assign.getHp();
	this->ep = assign.getEp();
	this->attackdamge = assign.getattackdmg();
	this->class_name = assign.getClassName();
	this->name = assign.getName();
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	printName();
	if (this->hp <= 0)
		std::cout << "is unconscious." << std::endl;
	else if (this->ep <= 0)
		std::cout << "has not enough Energy to give a high five." << std::endl;
	else
		std::cout << "gives a high five to everyone." << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	printName();
	if (this->hp <= 0)
	{
		std::cout << "is unconscious." << std::endl;
	}
	else if (this->ep <= 0)
	{
		std::cout << "has not enough Energy to attack." << std::endl;
	}
	else
	{
		std::cout << "smacks " << target;
		std::cout <<", causing " << this->attackdamge;
		std::cout << " points of damge!" << std::endl;
		this->ep--;
	}
}
