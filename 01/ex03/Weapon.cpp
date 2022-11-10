/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:03:03 by hrings            #+#    #+#             */
/*   Updated: 2022/08/17 15:03:04 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
	std::cout << "\e[0;33mDefault Constructor called of Weapon\e[0m" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "\e[0;31mDestructor called of Weapon\e[0m" << std::endl;
}

std::string const & Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}