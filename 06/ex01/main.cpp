/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:19:27 by hrings            #+#    #+#             */
/*   Updated: 2022/10/11 13:17:36 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <stdint.h>

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

int main(void)
{
	Data	*data;
	uintptr_t	serialized;
	Data	*deserialized;

	data = new Data(42);
	std::cout << "data pointer is = " << data << std::endl;
	std::cout << "and his value   = " << data->getValue() << std::endl;

	serialized = serialize(data);
	std::cout << "serialize(data ptr) = " << serialized << std::endl;

	deserialized = deserialize(serialized);

	std::cout << "data pointer is = " << deserialized << std::endl;
	std::cout << "and his value   = " << deserialized->getValue() << std::endl;
		
	delete data;
	return (0);
}

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
