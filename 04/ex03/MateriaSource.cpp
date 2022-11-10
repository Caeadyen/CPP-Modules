#include "MateriaSource.hpp"

// Constructors
MateriaSource::MateriaSource()
{
	int index;

	index = 0;
	while (index < 4)
		this->slotOpen[index++] = true;
	//std::cout << "\e[0;33mDefault Constructor called of MateriaSource\e[0m" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	int index;

	index = 0;
	while (index < 4)
	{
		if (!this->slotOpen[index])
			delete this->slots[index];
		if (!copy.slotOpen[index])
		{
			this->slotOpen[index] = false;
			this->slots[index] = copy.slots[index];
		}
		index++;
	}
	//std::cout << "\e[0;33mCopy Constructor called of MateriaSource\e[0m" << std::endl;
}


// Destructor
MateriaSource::~MateriaSource()
{
	int index;

	index = 0;
	while (index < 4)
	{
		if(!this->slotOpen[index])
			delete this->slots[index];
		index++;
	}
	//std::cout << "\e[0;31mDestructor called of MateriaSource\e[0m" << std::endl;
}


// Operators
MateriaSource & MateriaSource::operator=(const MateriaSource &assign)
{
	int index;

	index = 0;
	while (index < 4)
	{
		if (!this->slotOpen[index])
			delete this->slots[index];
		if (!assign.slotOpen[index])
		{
			this->slotOpen[index] = false;
			this->slots[index] = assign.slots[index];
		}
		index++;
	}
	return *this;
}

//getter

bool MateriaSource::getSlotOpen(int index)
{
	if (index >= 0 && index <= 4)
		return (this->slotOpen[index]);
	else
		return (false);
}

AMateria *MateriaSource::getItem(int index)
{
	if (index >= 0 && index <= 4)
		return (this->slots[index]);
	return (NULL);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	int index;

	index = 0;
	while (index < 4)
	{
		if (slotOpen[index])
		{
			slots[index] = materia;
			slotOpen[index] = false;
			std::cout << materia->getType() << " was added at slot " << index << std::endl;
			return ;
		}
		index++;
	}
	delete materia;
	std::cout << "Can't learn anymore Materia" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int	index;

	index = 0;
	while (index < 4)
	{
		if(!slotOpen[index] && this->slots[index]->getType() == type)
			return (this->slots[index]->clone());
		index++;
	}
	return (0);
}
