/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 09:34:11 by hrings            #+#    #+#             */
/*   Updated: 2022/09/27 09:32:58 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap bob("bob");
	FragTrap fred("fred");
	ScavTrap mick("mick");
	FragTrap unknown;
	int	i = 0;

	std::cout << std::endl << "Testing basic operations: " << std::endl << std::endl;
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
	unknown.attack("bob");
	unknown.highFivesGuys();
	unknown.beRepaired(10);
	unknown.takeDamage(10);
	
	std::cout << std::endl << "Testing if EP are working: " << std::endl << std::endl;
	while (i < 100)
	{
		fred.attack("bob");
		i++;
	}
	fred.beRepaired(10);
	fred.highFivesGuys();
	std::cout << std::endl << std::endl << "Testing if death is checked: " << std::endl << std::endl;
	fred.takeDamage(1000);
	fred.takeDamage(1000);
	fred.attack("bob");
	fred.beRepaired(5);
	fred.highFivesGuys();
	return (0);
}