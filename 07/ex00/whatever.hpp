/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:32:11 by hrings            #+#    #+#             */
/*   Updated: 2022/10/20 09:45:55 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T> 
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T> 
T min(T a, T b)
{
	if ( a > b)
		return b;
	else
		return a;
}

template <typename T> 
T max(T a, T b)
{
	if ( a < b)
		return b;
	else
		return a;
}

#endif
