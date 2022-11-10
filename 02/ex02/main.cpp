/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:04:09 by hrings            #+#    #+#             */
/*   Updated: 2022/09/18 15:27:53 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void testSubject();
void testMinMax();
void testComparison();
void testArithmetic();
	
int main( void ) 
{
	std::cout << "Test from the Subject.pdf" << std::endl;
	testSubject();
	std::cout << std::endl << "Testing Min and Max" << std::endl << std::endl;
	testMinMax();
	std::cout << std::endl << "Testing Comparison" << std::endl << std::endl;
	testComparison();
	std::cout << std::endl << "Testing Arithmetic" << std::endl << std::endl;
	testArithmetic();
	return 0;
}

void testSubject()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}
void testMinMax()
{
	Fixed		a(-10.25f);
	Fixed		b(-9);
	Fixed const	c(99);

	std::cout << "a = " << a << "(-10,25)  b = " << b << std::endl;
	std::cout << "  max(a,b) = " << Fixed::max(a, b) << std::endl;
	std::cout << "  min(a,b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "a = " << a << "(-10,25)  c(const) = " << c << std::endl;
	std::cout << "  max(a,c) = " << Fixed::max(a, c) << std::endl;
	std::cout << "  min(a,c) = " << Fixed::min(a, c) << std::endl << std::endl;	
}

void testComparison()
{
	Fixed	a(6.95f);
	Fixed	b(7);

	std::cout << "a = " << a << "(6,95)  b = " << b << std::endl;
	std::cout << "  a > b ? " << std::boolalpha << (a > b) << std::endl;
	std::cout << "  a < b ? " << std::boolalpha <<(a < b) << std::endl;
	std::cout << "  a >= b ? " << std::boolalpha <<(a >= b) << std::endl;
	std::cout << "  a <= b ? " << std::boolalpha <<(a <= b) << std::endl;
	std::cout << "  a == b ? " << std::boolalpha <<(a == b) << std::endl;
	std::cout << "  a != b ? " << std::boolalpha <<(a != b) << std::endl << std::endl;
	b = a;
	std::cout << "a = " << a << "(6,95)  b = " << b << " (6,95)" << std::endl;
	std::cout << "  a > b ? " << std::boolalpha <<(a > b) << std::endl;
	std::cout << "  a < b ? " << std::boolalpha <<(a < b) << std::endl;
	std::cout << "  a >= b ? " << std::boolalpha <<(a >= b) << std::endl;
	std::cout << "  a <= b ? " << std::boolalpha <<(a <= b) << std::endl;
	std::cout << "  a == b ? " << std::boolalpha <<(a == b) << std::endl;
	std::cout << "  a != b ? " << std::boolalpha <<(a != b) << std::endl << std::endl;
	
	std::cout << "a = " << a << " (6,95)" << std::endl;
	std::cout << "  a > a ? " << std::boolalpha <<(a > a) << std::endl;
	std::cout << "  a < a ? " << std::boolalpha <<(a < a) << std::endl;
	std::cout << "  a >= a ? " << std::boolalpha <<(a >= a) << std::endl;
	std::cout << "  a <= a ? " << std::boolalpha <<(a <= a) << std::endl;
	std::cout << "  a == a ? " << std::boolalpha <<(a == a) << std::endl;
	std::cout << "  a != a ? " << std::boolalpha <<(a != a) << std::endl << std::endl;
	
}

void testArithmetic()
{
	Fixed	a(6.95f);
	Fixed	b(7);

	std::cout << "a is a float, b an int" << std::endl;
	std::cout << "a = " << a << "(6,95)  b = " << b << std::endl;
	std::cout << "  a + b = " << a + b << " vs normal: " << 6.95f + 7 << std::endl;
	std::cout << "  a - b = " << a - b << " vs normal: " << 6.95f - 7 << std::endl;
	std::cout << "  a * b = " << a * b << " vs normal: " << 6.95f * 7 << std::endl;
	std::cout << "  a / b = " << a / b << " vs normal: " << 6.95f / 7 << std::endl << std::endl;
	
	Fixed c(10);
	Fixed d(3);

	std::cout << "c is an int, d an int" << std::endl;
	std::cout << "c = " << c << " d = " << d << std::endl;
	std::cout << "  c + d  : " << c + d << " vs normal: " << 10 + 3 << std::endl;
	std::cout << "  c - d  : " << c - d << " vs normal: " << 10 - 3 << std::endl;
	std::cout << "  c * d  : " << c * d << " vs normal: " << 10 * 3 << std::endl;
	std::cout << "  c / d  : " << c / d << " vs normal: " << 10 / 3 << std::endl << std::endl;

	Fixed	e(6.95f);
	Fixed	f(3.5f);

	std::cout << "e is a float, f a float" << std::endl;
	std::cout << "e = " << e << "(6,95)  f = " << f << " (3,5) " << std::endl;
	std::cout << "  e + f = " << e + f << " vs normal: " << 6.95f + 3.5f << std::endl;
	std::cout << "  e - f = " << e - f << " vs normal: " << 6.95f - 3.5f << std::endl;
	std::cout << "  e * f = " << e * f << " vs normal: " << 6.95f * 3.5f << std::endl;
	std::cout << "  e / f = " << e / f << " vs normal: " << 6.95f / 3.5f << std::endl << std::endl;
	
}
