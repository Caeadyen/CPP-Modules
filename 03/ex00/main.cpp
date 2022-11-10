/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 09:34:11 by hrings            #+#    #+#             */
/*   Updated: 2022/09/26 11:05:35 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap bob("bob");
	ClapTrap fred("fred");
	ClapTrap mick;
	int	i = 0;

	std::cout << std::endl << "Testing basic operations: " << std::endl << std::endl;
	mick.attack("bob");
	mick.beRepaired(5);
	bob.beRepaired(10);
	bob.takeDamage(5);
	fred.attack("bob");
	fred.beRepaired(10);
	std::cout << std::endl << "Testing if EP are working: " << std::endl << std::endl;
	while (i < 10)
	{
		fred.attack("bob");
		i++;
	}
	i = 0;
	while (i < 10)
	{
		bob.beRepaired(10);
		i++;
	}
	std::cout << std::endl << "Testing if death is checked: " << std::endl << std::endl;
	mick.takeDamage(100);
	mick.takeDamage(100);
	mick.attack("bob");
	mick.beRepaired(5);
	return (0);
}
