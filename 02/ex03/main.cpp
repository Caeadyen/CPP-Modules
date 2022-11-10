/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:04:09 by hrings            #+#    #+#             */
/*   Updated: 2022/09/18 15:46:28 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) 
{
	Point a;
	Point b(1.0f, 1.0f);
	Point c(0.0f, 1.0f);
	Point d(2.0f, 2.0f);
	Point e(0.75f, 0.25f);
	Point f(0.25f, 0.75f);
	Point g(0.5f, 0.5f);
	Point h(-0.25, 0.75f);
	
	std::cout << "The Triangle and the Points:" << std::endl;
	std::cout << "         2       d" << std::endl;
	std::cout << "         |        " << std::endl;
	std::cout << "         |        " << std::endl;
	std::cout << "         |        " << std::endl;
	std::cout << "         c---b    " << std::endl;
	std::cout << "         |f /     " << std::endl;
	std::cout << "     h   | g      " << std::endl;
	std::cout << "         |/ e     " << std::endl;
	std::cout << "-----1---a---1---2->" << std::endl << std::endl;
	
	std::cout << "d in triangle : " << std::boolalpha << bsp(a,b,c,d) << std::endl;
	std::cout << "e in triangle : " << std::boolalpha << bsp(a,b,c,e) << std::endl;
	std::cout << "f in triangle : " << std::boolalpha << bsp(a,b,c,f) << std::endl;
	std::cout << "g in triangle : " << std::boolalpha << bsp(a,b,c,g) << std::endl;
	std::cout << "h in triangle : " << std::boolalpha << bsp(a,b,c,h) << std::endl;
}
