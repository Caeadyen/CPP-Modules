/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:58:50 by hrings            #+#    #+#             */
/*   Updated: 2022/08/19 17:10:18 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	turns;

	turns = orientation(a,b,point) + \
			orientation(b,c,point) + \
			orientation(c,a,point);
	if (turns == Fixed(3))
		return (true);
	else if (turns == Fixed(-3))
		return (true);
	else	
		return (false);
}

int	orientation(Point const a, Point const b, Point const c)
{
	Point ab;
	Point ac;

	ab = vector(a, b);
	ac = vector(a, c);
	if (zcomponent(ab,ac) > 0)
		return (1);
	else
		return (-1);
}