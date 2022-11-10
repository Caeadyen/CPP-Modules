/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:13:54 by hrings            #+#    #+#             */
/*   Updated: 2022/10/12 13:43:26 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Constructors
Base::Base()
{
	//std::cout << "\e[0;33mDefault Constructor called of Base\e[0m" << std::endl;
}

Base::~Base()
{
	//std::cout << "\e[0;31mDestructor called of Base\e[0m" << std::endl;
}

void Base::whoAmI()
{
	std::cout << "bad bad class, uhuh" << std::endl;
}
Base *generate(void)
{
	int num = rand() % 3;
	switch(num)
	{
		case 0:
			return (Base *) new A();
		case 1:
			return (Base *) new B();
		case 2:
			return (Base *) new C();
		default:
			std::cout << "bad bad random, uhuh" << std::endl;
	}
	return (NULL);
}