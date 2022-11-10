/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 09:34:11 by hrings            #+#    #+#             */
/*   Updated: 2022/09/27 15:18:21 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap bob("bob");
	ClapTrap fred("fred");
	ScavTrap mick("mick");
	ScavTrap unknow;
	int	i = 0;

	std::cout << std::endl << "Testing basic operations: " << std::endl << std::endl;
	mick.attack("bob");
	mick.beRepaired(5);
	bob.beRepaired(10);
	fred.attack("bob");
	bob.takeDamage(5);
	fred.beRepaired(10);
	unknow.takeDamage(5);
	unknow.attack("mick");
	mick.guardGate();
	std::cout << std::endl << "Testing if EP are working: " << std::endl << std::endl;
	while (i < 10)
	{
		fred.attack("bob");
		i++;
	}
	i = 0;
	while (i < 50)
	{
		mick.beRepaired(10);
		i++;
	}
	std::cout << std::endl << "Testing if death is checked: " << std::endl << std::endl;
	mick.takeDamage(600);
	mick.takeDamage(100);
	mick.attack("bob");
	mick.beRepaired(5);
	std::cout << std::endl;
	
	return (0);
}