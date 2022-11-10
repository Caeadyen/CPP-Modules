/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:04:09 by hrings            #+#    #+#             */
/*   Updated: 2022/09/18 12:10:51 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
	int aRaw;
	int bRaw;
	int cRaw;

	Fixed a;
	std::cout << "copy test, setting RawBits of a = 1, and then make b as copy of a" << std::endl;
	
	a.setRawBits(1);
	Fixed b( a );
	aRaw = a.getRawBits();
	bRaw = b.getRawBits();
	std::cout << "RawBits of a = " << aRaw << std::endl;
	std::cout << "RawBits of b = " << bRaw << std::endl;
	std::cout << std::endl;
	
	std::cout << "Assignment test, setting RawBits of b = 2, and then assign b to c" << std::endl;
	
	b.setRawBits(2);
	Fixed c;
	c = b;
	bRaw = b.getRawBits();
	cRaw = c.getRawBits();
	std::cout << "RawBits of b = " << bRaw << std::endl;
	std::cout << "RawBits of c = " << cRaw << std::endl;
	std::cout << std::endl;
	
	std::cout << "setting RawBits of c=3 and keep the rest as they were" << std::endl;
	
	c.setRawBits(3);
	aRaw = a.getRawBits();
	bRaw = b.getRawBits();
	cRaw = c.getRawBits();
	std::cout << "RawBits of a = " << aRaw << std::endl;
	std::cout << "RawBits of b = " << bRaw << std::endl;
	std::cout << "RawBits of c = " << cRaw << std::endl;
	
	return 0;
}
