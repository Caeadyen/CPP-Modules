#include "Brain.hpp"

// Constructors
Brain::Brain()
{
	this->ideaIndex = -1;
	std::cout << "\e[0;33mDefault Constructor called of Brain\e[0m" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	int index;

	index = 0;
	while (index <= copy.ideaIndex)
	{
		this->ideas[index] = copy.ideas[index];
		index++;
	}
	this->ideaIndex = copy.ideaIndex;
	std::cout << "\e[0;33mCopy Constructor called of Brain\e[0m" << std::endl;
}


// Destructor
Brain::~Brain()
{
	std::cout << "\e[0;31mDestructor called of Brain\e[0m" << std::endl;
}


// Operators
Brain & Brain::operator=(const Brain &assign)
{
	int index;
	std::cout << "\e[0;33mAssign Operator called of Brain\e[0m" << std::endl;
	if (this != &assign)
	{
		index = 0;
		while (index <= assign.ideaIndex)
		{
			this->ideas[index] = assign.ideas[index];
			index++;
		}
		this->ideaIndex = assign.ideaIndex;
	}
	return *this;
}

std::string Brain::getIdea(int n)
{
	int index;

	index = n % 100;
	if ((this->ideaIndex >= 0) && (index <= this->ideaIndex))
		return (this->ideas[index]);
	else
		return (std::string());
}

void Brain::addIdea(std::string idea)
{
	if (this->ideaIndex < 99)
	{
		this->ideaIndex++;
		this->ideas[this->ideaIndex] = idea;
	}
}

void	Brain::removeIdea()
{
	if (this->ideaIndex >= 0)
	{
		this->ideaIndex--;
	}
}