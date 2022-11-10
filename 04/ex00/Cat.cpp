#include "Cat.hpp"

// Constructors
Cat::Cat()
{
	this->type = "Cat";
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy): Animal()
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}


// Destructor
Cat::~Cat()
{
	
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}


// Operators
Cat & Cat::operator=(const Cat &assign)
{
	if (this== &assign)
		return (*this);
	this->type = assign.type;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Cat makes a sound" << std::endl;
}