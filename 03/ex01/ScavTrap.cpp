/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 10:51:28 by hrings            #+#    #+#             */
/*   Updated: 2022/09/26 10:49:59 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "\e[0;33mDefault Constructor called of ScavTrap\e[0m" << std::endl;
	this->hp = 100;
	this->ep = 50;
	this->attackdamge = 20;
	this->class_name = "ScavTrap";
	this->name = "";
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "\e[0;33mName Constructor called of ScavTrap called " << name << "\e[0m" << std::endl;
	this->hp = 100;
	this->ep = 50;
	this->attackdamge = 20;
	this->class_name = "ScavTrap";
	this->name = name;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of ScavTrap\e[0m" << std::endl;
}


// Destructor
ScavTrap::~ScavTrap()
{
	if (this->name == "")
		std::cout << "\e[0;31mDestructor called of an unnamed ScavTrap\e[0m" << std::endl;
	else
		std::cout << "\e[0;31mDestructor called of ScavTrap called " << ClapTrap::getName() << "\e[0m" << std::endl;
}


// Operators
ScavTrap & ScavTrap::operator=(const ScavTrap &assign)
{
	if (this == &assign)
		return *this;
	this->hp = assign.getHp();
	this->ep = assign.getEp();
	this->attackdamge = assign.getattackdmg();
	this->class_name = assign.getClassName();
	this->name = assign.getName();
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	ClapTrap::printName();
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
		std::cout << "punshes " << target;
		std::cout <<", causing " << ClapTrap::getattackdmg();
		std::cout << " points of damge!" << std::endl;
		this->ep -= 1;
	}
}

void ScavTrap::guardGate()
{
	ClapTrap::printName();
	if (this->hp <= 0)
		std::cout << "is unconscious." << std::endl;
	else if (this->ep <= 0)
		std::cout << "has not enough Energy for Gate keeper mode." << std::endl;
	else
		std::cout << "is now in Gate keeper mode." << std::endl;
}
