#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		// Constructors
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		
		// Destructor
		~MateriaSource();
		
		// Operators
		MateriaSource & operator=(const MateriaSource &assign);
		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const & type);

		//getter
		bool getSlotOpen(int index);
		AMateria *getItem(int index);

	private:
		bool slotOpen[4];
		AMateria* slots[4];
};

#endif