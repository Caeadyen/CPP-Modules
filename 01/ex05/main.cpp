/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:42:19 by hrings            #+#    #+#             */
/*   Updated: 2022/09/14 22:10:23 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl harl;
	std::cout << std::endl;
	std::cout << "Lets see how much Harl complains:" << std::endl;
	std::cout << "he complains about DEBUG" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "he complains about INFO" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	std::cout << "he complains about WARNING" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	std::cout << "he complains about ERROR" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	std::cout << "he complains about error" << std::endl;
	harl.complain("error");
	std::cout << std::endl;
	std::cout << "he complains about random stuff" << std::endl;
	harl.complain("random stuff");
	std::cout << std::endl;

	return 0;
}
