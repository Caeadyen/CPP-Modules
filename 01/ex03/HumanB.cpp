/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:02:57 by hrings            #+#    #+#             */
/*   Updated: 2022/09/17 10:28:02 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


// Constructors
HumanB::HumanB(std::string name)
{
	std::cout << "\e[0;33mDefault Constructor called of HumanB\e[0m" << std::endl;
	this->name = name;
	this->weapon = NULL;
}

// Destructor
HumanB::~HumanB()
{
	std::cout << "\e[0;31mDestructor called of HumanB\e[0m" << std::endl;
}

void HumanB::attack(void)
{
	if (this->weapon)
		std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " attacks with his bare hands" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
