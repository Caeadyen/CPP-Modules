/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:19:27 by hrings            #+#    #+#             */
/*   Updated: 2022/10/20 13:02:56 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

class Awesome
{
	public:
		Awesome( int n ) : _n( n ) {}
		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
	o << rhs.get();
	return o;
}


int main(void)
{
	{
		int a = 2;
		int b = 3;
		std::cout << "\033[0;32m---- Testing with Int\033[0m" << std::endl;
		std::cout << "\033[0;32mBefor Swap: \033[0m";
		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap( a, b );
		std::cout << "\033[0;32mAfter Swap: \033[0m";
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::cout << "max( a, a ) = " << ::max( a, a ) << std::endl;
		std::cout << "min( a, a ) = " << ::min( a, a ) << std::endl;
		
		std::cout << "\033[0;32m---- Testing with String\033[0m" << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		std::cout << "\033[0;32mBefor Swap: \033[0m";
		std::cout << "c = " << c << ", d = " << d << std::endl;
		::swap(c, d);
		std::cout << "\033[0;32mAfter Swap: \033[0m";
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		std::cout << "max( c, c ) = " << ::max( c, c ) << std::endl;
		std::cout << "min( c, c ) = " << ::min( c, c ) << std::endl;
	}
	{
	Awesome a(2), b(4);
	std::cout << "\033[0;32m---- Testing with the Awesome Class\033[0m" << std::endl;
	std::cout << "\033[0;32mBefor Swap: \033[0m";
	std::cout << "a: " << a << " , b: " << b << std::endl;
	swap(a, b);
	std::cout << "\033[0;32mAfter Swap: \033[0m";
	std::cout << "a: " << a << " , b: " << b << std::endl;
	std::cout << "max( a, b ) = " << max(a, b) << std::endl;
	std::cout << "min( a, b ) = " << min(a, b) << std::endl;
	std::cout << "max( a, a ) = " << max(a, a) << std::endl;
	std::cout << "min( a, a ) = " << min(a, a) << std::endl;
	}
	return 0;
}
