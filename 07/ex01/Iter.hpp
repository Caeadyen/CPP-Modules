/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:52:22 by hrings            #+#    #+#             */
/*   Updated: 2022/10/20 09:46:03 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T *a, int len, void (*f)(T&))
{
	int index;

	index = 0;
	while (index < len)
		(*f)(a[index++]);
}

template <typename T>
void iter(T const *a, int len, void (*f)(const T&))
{
	int index;

	index = 0;
	while (index < len)
		(*f)(a[index++]);
}

#endif
