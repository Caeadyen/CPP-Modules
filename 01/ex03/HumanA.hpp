/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:02:52 by hrings            #+#    #+#             */
/*   Updated: 2022/09/14 16:17:35 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
	public:
		// Constructors
		HumanA(std::string name, Weapon& weapon);
		
		// Destructor
		~HumanA();
		void attack(void);
		void setWeapon(Weapon &weapon);
		
	private:
		std::string	name;
		Weapon &weapon;
};

#endif