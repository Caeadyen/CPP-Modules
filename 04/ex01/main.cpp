/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:12:24 by hrings            #+#    #+#             */
/*   Updated: 2022/10/04 09:44:19 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
# include "Dog.hpp"

void subject_test();
void copy_test();
void assign_test();
void brain_test();

int main()
{
	subject_test();
	copy_test();
	assign_test();
	brain_test();
	//from the eval sheet, already test before
	Dog basic;
	{
		Dog tmp = basic;
	}
	return (0);
}

void subject_test()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "Dog is a : " <<j->getType() << " " << std::endl;
	std::cout << "Cat is a : " << i->getType() << " " << std::endl;
	std::cout << "Cat: ";
	i->makeSound(); //will output the cat sound!
	std::cout << "Dog: ";
	j->makeSound();
	delete i;
	delete j;
}

void copy_test()
{
	std::cout << "=====COPY TESTING=====" << std::endl;
	std::cout << "=====CAT=====" << std::endl;

	// in this case, Kitty and copycat are pure cats
	// and so everything can be copied over. same goes for dog.
	Cat	*kitty = new Cat();
	kitty->getBrain()->addIdea("Scratch.");
	kitty->getBrain()->addIdea("Chase mouse!");
	kitty->getBrain()->addIdea("Cry about food!");

	std::cout << "=====kitty made=====" << std::endl;
	
	Cat *copycat = new Cat(*kitty);
	std::cout << "=====copycat made=====" << std::endl;
	copycat->getBrain()->removeIdea();

	
	std::cout << "kitty is firstly thinking (ideas[0]) about: " << kitty->getBrain()->getIdea(0) << std::endl;
	std::cout << "kitty is secondly thinking (ideas[1]) about: " << kitty->getBrain()->getIdea(1) << std::endl;
	std::cout << "kitty is thirdly thinking (ideas[2]) about: " << kitty->getBrain()->getIdea(2)<< std::endl;
	

	std::cout << "copycat is firstly thinking (ideas[0]) about: " << copycat->getBrain()->getIdea(0) << std::endl;
	std::cout << "copycat is secondly thinking (ideas[1]) about: " << copycat->getBrain()->getIdea(1) << std::endl;
	std::cout << "copycat is thirdly thinking (ideas[2]) about: " << copycat->getBrain()->getIdea(2) << std::endl;

	delete kitty;
	delete copycat;
	std::cout << "=====DOG=====" << std::endl;
	Dog	puppy = Dog();

	puppy.getBrain()->addIdea("sleep.");
	puppy.getBrain()->addIdea("Chase ball!");
	puppy.getBrain()->addIdea("HOWLLLLL!");
	Dog rogerdog(puppy);// = Dog(puppy);
	std::cout << "=====rogerdog made=====" << std::endl;
	rogerdog.getBrain()->removeIdea();
	
	std::cout << "puppy is firstly thinking (ideas[0]) about: " << puppy.getBrain()->getIdea(0) << std::endl;
	std::cout << "puppy is secondly thinking (ideas[1]) about: " << puppy.getBrain()->getIdea(1) << std::endl;
	std::cout << "puppy is thirdly thinking (ideas[2]) about: " << puppy.getBrain()->getIdea(2) << std::endl;
	
	
	std::cout << "rogerdog is firstly thinking (ideas[0]) about: " << rogerdog.getBrain()->getIdea(0) << std::endl;
	std::cout << "rogerdog is secondly thinking (ideas[1]) about: " << rogerdog.getBrain()->getIdea(1) << std::endl;
	std::cout << "rogerdog is thirdly thinking (ideas[2]) about: " << rogerdog.getBrain()->getIdea(2) << std::endl; 
}

void assign_test()
{
	Cat	*kitty = new Cat();
	Cat	cpy;
	kitty->getBrain()->addIdea("Scratch.");
	kitty->getBrain()->addIdea("Chase mouse!");
	kitty->getBrain()->addIdea("Cry about food!");
	std::cout << "=====cpy made=====" << std::endl;
	cpy = *kitty;
	std::cout << "=====copy of cpy made and removed 2 ideas=====" << std::endl;
	cpy.getBrain()->removeIdea();
	cpy.getBrain()->removeIdea();
	
	std::cout << "kitty is firstly thinking (ideas[0]) about: " << kitty->getBrain()->getIdea(0) << std::endl;
	std::cout << "kitty is secondly thinking (ideas[1]) about: " << kitty->getBrain()->getIdea(1) << std::endl;
	std::cout << "kitty is thirdly thinking (ideas[2]) about: " << kitty->getBrain()->getIdea(2)<< std::endl;
	
	std::cout << "cpy is firstly thinking (ideas[0]) about: " << cpy.getBrain()->getIdea(0) << std::endl;
	std::cout << "cpy is secondly thinking (ideas[1]) about: " << cpy.getBrain()->getIdea(1) << std::endl;
	std::cout << "cpy is thirdly thinking (ideas[2]) about: " << cpy.getBrain()->getIdea(2) << std::endl;

	delete kitty;
	std::cout << "=====new DOG=====" << std::endl;
	Dog	*pup = new Dog();

	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	
	Dog copydog;
	copydog = *pup;

	copydog.getBrain()->removeIdea();
	std::cout << "=====copy of pup made and removed 1 idea=====" << std::endl;
	
	std::cout << "pup is firstly thinking (ideas[0]) about: " << pup->getBrain()->getIdea(0) << std::endl;
	std::cout << "pup is secondly thinking (ideas[1]) about: " << pup->getBrain()->getIdea(1) << std::endl;
	std::cout << "pup is thirdly thinking (ideas[2]) about: " << pup->getBrain()->getIdea(2) << std::endl;
	
	std::cout << "copydog is firstly thinking (ideas[0]) about: " << copydog.getBrain()->getIdea(0) << std::endl;
	std::cout << "copydog is secondly thinking (ideas[1]) about: " << copydog.getBrain()->getIdea(1) << std::endl;
	std::cout << "copydog is thirdly thinking (ideas[2]) about: " << copydog.getBrain()->getIdea(2) << std::endl;

	delete pup;
}

void brain_test()
{
	Dog	*pup = new Dog();
	
	std::cout << "=====Testing of Brain functions=====" << std::endl << std::endl;
	
	pup->getBrain()->addIdea("sleep.");
	std::cout << "pup is firstly thinking (ideas[0]) about: " << pup->getBrain()->getIdea(0) << std::endl;
	
	std::cout << "=====remove all ideas=====" << std::endl;
	pup->getBrain()->removeIdea();
	pup->getBrain()->removeIdea();
	
	std::cout << "pup is firstly thinking (ideas[0]) about: " << pup->getBrain()->getIdea(0) << std::endl;
	
	std::cout << "=====adding 100+ ideas=====" << std::endl;
	pup->getBrain()->addIdea("first is sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("sleep.");
	pup->getBrain()->addIdea("Chase ball!");
	pup->getBrain()->addIdea("HOWLLLLL!");
	pup->getBrain()->addIdea("99 is HOWLLLLL!");
	pup->getBrain()->addIdea("this isnt added sleep.");
	pup->getBrain()->addIdea("Chase ball!");


	std::cout << "pup is firstly thinking (ideas[100] or more 0) about: " << pup->getBrain()->getIdea(100) << std::endl;
	std::cout << "pup is thirdly thinking (ideas[99]) about: " << pup->getBrain()->getIdea(99) << std::endl;
	
	delete pup;
}
