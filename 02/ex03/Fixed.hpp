/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:48:39 by hrings            #+#    #+#             */
/*   Updated: 2022/09/18 14:48:40 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

# define DEBUG false

class Fixed
{
	public:
		// Constructors
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &copy);
		
		// Destructor
		~Fixed();
		
		// Operators
		Fixed & operator=(const Fixed &assign);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		bool operator>(const Fixed &num) const;
		bool operator<(const Fixed &num) const;
		bool operator>=(const Fixed &num) const;
		bool operator<=(const Fixed &num) const;
		bool operator==(const Fixed &num) const;
		bool operator!=(const Fixed &num) const;

		Fixed operator+(const Fixed &num) const;
		Fixed operator-(const Fixed &num) const;
		Fixed operator*(const Fixed &num) const;
		Fixed operator/(const Fixed &num) const;

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		static Fixed &min ( Fixed & first, Fixed &second);
		const static Fixed &min ( const Fixed & first, const Fixed &second);
		static Fixed &max ( Fixed & first, Fixed &second);
		const static Fixed &max ( const Fixed & first, const Fixed &second);

	private:
		int	value;
		static const int fract = 8;
};

std::ostream& operator<<(std::ostream &outputStream, const Fixed &ref);
#endif