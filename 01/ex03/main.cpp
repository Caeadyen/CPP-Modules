/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:42:19 by hrings            #+#    #+#             */
/*   Updated: 2022/09/14 16:24:25 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		Weapon sword = Weapon("shiny sword");
		HumanA bob("Bob", club);
		std::cout << std::endl;
		std::cout << "Human A test: (attack with club and then with something else)" << std::endl;
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		std::cout << std::endl;
		std::cout << "Human A test: (now gets a sword and attacks with it)" << std::endl;
		bob.setWeapon(sword);
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		std::cout << std::endl;
		std::cout << "Human B test: (attack with no weapon, a club and then something else)" << std::endl;
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}