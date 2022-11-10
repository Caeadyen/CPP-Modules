/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:59:27 by hrings            #+#    #+#             */
/*   Updated: 2022/10/18 09:26:33 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP

# include <iostream>
# include <string>
# include <string.h>
# include <climits>
# include <cstdlib>
# include <math.h>
# include <iomanip>

# define MAX_FLOAT_PRE 1e7
# define MAX_DOUBLE_PRE 1e15

class ScalarConversion
{
	public:
		// Constructors
		ScalarConversion(const char *input);
		
		// Destructor
		~ScalarConversion();
		
		//getter
		char getChar() const;
		int getInt() const;
		float getFloat() const;
		double getDouble() const;
		// Operators
		
		enum Type {noType, charType, intType, floatType, doubleType};
		enum Flag {possible, impossible, notDisplayable};
		std::string getInput() const;
		Flag isPossible(Type type) const;
		//error
		class TypeConvertError: public std::exception
		{
			public:
				enum Error{undefined, intSize, analyseError};
				TypeConvertError();
				TypeConvertError(const Error error);
				virtual const char* what() const throw();
			private:
				Error error;
		};
	private:
		ScalarConversion();
		ScalarConversion & operator=(const ScalarConversion &assign);
		ScalarConversion(const ScalarConversion &copy);
		void convertInput();
		void convertToOthers();
		void fromChar();
		void fromInt();
		void fromFloat();
		void fromDouble();
		bool checkPseudoDouble();
		bool checkPseudoFloat();
		Type checkType();
		Type type;
		std::string input;
		int intValue;
		Flag intPos;
		char charValue;
		Flag charPos;
		float floatValue;
		double doubleValue;
};

std::ostream& operator<< (std::ostream &out, ScalarConversion const& obj);
int getNeededPrecision(double num);
int getNeededPrecision(float num);

#endif