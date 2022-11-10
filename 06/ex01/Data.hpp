#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

struct Data
{
	public:
		// Constructors
		Data();
		Data(int num);
		Data(const Data &copy);
		
		// Destructor
		~Data();
		
		// Operators
		Data & operator=(const Data &assign);
		
		int getValue() const;
	private:
		int value;
};

#endif