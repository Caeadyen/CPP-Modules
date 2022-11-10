#include "Character.hpp"

// Constructors
Character::Character()
{
	int index;
	index = 0;
	while (index < 4)
		slotsOpen[index++] = true;
	this->name = std::string();
	//std::cout << "\e[0;33mDefault Constructor called of Character\e[0m" << std::endl;
}

Character::Character(std::string name)
{
	int index;
	index = 0;
	while (index < 4)
		slotsOpen[index++] = true;
	this->name = name;
	//std::cout << "\e[0;33mName Constructor called of Character\e[0m" << std::endl;
}

Character::Character(const Character &copy)
{
	int index;

	index = 0;
	this->name = copy.getName();
	while (index < 4)
	{
		if (!copy.slotsOpen[index])
		{
			this->slotsOpen[index] = false;
			this->inventory[index] = copy.inventory[index]->clone();
		}
		else
			this->slotsOpen[index] = true;
		index++;
	}
	std::cout << "\e[0;33mCopy Constructor called of Character\e[0m" << std::endl;
}


// Destructor
Character::~Character()
{
	int index;

	index = 0;
	while (index < 4)
	{
		if (!this->slotsOpen[index])
			delete this->inventory[index];
		index++;
	}
	//std::cout << "\e[0;31mDestructor called of Character\e[0m" << std::endl;
}


// Operators
Character & Character::operator=(const Character &assign)
{
	int index;

	index = 0;
	this->name = assign.getName();
	while (index < 4)
	{
		if (!assign.slotsOpen[index])
		{
			if (!this->slotsOpen[index])
				delete this->inventory[index];
			this->slotsOpen[index] = false;
			this->inventory[index] = assign.inventory[index]->clone();
		}
		else
		{
			if (!this->slotsOpen[index])
				delete this->inventory[index];
			this->slotsOpen[index] = true;
		}
		index++;
	}
	std::cout << "\e[0;33mAssignment Constructor called of Character\e[0m" << std::endl;
	return *this;
}

//getter

bool Character::getSlotOpen(int index)
{
	if (index >= 0 && index <= 4)
		return (this->slotsOpen[index]);
	else
		return (false);
}

AMateria *Character::getItem(int index)
{
	if (index >= 0 && index <= 4)
		return (this->inventory[index]);
	return (NULL);
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	int index;

	index = 0;
	while (index < 4)
	{
		if(slotsOpen[index])
		{
			this->inventory[index] = m;
			this->slotsOpen[index] = false;
			return ;
		}
		index++;
	}
	std::cout << "Inventory is full." << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 4)
	{
		if (!this->slotsOpen[idx])
		{
			this->slotsOpen[idx] = true;
			this->inventory[idx] = NULL;
		}
	}
	else
		std::cout << "Slot " << idx << " is not a valid Slot." << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 4)
	{
		if (!this->slotsOpen[idx])
			this->inventory[idx]->use(target);
		else
			std::cout << "Slot " << idx << " is empty." << std::endl;
	}
	else
		std::cout << "Slot " << idx << " is not a valid Slot." << std::endl;
}
