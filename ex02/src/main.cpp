/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:43:15 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/09/05 19:43:15 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

int	main()
{
	srand(time(NULL));
	Base	*testptr = generate();
	identify(testptr);
	Base	&testref = *generate();
	identify(testref);
	delete testptr;
	delete &testref;
}
