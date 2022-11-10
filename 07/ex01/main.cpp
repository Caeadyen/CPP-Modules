/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:19:27 by hrings            #+#    #+#             */
/*   Updated: 2022/10/20 13:04:26 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

class Awesome
{
	public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
	private:
	int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
	o << rhs.get();
	return o;
}


void addone(int &a)
{
	a++;
}

template< typename T >
void capitalization( T  & c )
{
	c = std::toupper(c);
	return;
}

template< typename T >
void print( T const & x )
{
	std::cout << x << " ";
	return;
}

int main(void)
{
	int length = 5;
	int num[5] = {1, 2, 3, 4, 5};
	char letter[5] = {'a', 'b', '1', '!', 'f'};
	

	std::cout << "\033[0;32m---- The Number array ----\033[0m" << std::endl;
	iter( num, length, print );
	std::cout << std::endl;

	iter(num, length, addone);
	std::cout << "\033[0;32m---- The Number array after using the function template iter ----\033[0m" << std::endl;
	std::cout << "\033[0;32m---- with the function addone----\033[0m" << std::endl;
	iter( num, length, print );
	std::cout << std::endl;
	
	std::cout << "\033[0;32m---- The Char array ----\033[0m" << std::endl;
	iter( letter, length, print );
	std::cout << std::endl;
	iter(letter, length, capitalization);
	std::cout << "\033[0;32m---- The Char array after using the function template iter ----\033[0m" << std::endl;
	std::cout << "\033[0;32m---- with the function template capitalization----\033[0m" << std::endl;
	iter( letter, length, print );
	std::cout << std::endl;

	std::cout << "\033[0;32m---- Testing with the Awesome class             ----\033[0m" << std::endl;
	std::cout << "\033[0;32m---- from the eval sheet (removed nl from print)----\033[0m" << std::endl;
	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];
	std::cout << "\033[0;32m---- The Number array ----\033[0m" << std::endl;
	iter( tab, length, print );
	std::cout << std::endl;
	std::cout << "\033[0;32m---- The Awesome array ----\033[0m" << std::endl;
	iter( tab2, length, print );
	std::cout << std::endl;
	return (0);
}
