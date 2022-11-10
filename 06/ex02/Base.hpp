/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:02:18 by hrings            #+#    #+#             */
/*   Updated: 2022/10/12 13:38:24 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <stdlib.h>
# include <iostream>

class Base
{
	public:
		Base();
		virtual ~Base();
		virtual void whoAmI();
};

Base *generate(void);

#endif