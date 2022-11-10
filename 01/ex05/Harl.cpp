#include "Harl.hpp"

// Constructors
Harl::Harl()
{
	init();
	std::cout << "\e[0;33mDefault Constructor called of Harl\e[0m" << std::endl;
}
void Harl::init(void)
{
	comments[0].name = "UNKNOWN";
	comments[0].ptr = &Harl::unknown;
	comments[1].name = "DEBUG";
	comments[1].ptr = &Harl::debug;
	comments[2].name = "INFO";
	comments[2].ptr = &Harl::info;
	comments[3].name = "WARNING";
	comments[3].ptr = &Harl::warning;
	comments[4].name = "ERROR";
	comments[4].ptr = &Harl::error;
}

// Destructor
Harl::~Harl()
{
	std::cout << "\e[0;31mDestructor called of Harl\e[0m" << std::endl;
}


void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup ";
	std::cout << "burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started ";
	std::cout << "working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now" << std::endl;
}

void Harl::unknown( void )
{
	std::cout << "[ UNKNOWN ]" << std::endl;
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::complain(std::string level)
{
	int	index;

	index = (level == "DEBUG") + \
			(level == "INFO") * 2+ \
			(level == "WARNING") * 3+ \
			(level == "ERROR") * 4;
	(this->*(comments[index].ptr))();

}
