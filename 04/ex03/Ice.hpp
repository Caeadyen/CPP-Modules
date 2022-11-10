#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice: public AMateria
{
	public:
		// Constructors
		Ice();
		Ice(const Ice &copy);
		
		// Destructor
		virtual ~Ice();
		
		// Operators
		Ice & operator=(const Ice &assign);
		AMateria* clone(void) const;
				
	private:
		
};

#endif