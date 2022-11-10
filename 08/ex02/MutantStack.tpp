/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:57:25 by hrings            #+#    #+#             */
/*   Updated: 2022/10/20 23:10:30 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>()
{
	std::cout << "\033[0;33mDefault Constructor called of MutantStack\033[0m" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) : std::stack<T>(copy)
{
	std::cout << "\033[0;33mCopy Constructor called of MutantStack\033[0m" << std::endl;
}
template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "\033[0;31mDestructor called of MutantStack\033[0m" << std::endl;
}
		
template <typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack &assign)
{
	std::cout << "\033[0;33mAssignment called of MutantStack\033[0m" << std::endl;
	if (this == &assign)
		return (*this);
    std::stack<T>::operator=(assign);
    return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return(std::stack<T>::c.begin());
}


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return(std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() 
{ 
	return this->std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return this->std::stack<T>::c.rend();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return this->std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return this->std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return this->std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return this->std::stack<T>::c.rend();
}
