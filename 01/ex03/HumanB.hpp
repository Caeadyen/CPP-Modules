/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:02:29 by hrings            #+#    #+#             */
/*   Updated: 2022/08/17 15:02:30 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
#include "Weapon.hpp"

class HumanB
{
	public:
		// Constructors
		HumanB(std::string name);
		
		// Destructor
		~HumanB();
		
		void attack(void);
		void setWeapon(Weapon &weapon);

	private:
		std::string	name;
		Weapon *weapon;		
};

#endif