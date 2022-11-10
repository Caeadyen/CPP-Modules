#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"


class Character: public ICharacter
{
	public:
		// Constructors
		Character();
		Character(std::string name);
		Character(const Character &copy);
		
		// Destructor
		~Character();
		
		// Operators
		Character & operator=(const Character &assign);

		//getter
		std::string const & getName() const;
		bool getSlotOpen(int index);
		AMateria *getItem(int index);
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		std::string name;
		bool slotsOpen[4];
		AMateria *inventory[4];
};

#endif