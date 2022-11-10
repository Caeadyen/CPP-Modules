/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:56:05 by hrings            #+#    #+#             */
/*   Updated: 2022/09/15 15:53:52 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int index;
	int size;

	std::cout << "Lets create a small Zombie Horde of 4 Zombies" << std::endl;
	size = 4;
	Zombie *horde = zombieHorde(size, "Boob");
	std::cout << "and lets announce them all" << std::endl;
	index = 0;
	while (index < size)
		horde[index++].announce();
	delete[] horde;
	std::cout << "Lets create a small Zombie Horde of -4 Zombies" << std::endl;
	std::cout << std::endl;
	size = -4;
	Zombie *horde2 = zombieHorde(size, "Boob");
	delete[] horde2;
	std::cout << std::endl;
	
	return (0);
}