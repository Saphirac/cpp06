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
#include <algorithm>
#include <string>

inline static bool	validCharFloat(std::string const &literal)
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
	if (std::all_of(literal.begin(), literal.end(), isdigit) == false)
		return false;
	try 
	{
		stoi(literal);
	}
	catch (std::exception const &e)
	{
		return false;
	}
	return true;
}

inline static bool	isFloat(std::string const &literal)
{
	if (literal == "+inff" || literal == "-inff" || literal == "nanf")
		return true;
	if (literal.back() != 'f')
		return false;
	if (std::all_of(literal.begin(), literal.back() - 1, validCharFloat) == false)
		return false;
	try
	{
		stof(literal);
	}
	catch (std::exception const &e)
	{
		return false;
	}
	return true;
}

inline static bool	isDouble(std::string const &literal)
{
	if (literal == "+inf" || literal == "-inf" || literal == "nan")
		return true;
	if (std::all_of(literal.begin(), literal.back() - 1, validCharDouble) == false)
		return false;
	try
		stof(literal);
	catch(std::exception const &e)
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

static void	ScalarConverter::convert(std::string const &literal)
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
		std::cout << "float : " << f << "\n";
		d = static_cast<double>(c);
		std::cout << "double : " << d << "\n";
	}
	else if (isInt(literal) == true)
	{
		i = stoi(literal);
		std::cout << "int : " << i << "\n";
		std::cout << "char : impossible\n";
		f = static_cast<float>(i);
		std::cout << "float : " << f << "\n";
		d = static_cast<double>(i);
		std::cout << "double : " << d << "\n";
	}
	else if (isFloat(literal) == true)
	{
		if (isdigit(literal[0]) == false)
			manageNanInf(literal);
		else
		{
			f = stof(literal);
			std::cout << "float : " << f << "\n";
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
			std::cout << "double : " << d << "\n";
		}
	}
	else if (isDouble(literal) == true)
	{
		if (isdigit(literal[0]) == false)
			manageNanInf(literal);
		else
		{
			d = stod(literal);
			std::cout << "double : " << d << "\n";
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
			f = static_cast<float>(d);
			std::cout << "float : " << double << "\n";
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

ScalarConverter	ScalarConverter::&operator=(ScalarConverter const &src __attribute__((unused)))
{
	if (DEBUG)
		std::cout << "ScalarConverter copy operator called\n";
	return *this;
}
