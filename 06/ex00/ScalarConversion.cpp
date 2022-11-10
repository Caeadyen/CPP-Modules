/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:59:15 by hrings            #+#    #+#             */
/*   Updated: 2022/10/18 09:37:02 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

// Constructors
ScalarConversion::ScalarConversion()
{
	std::cout << "\e[0;33mDefault Constructor called of ScalarConversion\e[0m" << std::endl;
}

ScalarConversion::ScalarConversion(const char *input)
{
	std::cout << "\e[0;33mConstructor called of ScalarConversion\e[0m" << std::endl;
	this->input = std::string(input);
	this->type = checkType();
	convertInput();
	convertToOthers();
}
ScalarConversion::ScalarConversion(const ScalarConversion &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of ScalarConversion\e[0m" << std::endl;
}


// Destructor
ScalarConversion::~ScalarConversion()
{
	std::cout << "\e[0;31mDestructor called of ScalarConversion\e[0m" << std::endl;
}

//error
ScalarConversion::TypeConvertError::TypeConvertError()
{
	this->error = undefined;
}

ScalarConversion::TypeConvertError::TypeConvertError(const Error error)
{
	this->error = error;
}

const char* ScalarConversion::TypeConvertError::what() const throw()
{
	switch (error)
	{
	case intSize:
		return ("Overflow of int");
		break;
	case analyseError:
		return ("Error on Parsing the input");
		break;
	default:
		return ("Unknown Error, ohoh");
		break;
	}
}

// Operators
ScalarConversion & ScalarConversion::operator=(const ScalarConversion &assign)
{
	(void) assign;
	return *this;
}

void ScalarConversion::convertToOthers()
{
	switch(this->type)
	{
		case charType:
			fromChar();
			break;
		case intType:
			fromInt();
			break;
		case floatType:
			fromFloat();
			break;
		case doubleType:
			fromDouble();
			break;
		default:
			throw TypeConvertError(TypeConvertError::analyseError);
	}
}

void ScalarConversion::fromChar()
{
	this->intValue = static_cast<int>(this->charValue);
	this->intPos = possible;
	this->floatValue = static_cast<float>(this->charValue);
	this->doubleValue = static_cast<double>(this->charValue);
}

void ScalarConversion::fromInt()
{
	this->charValue = static_cast<char>(this->intValue);
	if (this->intValue > CHAR_MAX || this->intValue < CHAR_MIN - 1)
		this->charPos = impossible;
	else if (isprint(this->charValue))
		this->charPos = possible;
	else
		this->charPos = notDisplayable;
	this->floatValue = static_cast<float>(this->intValue);
	this->doubleValue = static_cast<double>(this->intValue);
}

void ScalarConversion::fromFloat()
{
	this->intValue = static_cast<int>(this->floatValue);
	if (this->floatValue > INT_MAX || this->floatValue < INT_MIN || isnan(this->floatValue) || (this->intValue * this->floatValue) < 0)
		this->intPos = impossible;
	else
		this->intPos = possible;	
	this->charValue = static_cast<char>(this->floatValue);
	if (this->floatValue > CHAR_MAX + 1|| this->floatValue < CHAR_MIN - 1 || isnan(this->floatValue))
		this->charPos = impossible;
	else if (isprint(this->charValue))
		this->charPos = possible;
	else
		this->charPos = notDisplayable;
	this->doubleValue = static_cast<double>(this->floatValue);
}

void ScalarConversion::fromDouble()
{
	this->intValue = static_cast<int>(this->doubleValue);
	if (this->doubleValue > INT_MAX || this->doubleValue < INT_MIN || isnan(this->doubleValue))
		this->intPos = impossible;
	else
		this->intPos = possible;	
	this->charValue = static_cast<char>(this->doubleValue);
	if (this->doubleValue > CHAR_MAX + 1|| this->doubleValue < CHAR_MIN || isnan(this->doubleValue))
		this->charPos = impossible;
	else if (isprint(this->charValue))
		this->charPos = possible;
	else
		this->charPos = notDisplayable;
	this->floatValue = static_cast<float>(this->doubleValue);
}

bool ScalarConversion::checkPseudoDouble()
{
	if (this->input == "-inf")
		return true;
	if (this->input == "+inf")
		return true;
	if (this->input == "nan")
		return true;
	return false;
}

bool ScalarConversion::checkPseudoFloat()
{
	if (this->input == "-inff")
		return true;
	if (this->input == "+inff")
		return true;
	if (this->input == "nanf")
		return true;
	return false;
}

ScalarConversion::Type ScalarConversion::checkType()
{
	int index;
	int dots;

	if ((this->input.length() == 1) && !std::isdigit(this->input[0]))
		return (charType);
	else if (checkPseudoDouble())
		return (doubleType);
	else if (checkPseudoFloat())
		return (floatType);
	else
	{
		index = 0;
		dots = 0;
		if ((this->input[index] == '+') || (this->input[index] == '-'))
			index++;
		if (!std::isdigit(this->input[index]))
			return (noType);
		index++;
		while ((this->input[index] == '.') || std::isdigit(this->input[index]))
		{
			if(this->input[index] == '.')
				dots++;
			if (dots > 1)
				return (noType);
			index++;
		}
		if (!this->input[index])
		{
			if(dots == 1)
				return (doubleType);
			else
				return (intType);
		}
		else if ((this->input[index] == 'f') && !this->input[index + 1] && (dots == 1))
			return (floatType);
		return (noType);
	}
	return (noType);
}

void ScalarConversion::convertInput()
{
	switch(this->type)
	{
		case intType:
			char *end;
			long l;
			l = strtol(this->input.c_str(), &end, 10);
			if (l < INT_MIN || l > INT_MAX)
    			throw TypeConvertError(TypeConvertError::intSize);
			if (*end != '\0')
        		throw TypeConvertError(TypeConvertError::analyseError);
			this->intValue = l;
			this->intPos = possible;
			break;
		case floatType:
			this->floatValue = std::atof(this->input.c_str());
			break;
		case doubleType:
			this->doubleValue = std::atof(this->input.c_str());
			break;
		case charType:
			this->charValue = this->input[0];
			if (isprint(this->charValue))
				this->charPos = possible;
			else
				this->charPos = notDisplayable;
			break;
		default:
			throw TypeConvertError(TypeConvertError::analyseError);
	}
}
std::string ScalarConversion::getInput() const
{
	return (this->input);
}

ScalarConversion::Flag ScalarConversion::isPossible(Type type) const
{
	switch (type)
	{
		case charType:
			return (this->charPos);
			break;
		case intType:
			return (this->intPos);
			break;
		default:
			return (impossible);
	}
}
char ScalarConversion::getChar() const
{
	return (this->charValue);
}

int ScalarConversion::getInt() const
{
	return (this->intValue);
}

float ScalarConversion::getFloat() const
{
	return (this->floatValue);
}

double ScalarConversion::getDouble() const
{
	return (this->doubleValue);
}


std::ostream& operator<< (std::ostream &out, ScalarConversion const& obj)
{
	int precision;
	
	switch(obj.isPossible(ScalarConversion::charType))
	{
		case ScalarConversion::possible:
			out << "char: '" << obj.getChar() << "'" << std::endl;
			break;
		case ScalarConversion::impossible:
			out << "char: impossible" << std::endl;
			break;
		case ScalarConversion::notDisplayable:
			out << "char: Non displayable" << std::endl;
			break;
	}
	switch(obj.isPossible(ScalarConversion::intType))
	{
		case ScalarConversion::possible:
			out << "int: " << obj.getInt() << std::endl;
			break;
		default:
			out << "int: impossible" << std::endl;
	}
	precision = getNeededPrecision(obj.getFloat());
	
	out << "float: ";
	if (precision == 0)
	{
		std::cout.precision(precision + 1);
		out << std::fixed;
	}
	else
		std::cout.precision(precision); 
	out << obj.getFloat();
	out << "f" << std::endl;
	precision = getNeededPrecision(obj.getDouble());
	std::cout.precision(precision);
	out << "double: ";
	if (precision == 0)
	{
		std::cout.precision(precision + 1);
		out << std::fixed;
	}
	else
		std::cout.precision(precision); 
	out << obj.getDouble();	
	out << std::endl;
	return out;
}

int getNeededPrecision(float num)
{
	double intPart;
	if (isnan(num) || isinf(num))
		return (1);
	else if((modf(num, &intPart) == 0) && num < MAX_FLOAT_PRE && num > -MAX_FLOAT_PRE)
		return (0);
	else
		return (7);
}

int getNeededPrecision(double num)
{
	double intPart;
	if (isnan(num) || isinf(num))
		return (1);
	else if(modf(num, &intPart) == 0 && num < MAX_DOUBLE_PRE && num > -MAX_DOUBLE_PRE)
		return (0);
	else
		return (15);
}
