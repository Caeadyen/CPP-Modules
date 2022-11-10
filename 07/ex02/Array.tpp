/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:45:51 by hrings            #+#    #+#             */
/*   Updated: 2022/10/20 12:49:57 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"

template <typename T>
Array<T>::Array(void)
{
	std::cout << "\033[0;33mDefault Constructor called of Array\033[0m" << std::endl;
	this->length = 0;
	this->array = NULL;
}

template <typename T>
Array<T>::Array(unsigned int len)
{
	std::cout << "\033[0;33mConstructor called of Array\033[0m" << std::endl;
	this->length = len;
	if (len == 0)
		this->array = NULL;
	else
		this->array = new T[len];
}

template <typename T>
Array<T>::~Array(void)
{
	std::cout << "\033[0;31mDestructor called of Array\033[0m" << std::endl;
	if(this->length != 0)
		delete[] this->array;
}

template <typename T>
Array<T>::Array(Array<T> const &copy)
{
	unsigned int index = 0;
	std::cout << "\033[0;33mCopy Constructor called of Array\033[0m" << std::endl;
	this->length = copy.size();
	if (this->length == 0)
		this->array = NULL;
	else
	{
		this->array = new T[this->length];
		while (index < this->length)
		{
			this->array[index] = copy[index];
			index++;
		}
	}
}

template <typename T>
Array<T> & Array<T>::operator=(Array<T> const &other)
{
	unsigned int index = 0;
	std::cout << "\033[0;33mAssignment called of Array\033[0m" << std::endl;
	if (this == &other)
		return *this;
	if (this->length != 0)
		delete[] this->array;
	this->length = other.size();
	if (this->length == 0)
		this->array = NULL;
	else
	{
		this->array = new T[this->length];
		while (index < this->length)
		{
			this->array[index] = other[index];
			index++;
		}
	}
	return (*this);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->length);
}

template <typename T>
T& Array<T>::operator[](unsigned int index) const
{
	if(index >= this->length)
		throw OutOfBoundsException();
	return (this->array[index]);
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Error: The index is out of bounds");
}

template <typename T>
std::ostream& operator<< (std::ostream &out, Array<T> const& obj)
{
	return out << obj.size();
}
