/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 09:34:11 by hrings            #+#    #+#             */
/*   Updated: 2022/09/27 09:34:53 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


int main(void)
{
	DiamondTrap dia("Wolf");
	DiamondTrap unknown;
	ClapTrap bob("bob");
	FragTrap fred("fred");
	ScavTrap mick("mick");
	
	int i = 0;

	std::cout << std::endl << "Testing basic operations: " << std::endl << std::endl;
	dia.whoAmI();
	dia.highFivesGuys();
	dia.guardGate();
	dia.beRepaired(10);
	dia.attack("Bob");
	bob.attack("Bob");
	fred.attack("Bob");
	mick.attack("Bob");
	mick.attack("bob");
	mick.beRepaired(5);
	mick.takeDamage(10);
	bob.beRepaired(10);
	bob.takeDamage(5);
	bob.attack("unknown");
	fred.attack("bob");
	fred.beRepaired(10);
	fred.takeDamage(10);
	fred.highFivesGuys();
	unknown.whoAmI();
	unknown.attack("bob");
	unknown.highFivesGuys();
	unknown.guardGate();
	unknown.beRepaired(10);
	unknown.takeDamage(10);
	// int	i = 0;
	std::cout << std::endl << "Testing if EP are working: " << std::endl << std::endl;
	while (i < 100)
	{
		dia.attack("bob");
		i++;
	}
	dia.beRepaired(10);
	dia.highFivesGuys();
	dia.guardGate();
	std::cout << std::endl << std::endl << "Testing if death is checked: " << std::endl << std::endl;
	dia.takeDamage(1000);
	dia.takeDamage(1000);
	dia.attack("bob");
	dia.beRepaired(5);
	dia.highFivesGuys();
	
	return (0);
}