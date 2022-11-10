/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 08:35:13 by hrings            #+#    #+#             */
/*   Updated: 2022/09/17 10:24:48 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructors
Zombie::Zombie(std::string name)
{
	std::cout << "\e[0;33mConstructor with " << name << " called of Zombie\e[0m" << std::endl;
	this->_name = name;
}

Zombie::Zombie()
{
	std::cout << "\e[0;33mDefault Constructor called of Zombie\e[0m" << std::endl;

}

// Destructor
Zombie::~Zombie()
{
	std::cout << "\e[0;31mDestructor called of Zombie: \e[0m" << _name << std::endl;
}


// Operators
void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

