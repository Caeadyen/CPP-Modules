/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:26:28 by hrings            #+#    #+#             */
/*   Updated: 2022/10/12 17:20:16 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "This points to Class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "This points to Class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "This points to Class C" << std::endl;
	else
		std::cout << "Unknow class, uhuh" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "This points to Class A" << std::endl;
	}
	catch (const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "This points to Class B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout << "This points to Class C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "Unknow class, uhuh" << std::endl;
			}
		}
	}
}
