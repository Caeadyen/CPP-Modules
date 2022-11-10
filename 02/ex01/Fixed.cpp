/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:49:27 by hrings            #+#    #+#             */
/*   Updated: 2022/09/18 14:49:28 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed()
{
	std::cout << "\e[0;33mDefault Constructor called of Fixed\e[0m" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "\e[0;33mInt Constructor called of Fixed\e[0m" << std::endl;
	this->value = num << fract;
}

Fixed::Fixed(const float num)
{
	std::cout << "\e[0;33mFloat Constructor called of Fixed\e[0m" << std::endl;
	this->value = roundf(num * (1<<fract));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Fixed\e[0m" << std::endl;
	this->value = copy.getRawBits();
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "\e[0;31mDestructor called of Fixed\e[0m" << std::endl;
}


// Operators
Fixed & Fixed::operator=(const Fixed &assign)
{
	std::cout << "\e[0;33mOperators = called of Fixed\e[0m" << std::endl;
	if (this != &assign)
		this->value = assign.value;
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "\e[0;33mgetRawBits called of Fixed\e[0m" << std::endl;
	return (this->value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "\e[0;33msetRawBits called of Fixed\e[0m" << std::endl;
	this->value = raw;
}

float Fixed::toFloat( void ) const
{
	return ( (float)this->value / (1<<fract) );
}

int Fixed::toInt( void ) const
{
	return (this->value>>fract);
}

std::ostream& operator<<(std::ostream &outputStream, const Fixed &ref)
{
	outputStream << ref.toFloat();
	return (outputStream);
}
