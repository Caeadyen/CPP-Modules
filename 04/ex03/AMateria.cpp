#include "AMateria.hpp"

// Constructors
AMateria::AMateria()
{
	this->type = std::string();
	//std::cout << "\e[0;33mDefault Constructor called of AMateria\e[0m" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
	//std::cout << "\e[0;33mType Constructor called of AMateria\e[0m" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	this->type = copy.getType();
	*this = copy;
	//std::cout << "\e[0;33mCopy Constructor called of AMateria\e[0m" << std::endl;
}


// Destructor
AMateria::~AMateria()
{
	//std::cout << "\e[0;31mDestructor called of AMateria\e[0m" << std::endl;
}


// Operators
AMateria & AMateria::operator=(const AMateria &assign)
{
	this->type = assign.getType();
	return *this;
}

std::string const & AMateria::getType() const
{
	return (this->type);
}
void AMateria::use(ICharacter& target)
{
	if(this->type == "cure")
		std::cout << "* heals " << target.getName() << "'s wound *" << std::endl;
	else if(this->type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else
		std::cout << "* unknown material *" << std::endl;
}