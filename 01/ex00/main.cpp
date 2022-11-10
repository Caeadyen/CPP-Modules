/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:56:05 by hrings            #+#    #+#             */
/*   Updated: 2022/09/15 15:43:55 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "Making a Zombie Boob and a random Zombie Greg" << std::endl;
	Zombie *one = newZombie("Boob");
	randomChump("Greg");
	std::cout << std::endl;
	std::cout << "Zombie Boob should also announce himself" << std::endl;
	one->announce();
	delete one;
	return (0);
}