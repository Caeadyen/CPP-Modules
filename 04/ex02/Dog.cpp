#include "Dog.hpp"

// Constructors
Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
}

Dog::Dog(const Dog &copy): Animal(), brain(new Brain(*copy.getBrain()))
{
	this->type = copy.getType();
	std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
}


// Destructor
Dog::~Dog()
{
	delete this->brain;
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}


// Operators
Dog & Dog::operator=(const Dog &assign)
{
	std::cout << "\e[0;33mAssign Operator called of Dog\e[0m" << std::endl;
	if (this== &assign)
		return (*this);
	this->type = assign.type;
	delete this->brain;
	this->brain = new Brain(*assign.getBrain());
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Dog makes a sound" << std::endl;
}
Brain* Dog::getBrain() const
{
	return (this->brain);
}