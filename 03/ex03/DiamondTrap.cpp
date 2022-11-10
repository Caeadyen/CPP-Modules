/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:12:00 by hrings            #+#    #+#             */
/*   Updated: 2022/09/27 11:58:22 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap(): ScavTrap(), FragTrap()
{
	std::cout << "\e[0;33mDefault Constructor called of DiamondTrap\e[0m" << std::endl;
	this->hp = FragTrap::getHp();
	this->ep = ScavTrap::getEp();
	this->attackdamge = FragTrap::getattackdmg();
	this->class_name = "DiamondTrap";
	this->name = "";
	ClapTrap::name = "withoutname_clap_name";
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	std::cout << "\e[0;33mName Constructor called of DiamondTrap called " << name << "\e[0m" << std::endl;
	this->hp = FragTrap::getHp();
	this->ep = ScavTrap::getEp();
	this->attackdamge = FragTrap::getattackdmg();
	this->class_name = "DiamondTrap";
	this->name = name;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of DiamondTrap\e[0m" << std::endl;
}


// Destructor
DiamondTrap::~DiamondTrap()
{
	if (this->name == "")
		std::cout << "\e[0;31mDestructor called of an unnamed DiamondTrap\e[0m" << std::endl;
	else
		std::cout << "\e[0;31mDestructor called of DiamondTrap called " << this->name << "\e[0m" << std::endl;
}


// Operators
DiamondTrap & DiamondTrap::operator=(const DiamondTrap &assign)
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

void DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}
void DiamondTrap::whoAmI()
{
	if (this->name == "")
		std::cout << "Withoutname and also " << ClapTrap::getName() << std::endl;
	else	
		std::cout << this->name << " and also " << ClapTrap::getName() << std::endl;
}
