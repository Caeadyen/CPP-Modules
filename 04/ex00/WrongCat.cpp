#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "\e[0;33mDefault Constructor called of WrongCat\e[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal()
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of WrongCat\e[0m" << std::endl;
}


// Destructor
WrongCat::~WrongCat()
{
	std::cout << "\e[0;31mDestructor called of WrongCat\e[0m" << std::endl;
}


// Operators
WrongCat & WrongCat::operator=(const WrongCat &assign)
{
	if (this== &assign)
		return (*this);
	this->type = assign.type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat makes a sound" << std::endl;
}