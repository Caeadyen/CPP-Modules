/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:49:02 by hrings            #+#    #+#             */
/*   Updated: 2022/09/18 14:49:03 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>
# include "Fixed.hpp"

# define DEBUGP 0

class Point
{
	public:
		// Constructors
		Point();
		Point(float xx, float yy);
		Point(const Point &copy);
		
		// Destructor
		~Point();
		
		// Operators
		Point & operator=(const Point &assign);

		Fixed getX() const;
		Fixed getY() const;
		
	private:
		Fixed const x;
		Fixed const y;
		
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
int	orientation(Point const a, Point const b, Point const c);
Point vector(Point a, Point b);
Fixed zcomponent(Point a, Point b);

#endif