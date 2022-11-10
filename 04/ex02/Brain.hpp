#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	public:
		// Constructors
		Brain();
		Brain(const Brain &copy);
		
		// Destructor
		~Brain();
		
		// Operators
		Brain & operator=(const Brain &assign);
		//getter
		std::string getIdea(int n);

		//setter
		void	addIdea(std::string idea);
		void	removeIdea();
	private:
		std::string ideas[100];
		int ideaIndex;
};

#endif