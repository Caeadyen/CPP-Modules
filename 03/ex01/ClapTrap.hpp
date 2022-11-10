/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 09:31:56 by hrings            #+#    #+#             */
/*   Updated: 2022/09/26 10:03:26 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	public:
		// Constructors
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		
		// Destructor
		~ClapTrap();
		
		// Operators
		ClapTrap & operator=(const ClapTrap &assign);
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		//getter
		unsigned int getHp(void) const;
		unsigned int getEp(void) const;
		unsigned int getattackdmg(void) const;
		void printName(void);
		std::string getName(void) const;
		std::string getClassName(void) const;
	protected:
		
		std::string name;
		unsigned int hp;
		unsigned int ep;
		unsigned int attackdamge;
		std::string class_name;
};

#endif