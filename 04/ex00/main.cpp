/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:12:24 by hrings            #+#    #+#             */
/*   Updated: 2022/09/30 12:24:04 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongCat.hpp"


int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wronganimal = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();

	std::cout << "Dog is a : " <<j->getType() << " " << std::endl;
	std::cout << "Cat is a : " << i->getType() << " " << std::endl;
	std::cout << "WrongAnimal is a: " << wronganimal->getType() << " " << std::endl;
	std::cout << "WrongCat is a: " << wrongcat->getType() << " " << std::endl;
	std::cout << "Cat: ";
	i->makeSound(); //will output the cat sound!
	std::cout << "Dog: ";
	j->makeSound();
	std::cout << "Animal: ";
	meta->makeSound();
	std::cout << "WrongAnimal: ";
	wronganimal->makeSound();
	std::cout << "WrongCat: ";
	wrongcat->makeSound();
	delete j;
	delete i;
	delete meta;
	delete wronganimal;
	delete wrongcat;
	return (0);
}