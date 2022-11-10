/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:58:54 by hrings            #+#    #+#             */
/*   Updated: 2022/09/18 15:07:14 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructors
Point::Point(): x(0),y(0)
{
	if (DEBUGP)
		std::cout << "\e[0;33mDefault Constructor called of Point\e[0m" << std::endl;
}

Point::Point(float xx, float yy): x(xx),y(yy)
{
	if (DEBUGP)
		std::cout << "\e[0;33mDefault Constructor called of Point\e[0m" << std::endl;
}

Point::Point(const Point &copy): x(copy.getX()), y(copy.getY())
{
	if (DEBUGP)
		std::cout << "\e[0;33mCopy Constructor called of Point\e[0m" << std::endl;
}


// Destructor
Point::~Point()
{
	if (DEBUGP)
		std::cout << "\e[0;31mDestructor called of Point\e[0m" << std::endl;
}


// Operators
Point & Point::operator=(const Point &assign)
{
	if (DEBUGP)
		std::cout << "\e[0;33mOperators = called of Fixed\e[0m" << std::endl;
	if (&assign != this)
	{
		this->~Point();
		new (this) Point(assign.getX().toFloat(), assign.getY().toFloat());
	}
	return (*this);
}

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}

Point vector(Point a, Point b)
{
	return (Point( (b.getX()-a.getX()).toFloat(), \
					(b.getY()- a.getY()).toFloat()));
}

Fixed zcomponent(Point a, Point b)
{
	return (Fixed((a.getX() * b.getY() - a.getY() * b.getX())).toFloat());
}