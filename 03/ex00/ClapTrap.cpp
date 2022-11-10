/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 09:32:02 by hrings            #+#    #+#             */
/*   Updated: 2022/09/27 09:01:25 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap()
{
	std::cout << "\e[0;33mDefault Constructor called of ClapTrap\e[0m" << std::endl;
	this->hp = 10;
	this->ep = 10;
	this->attackdamge = 0;
	this->name = "";
}

// Constructors
ClapTrap::ClapTrap(std::string name)
{
	std::cout << "\e[0;33mName Constructor called of ClapTrap called " << name << "\e[0m" << std::endl;
	this->hp = 10;
	this->ep = 10;
	this->attackdamge = 0;
	this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of ClapTrap\e[0m" << std::endl;
}


// Destructor
ClapTrap::~ClapTrap()
{
	if (this->name == "")
		std::cout << "\e[0;31mDestructor called of an unnamed ClapTrap\e[0m" << std::endl;
	else
		std::cout << "\e[0;31mDestructor called of ClapTrap called " << this->name << "\e[0m" << std::endl;
}


// Operators
ClapTrap & ClapTrap::operator=(const ClapTrap &assign)
{
	if (this==&assign)
		return *this;
	this->hp = assign.hp;
	this->ep = assign.ep;
	this->attackdamge = assign.attackdamge;
	this->name = assign.name;
	return *this;
}

void ClapTrap::attack(const std::string& target)
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
		std::cout << "attacks " << target;
		std::cout <<", causing " << this->attackdamge;
		std::cout << " points of damge!" << std::endl;
		this->ep--;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	printName();
	if (this->hp <= 0)
		std::cout << "is already dead." << std::endl;
	else if (amount < this->hp)
	{
		this->hp -= amount;
		std::cout << "has taken " << amount << " of damage." << std::endl;
	}
	else
	{
		std::cout << "has taken " << amount << " of damage and died." << std::endl;
		this->hp = 0;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	printName();
	if (this->hp <= 0)
		std::cout << "is dead nothing to repair anymore." << std::endl;
	else if (this->ep <= 0)
		std::cout << "has not enough Energy to repair." << std::endl;
	else
	{
		std::cout << "was repaired for " << amount << " Hitpoints." << std::endl;
		this->hp += amount;
		this->ep--;
	}
}

void ClapTrap::printName(void)
{
	if (this->name != "")
	{
		std::cout << "ClapTrap " << this->name << " ";
	}
	else
		std::cout << "ClapTrap withoutname ";
}
