/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:02:34 by hrings            #+#    #+#             */
/*   Updated: 2022/08/17 15:02:35 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
	public:
		// Constructors
		Weapon(std::string type);
		
		// Destructor
		~Weapon();
		
		const std::string& getType();
		void	setType(std::string type);
	private:
		std::string type;

		
};

#endif