/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:45:04 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/09/05 18:45:04 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

// Constructors and destructor //

Serializer::Serializer(void)
{
	if (DEBUG)
		std::cout << "Serializer default constructor called\n";
}

Serializer::Serializer(Serializer const &src __attribute__((unused)))
{
	if (DEBUG)
		std::cout << "Serializer copy constructor called\n";
}

Serializer::~Serializer(void)
{
	if (DEBUG)
		std::cout << "Serializer destructor called\n";
}

// Mandatory functions //

uintptr_t	Serializer::serialize(Data	*ptr)
{
	if (DEBUG)
		std::cout << "Serializer serialize member function called\n";
	return reinterpret_cast<uintptr_t>(ptr);
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	if (DEBUG)
		std::cout << "Serializer deserialize member function called\n";
	return reinterpret_cast<Data *>(raw);
}

// Operator //

Serializer	&Serializer::operator=(Serializer const &src __attribute__((unused)))
{
	if (DEBUG)
		std::cout << "Serializer copy operator called\n";
	return *this;
}
