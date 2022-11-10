/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:38:48 by hrings            #+#    #+#             */
/*   Updated: 2022/10/20 12:49:49 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template< typename T >
class Array
{
	public:
		Array(void);
		Array(unsigned int len);
		~Array(void);
		Array(Array<T> const &copy);
		Array<T> & operator=(Array<T> const &other);
		unsigned int size() const;
		T& operator[](unsigned int index) const;	
		class OutOfBoundsException: public std::exception
		{
			virtual const char* what() const throw();
		};
	private:
		unsigned int length;
		T* 	array;
};

#include "Array.tpp"
	
#endif
