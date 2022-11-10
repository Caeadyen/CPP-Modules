#include "Span.hpp"

// Constructors
Span::Span()
{
	std::cout << "\033[0;33mDefault Constructor called of Span\033[0m" << std::endl;
}

Span::Span(unsigned int n)
{
	this->size = n;
	std::cout << "\033[0;33mConstructor called of Span\033[0m" << std::endl;
}

Span::Span(const Span &copy)
{
	this->size = copy.getMaxSize();
	this->elements.clear();
	for(size_t i = 0; i < copy.getSize(); i++)
		addNumber(copy.getElement(i));
	std::cout << "\033[0;33mCopy Constructor called of Span\033[0m" << std::endl;
}


// Destructor
Span::~Span()
{
	std::cout << "\033[0;31mDestructor called of Span\033[0m" << std::endl;
}


// Operators
Span & Span::operator=(const Span &assign)
{
	if(this == &assign)
		return (*this);
	this->size = assign.getMaxSize();
	this->elements.clear();
	for(size_t i = 0; i < assign.getSize(); i++)
		addNumber(assign.getElement(i));	
	return *this;
}

void Span::addNumber(unsigned int n)
{
	if(this->elements.size() >= this->size)
		throw FullException();
	else
		elements.push_back(n);
		
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for(std::vector<int>::iterator itr = begin; itr != end; itr++)
		addNumber(*itr);
}

size_t Span::longestSpan(void)
{
	if (this->elements.size() < 2)
		throw ErrorNoSpanPossible();
	long min = *std::min_element(this->elements.begin(), this->elements.end());
	long max = *std::max_element(this->elements.begin(), this->elements.end());
	return (max - min);
}

size_t Span::shortestSpan(void)
{
	long result;
	if (this->elements.size() < 2)
		throw ErrorNoSpanPossible();
	std::sort(this->elements.begin(), this->elements.end());
	result = static_cast<long>(this->elements[1]) - static_cast<long>(this->elements[0]);
	for(std::vector<int>::iterator itr = this->elements.begin() + 2; itr != this->elements.end(); itr++)
		result = std::min(static_cast<long>(*itr) - static_cast<long>(*(itr - 1)), result);
	return (result);
}

size_t Span::getSize() const
{
	return (this->elements.size());
}

size_t Span::getMaxSize() const
{
	return (this->size);
}

int Span::getElement(size_t n) const
{
	if (n < this->elements.size())
		return (this->elements[n]);
	else
		throw OutOfBounds();
}

const char* Span::FullException::what() const throw()
{
	return ("FullException: Span is full");
}

const char* Span::ErrorNoSpanPossible::what() const throw()
{
	return ("ErrorNoSpanPossible: less then 2 Elements");
}

const char* Span::OutOfBounds::what() const throw()
{
	return ("OutOfBounds: Index is out of Bounds");
}

std::ostream& operator<< (std::ostream &out, Span const& obj)
{
	for (size_t i = 0; i < obj.getSize(); i++)
	{
    	out << obj.getElement(i) << ' ';
	}
	return (out);
}
