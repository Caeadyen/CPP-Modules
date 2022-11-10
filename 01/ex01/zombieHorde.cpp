/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:24:54 by hrings            #+#    #+#             */
/*   Updated: 2022/08/17 09:54:40 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int	index;

	index = 0;
	if (N <= 0)
		return (NULL);
	Zombie *horde = new Zombie[N];
	while (index < N)
	{
		horde[index].setName(name);
		index++;
	}
	return horde;
}