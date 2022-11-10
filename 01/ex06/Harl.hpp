#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>


class Harl
{
	typedef struct comments
	{
		std::string name;
		void(Harl::*ptr)(void);
	}	t_comments;
	public:
		// Constructors
		Harl();

		// Destructor
		~Harl();
		
		void complain( std::string level );
		
	private:
		t_comments comments[5];
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		void unknown( void );
		void init(void);
};

#endif