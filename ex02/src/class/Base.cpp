/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:17:38 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/09/05 19:17:38 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base::~Base(void)
{
	if (DEBUG)
		std::cout << "Base destructor called\n";
}

// Outside functions //

Base	*generate(void)
{
	if (DEBUG)
		std::cout << "generate function called\n";

	int	randnb;

	randnb = rand() % 3 + 1;
	if (randnb == 1)
	{
		std::cout << "Generated class A\n";
		return new A;
	}
	if (randnb == 2)
	{
		std::cout << "Generated class B\n";
		return new B;
	}
	std::cout << "Generated class C\n";
	return new C;
}

void	identify(Base *p)
{
	if (DEBUG)
		std::cout << "identify ptr version function called\n";
	if (dynamic_cast<A *>(p))
		std::cout << "Base object is : A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "Base object is : B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "Base object is : C\n";
	else
		std::cout << "Incorrect object\n";
}

void	identify(Base &p)
{
	Base	tmp; 
	if (DEBUG)
		std::cout << "identify ref version function called\n";
	try 
	{
		tmp = dynamic_cast<A &>(p);
		std::cout << "Base object is : A\n";
		return ;
	}
	catch (std::exception const &e)
	{
		try 
		{
			tmp = dynamic_cast<B &>(p);
			std::cout << "Base object is : B\n";
			return ;
		}
		catch (std::exception const &e1)
		{
			try 
			{
				tmp = dynamic_cast<C &>(p);
				std::cout << "Base object is : C\n";
				return ;
			}
			catch (std::exception const &e2)
			{
				std::cerr << "Error: " << e2.what() << '\n';
			}
		}
	}
	std::cout << "Incorrect object\n";
}
