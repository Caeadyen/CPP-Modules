/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:48:47 by hrings            #+#    #+#             */
/*   Updated: 2022/09/18 14:48:48 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed()
{
	if (DEBUG)
		std::cout << "\e[0;33mDefault Constructor called of Fixed\e[0m" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int num)
{
	if (DEBUG)
		std::cout << "\e[0;33mInt Constructor called of Fixed\e[0m" << std::endl;
	this->value = num << fract;
}

Fixed::Fixed(const float num)
{
	if (DEBUG)
		std::cout << "\e[0;33mFloat Constructor called of Fixed\e[0m" << std::endl;
	this->value = roundf(num * (1<<fract));
}

Fixed::Fixed(const Fixed &copy)
{
	if (DEBUG)
		std::cout << "\e[0;33mCopy Constructor called of Fixed\e[0m" << std::endl;
	this->value = copy.getRawBits();
}

// Destructor
Fixed::~Fixed()
{
	if (DEBUG)
		std::cout << "\e[0;31mDestructor called of Fixed\e[0m" << std::endl;
}

// Operators
Fixed & Fixed::operator=(const Fixed &assign)
{
	if (DEBUG)
		std::cout << "\e[0;33mOperators = called of Fixed\e[0m" << std::endl;
	if (this != &assign)
		this->value = assign.value;
	return *this;
}

int Fixed::getRawBits( void ) const
{
	if (DEBUG)
		std::cout << "\e[0;33mgetRawBits called of Fixed\e[0m" << std::endl;
	return (this->value);
}

void Fixed::setRawBits( int const raw )
{
	if (DEBUG)
		std::cout << "\e[0;33msetRawBits called of Fixed\e[0m" << std::endl;
	this->value = raw;
}

float Fixed::toFloat( void ) const
{
	return ( (float)this->value / (1<<fract) );
}

int Fixed::toInt( void ) const
{
	return (this->value >> fract);
}

bool Fixed::operator>(const Fixed &num) const
{
	if (this->value > num.value)
		return (true);
	else
		return (false);
}

bool Fixed::operator<(const Fixed &num) const
{
	if (this->value < num.value)
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(const Fixed &num) const
{
	if (this->value >= num.value)
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(const Fixed &num) const
{
	if (this->value <= num.value)
		return (true);
	else
		return (false);
}

bool Fixed::operator==(const Fixed &num) const
{
	if (this->value == num.value)
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(const Fixed &num) const
{
	if (this->value != num.value)
		return (true);
	else
		return (false);
}

Fixed Fixed::operator+(const Fixed &num) const
{
	Fixed result;
	result.setRawBits(this->value + num.value);
	return (result);
}

Fixed Fixed::operator-(const Fixed &num) const
{
	Fixed result;
	result.setRawBits(this->value - num.value);
	return (result);
}

Fixed Fixed::operator*(const Fixed &num) const
{
	Fixed result;
	result.setRawBits(((this->value * num.value) >> this->fract));
	return (result);
}

Fixed Fixed::operator/(const Fixed &num) const
{
	Fixed result;
	result.setRawBits(roundf( ((float) (this->value) / (float) num.value ) * (1<<fract)));
	return (result);
}

Fixed& Fixed::operator++()
{
	++this->value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed result(*this);
	operator++();
	return (result);
}

Fixed& Fixed::operator--()
{
	--this->value;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed result(*this);
	operator--();
	return (result);
}

Fixed & Fixed::min ( Fixed & first, Fixed &second)
{
	if (first > second)
		return (second);
	else
		return (first);

}

const Fixed & Fixed::min ( const Fixed & first, const Fixed &second)
{
	if (first > second)
		return (second);
	else
		return (first);

}

Fixed & Fixed::max ( Fixed & first, Fixed &second)
{
	if (second > first)
		return (second);
	else
		return (first);
}

Fixed const &Fixed::max ( const Fixed & first, const Fixed &second)
{
	if (second > first)
		return (second);
	else
		return (first);

}

std::ostream& operator<<(std::ostream &outputStream, const Fixed &ref)
{
	outputStream << ref.toFloat();
	return (outputStream);
}
