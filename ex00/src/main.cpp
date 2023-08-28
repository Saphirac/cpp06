/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 01:14:33 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/08/24 01:14:33 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Casts en C:

	1. Cast implicite

		Lorsque un type A est plus petit et de meme encodage qu'un type B,
		le compiler peut cast de A vers B sans rien craindre.
		Un tel cast, sans annotations explicite, est un cast implicite.

	2. Cast explicite
	
		Lorsque les types A et B sont primitifs:
			signed {char, short, int, long, long long},
			unsigned {char, short, int, long, long long},
			float, double, long double,
		Alors, on peut caster a l'aide de l'annotation `(B) a` ou `a` est une variable de type A.

		On peut aussi caster un pointeur sur A en pointeur sur B avec ce type de cast.
		Cela ne va pas changer la nature du pointeur lui-meme, mais l'interpretation du type qui est au bout.

		On peut egalement utiliser le cast explicite pour changer la constance/mutabilite d'une variable.
		Example:
		```
		a			char (== 1 caractere)
		bb			invalid /!\ (> 1 caractere && != chiffre)
		42			int (> 1 caractere && == chiffres && !`f`)
		5			char (== 1 caractere)
		.			char (== 1 caractere)
		.001		double (> 1 caractere && `.` && !`f`)
		12f			float (> 1 caractere && `f`)
		.f			float (> 1 caractere && `f`)
		2147483648	invalid /!\ (> 1 caractere && == chiffres && !`f` && > limit)
		Z			char (== 1 caractere)
		123.456f	float (> 1 caractere && `f`)
		```

		           | implicite | explicite |
		-----------+-----------+-----------+
		const/mut  |           |     XX    |
		-----------+-----------+-----------+
		static     |downgrading|     XX    |
		-----------+-----------+-----------+
		reinterpret|           |     XX    |
		-----------+-----------+-----------+

		static_cast<B>(A);

	0 | 0000000 0 | 0000000 00000000 00000000 |

	Address |  0x65  |  0x66  |  0x67  |  0x68  |  0x69  |  0x6a  |  0x6b  |  0x6c  |  0x6d  |
	--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
	Value   |  0x42  |  0x28  |  0x00  |  0x00  |        |        |  0x65  |        |        |
	            ^                                                      ^
																	  ptr

	float: 0x42280000
	int:   0x0000002a
*/

void	func_int(int *const G)
{
	int	*a = (int *)0xff2a;
}

#include <string>
#include <cmath>
#include "ScalarConverter.hpp"

int	main(int const ac, char const *const *const av)
{
	if (ac != 2)
	{
		std::cerr << "invalid number of arg\n";
		return 1;
	}
	std::string	literal(av[1]);
	ScalarConverter::convert(literal);
	return 0;
}
