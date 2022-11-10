#include "Dog.hpp"

// Constructors
Dog::Dog()
{
	this->type = "Dog";
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
}

Dog::Dog(const Dog &copy): Animal()
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
}


// Destructor
Dog::~Dog()
{
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}


// Operators
Dog & Dog::operator=(const Dog &assign)
{
	if (this== &assign)
		return (*this);
	this->type = assign.type;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Dog makes a sound" << std::endl;
}