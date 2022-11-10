#include "Cat.hpp"

// Constructors
Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy): Animal(), brain(new Brain(*copy.getBrain()))
{
	this->type = copy.getType();
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}


// Destructor
Cat::~Cat()
{
	delete this->brain;
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}


// Operators
Cat & Cat::operator=(const Cat &assign)
{
	std::cout << "\e[0;33mAssign Operator called of Cat\e[0m" << std::endl;
	if (this== &assign)
		return (*this);
	this->type = assign.type;
	delete this->brain;
	this->brain = new Brain(*assign.getBrain());
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Cat makes a sound" << std::endl;
}

Brain* Cat::getBrain() const
{
	return (this->brain);
}