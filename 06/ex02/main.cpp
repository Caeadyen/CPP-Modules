/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:19:27 by hrings            #+#    #+#             */
/*   Updated: 2022/10/19 10:12:32 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Identify.hpp"

int main(void)
{
	int count = 10;
	srand(time(NULL));
	{
		std::cout << "\e[0;32m----- Test Pointer identify --------\e[0m" << std::endl;
		std::cout << "\e[0;32m on Class A: \e[0m" << std::endl;
		Base *a = new A();
		a->whoAmI();
		identify(a);
		delete a;
		std::cout << "\e[0;32m on Class B: \e[0m" << std::endl;
		Base *b = new B();
		b->whoAmI();
		identify(b);
		delete b;
		std::cout << "\e[0;32m on Class C: \e[0m" << std::endl;
		Base *c = new C();
		c->whoAmI();
		identify(c);
		delete c;
	}
	{
		std::cout << "\e[0;32m----- Test Reference identify --------\e[0m" << std::endl;
		std::cout << "\e[0;32m on Class A: \e[0m" << std::endl;
		Base *a = new A();
		a->whoAmI();
		identify(*a);
		delete a;
		std::cout << "\e[0;32m on Class B: \e[0m" << std::endl;
		Base *b = new B();
		b->whoAmI();
		identify(*b);
		delete b;
		std::cout << "\e[0;32m on Class C: \e[0m" << std::endl;
		Base *c = new C();
		c->whoAmI();
		identify(*c);
		delete c;
	}
	{
		std::cout << "\e[0;32m----- Test generate Function --------\e[0m" << std::endl;
		for (int i = 1; i <= count; i++)
		{
			std::cout << "\e[0;32mRandom test Number: " << i <<".\e[0m" << std::endl;
			Base *test = generate();
			std::cout << "\e[0;32mThe Pointer points to class: \e[0m";
			test->whoAmI();
			std::cout << "\e[0;32mIdentify by pointer        : \e[0m";
			identify(test);
			std::cout << "\e[0;32mIdentify by reference      : \e[0m";
			identify(*test);
			delete test;
		}
		
	}
	return (0);
}

