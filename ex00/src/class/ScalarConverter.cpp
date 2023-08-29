/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:04:24 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/08/26 13:04:24 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

// Constructors and destructor //

ScalarConverter::ScalarConverter(void)
{
	if (DEBUG)
		std::cout << "ScalarConverter default constructor called\n";
}

ScalarConverter::ScalarConverter(ScalarConverter const &src __attribute__((unused)))
{
	if (DEBUG)
		std::cout << "ScalarConverter copy constructor called\n";
}

ScalarConverter::~ScalarConverter(void)
{
	if (DEBUG)
		std::cout << "ScalarConverter destructor called\n";
}

// Mandatory functions //

#include <cctype>
#include <cmath>
#include <string>
#include <iomanip>

inline static bool	validCharFloat(std::string const &literal)
{
	bool	is_dot = false;

	for (size_t i = 0; i < literal.length() - 1; i++)
	{
		if (isdigit(literal[i]) == false)
		{
			if (literal[i] != '.')
				return false;
			else if (is_dot == true)
				return false;
			else
				is_dot = true;
		}
	}
	return true;
}

inline static bool	validCharDouble(std::string const &literal)
{
	bool	is_dot = false;

	for (int i = 0; literal[i]; i++)
	{
		if (isdigit(literal[i]) == false)
		{
			if (literal[i] != '.')
				return false;
			else if (is_dot == true)
				return false;
			else
				is_dot = true;
		}
	}
	if (is_dot == false)
		return false;
	return true;
}

inline static bool	isChar(std::string const &literal)
{
	if (literal.length() == 1)
		return true;
	return false;
}

inline static bool	isInt(std::string const &literal)
{
	for (int i = 0; literal[i]; i++)
		if (isdigit(literal[i]) == false)
			return false;
	if (atol(literal.c_str()) > 21247483647 || atol(literal.c_str()) < -2147483648)
		return false;
	return true;
}

#include <stdio.h>

inline static bool	isFloat(std::string const &literal)
{
	if (literal == "+inff" || literal == "-inff" || literal == "nanf")
		return true;
	if (literal[literal.length() - 1] != 'f')
		return false;
	if (validCharFloat(literal) == false)
		return false;
	if (atof(literal.c_str()) == 0.0 && literal[0] != '0')
		return false;
	return true;
}

inline static bool	isDouble(std::string const &literal)
{
	if (literal == "+inf" || literal == "-inf" || literal == "nan")
		return true;
	if (validCharDouble(literal) == false)
		return false;
	if (atof(literal.c_str()) == 0.0 && literal[0] != '0')
		return false;
	return true;
}

void	manageNanInf(std::string const &literal)
{
	std::cout << "char : impossible\n"
	<< "int : impossible\n";
	if (literal == "nanf")
		std::cout << "double : nan" << "\n";
	if (literal == "+inff")
		std::cout << "double : +inf" << "\n";
	if (literal == "-inff")
		std::cout << "double : -inf" << "\n";
	if (literal == "nan")
		std::cout << "float : nanf" << "\n";
	if (literal == "+inf")
		std::cout << "float : +inff" << "\n";
	if (literal == "-inf")
		std::cout << "float : -inff" << "\n";
}

void	ScalarConverter::convert(std::string const &literal)
{
	char	c;
	int		i;
	float	f;
	double	d;

	if (isChar(literal) == true)
	{
		c = literal[0];
		std::cout << "char : " << c << "\n";
		i = static_cast<int>(c);
		std::cout << "int : " << i << "\n";
		f = static_cast<float>(c);
		std::cout << "float : " << f << "f\n";
		d = static_cast<double>(c);
		std::cout << "double : " << d << ".0\n";
	}
	else if (isInt(literal) == true)
	{
		i = atoi(literal.c_str());
		std::cout << "int : " << i << "\n";
		if (i > 0 && i < 127)
		{	
			c = static_cast<char>(i);
			std::cout << "char : " << c << "\n";
		}
		else
			std::cout << "char : impossible\n";
		f = static_cast<float>(i);
		std::cout << "float : " << f << "f\n";
		d = static_cast<double>(i);
		std::cout << "double : " << d << ".0\n";
	}
	else if (isFloat(literal) == true)
	{
		if (isdigit(literal[0]) == false)
			manageNanInf(literal);
		else
		{
			f = atof(literal.c_str());
			std::cout << std::setprecision(1) << std::fixed << "float : " << f << "f\n";
			if (f > 0.0f && f < 127.0f)
			{	
				c = static_cast<char>(f);
				std::cout << "char : " << c << "\n";
			}
			else
				std::cout << "char : impossible\n";
			if (f >= -2147483648.0f || f <= 2147483647.0f)
			{
				i = static_cast<int>(f);
				std::cout << "int : " << i << "\n";
			}
			else
				std::cout << "int : impossible\n";
			d = static_cast<double>(f);
			std::cout << std::setprecision(1) << std::fixed << "double : " << d << "\n";
		}
	}
	else if (isDouble(literal) == true)
	{
		if (isdigit(literal[0]) == false)
			manageNanInf(literal);
		else
		{
			f = atof(literal.c_str());
			d = static_cast<double>(f);
			std::cout << std::setprecision(1) << std::fixed << "double : " << d << "\n";
			if (d > 0.0 && d < 127.0)
			{	
				c = static_cast<char>(d);
				std::cout << "char : " << c << "\n";
			}
			else
				std::cout << "char : impossible\n";
			if (d >= -2147483648.0 || d <= 2147483647.0)
			{
				i = static_cast<int>(f);
				std::cout << "int : " << i << "\n";
			}
			else
				std::cout << "int : impossible\n";
			std::cout << std::setprecision(1) << std::fixed << "float : " << f << "f\n";
		}
	}
	else
	{
		std::cout << "char : impossible\n"
		<< "int : impossible\n"
		<< "float : impossible\n"
		<< "double : impossible\n";
	}
}

// Operator //

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &src __attribute__((unused)))
{
	if (DEBUG)
		std::cout << "ScalarConverter copy operator called\n";
	return *this;
}
