#include "Data.hpp"

// Constructors
Data::Data()
{
	this->value = 0;
	std::cout << "\e[0;33mDefault Constructor called of Data\e[0m" << std::endl;
}

Data::Data(int num)
{
	this->value = num;
	std::cout << "\e[0;33mConstructor called of Data\e[0m" << std::endl;
}

Data::Data(const Data &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Data\e[0m" << std::endl;
}


// Destructor
Data::~Data()
{
	std::cout << "\e[0;31mDestructor called of Data\e[0m" << std::endl;
}


// Operators
Data & Data::operator=(const Data &assign)
{
	(void) assign;
	return *this;
}

//getter

int Data::getValue() const
{
	return (this->value);
}