/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:12:24 by hrings            #+#    #+#             */
/*   Updated: 2022/09/30 11:57:18 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"
# include "Character.hpp"

#include "Ice.hpp"
#include "Cure.hpp"

void subject_test();
void extra_base_test();
void char_copy_test();

int main()
{
	subject_test();
	extra_base_test();
	char_copy_test();
	return (0);
}

void subject_test()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}
void extra_base_test()
{
	std::cout << std::endl << "--- some extra test ---" << std::endl << std::endl;
	std::cout << std::endl << "--- learning more then 4 Materia ---" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	ICharacter* me = new Character("me");
	std::cout << std::endl << "--- add more then 4 Materia to a char---" << std::endl;
	AMateria* tmp;
	AMateria* tmp2;
	me->equip(src->createMateria("ice"));
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));
	tmp = src->createMateria("ice");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	std::cout << std::endl << "--- using Materia thats there and not there ---" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(5, *bob);
	me->unequip(1);
	me->use(1, *bob);
	
	delete tmp;
	delete tmp2;
	delete bob;
	delete me;
	delete src;
}

void char_copy_test()
{
	std::cout << std::endl << "--- testing copy and assignment from Character ---" << std::endl << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	Character* me = new Character("me");
	AMateria* tmp;
	me->equip(src->createMateria("ice"));
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));
	std::cout << std::endl << "--- Calling the copy constructor ---" << std::endl;
	Character* bob = new Character(*me);
	std::cout << std::endl << "--- unequip an item on the original and using it on both---" << std::endl;
	me->unequip(1);
	me->use(1, *bob);
	bob->use(1, *me);

	Character fred;	
	me->equip(tmp);
	std::cout << std::endl << "--- Calling the assigment constructor ---" << std::endl;	
	fred = *bob;
	std::cout << std::endl << "--- unequip an item on the original and using it on both---" << std::endl;
	me->unequip(1);
	me->use(1, fred);
	fred.use(1, *me);
	
	delete tmp;
	delete bob;
	delete me;
	delete src;
}