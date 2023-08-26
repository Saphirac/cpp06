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

ScalarConverter::ScalarConverter(ScalarConverter const &src)
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

inline static bool	isChar(std::string const &literal)
{
	if (literal.length() == 1)
		return true;
	return false;
}

inline static bool	isInt(std::string const &literal)
{
	
}

static void	ScalarConverter::convert(std::string const &literal)
{
	char	c;
	int		i;
	float	f;
	double	d;

	if (is_char(literal) == true)
	{
		c = static_cast<char>(literal);
		std::cout << "char : " << c << "\n";
		i = static_cast<int>(c);
		std::cout << "int : " << i << "\n";
		f = static_cast<float>(c);
		std::cout << "float : " << f << "\n";
		d = static_cast<double>(d);
		std::cout << "double : " << d << "\n";
	}
}

// Operator //

ScalarConverter	ScalarConverter::&operator=(ScalarConverter const &src)
{
	if (DEBUG)
		std::cout << "ScalarConverter copy operator called\n";
	return *this;
}
