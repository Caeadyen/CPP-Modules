/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:42:19 by hrings            #+#    #+#             */
/*   Updated: 2022/08/19 10:12:37 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cout << "Wrong Number of Arguments" << std::endl;
		std::cout << "need: complain lvl" << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return 0;
}
