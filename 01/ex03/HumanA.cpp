/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:02:49 by hrings            #+#    #+#             */
/*   Updated: 2022/09/17 10:27:56 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructors
HumanA::HumanA(std::string name, Weapon& weapon): weapon(weapon)
{
	std::cout << "\e[0;33mConstructor called of HumanA\e[0m" << std::endl;
	this->name = name;
	this->weapon = weapon;
}

// Destructor
HumanA::~HumanA()
{
	std::cout << "\e[0;31mDestructor called of HumanA\e[0m" << std::endl;
}

void HumanA::attack(void)
{
	std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon &weapon)
{
	this->weapon = weapon;
}
