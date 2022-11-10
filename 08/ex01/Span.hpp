#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
	public:
		// Constructors
		
		Span(unsigned int n);
		Span(const Span &copy);
		
		// Destructor
		~Span();
		
		// Operators
		Span & operator=(const Span &assign);
		void addNumber(unsigned int n);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		size_t shortestSpan(void);
		size_t longestSpan(void);
		size_t getSize() const;
		size_t getMaxSize() const;
		int getElement(size_t n) const;
		class FullException: public std::exception
		{
			virtual const char* what() const throw();
		};
		class OutOfBounds: public std::exception
		{
			virtual const char* what() const throw();
		};
		class ErrorNoSpanPossible: public std::exception
		{
			virtual const char* what() const throw();
		};
		
	private:
		Span();
		std::vector<int> elements;
		size_t size;
		
		
};

std::ostream& operator<< (std::ostream &out, Span const& obj);

#endif
