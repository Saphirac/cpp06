/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:54:21 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/09/05 18:59:55 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <stdint.h>

# ifndef DEBUG
#  define DEBUG 0
# endif

struct	Data
{
	int			test0;
	std::string	test1;
	char		test2;
};

class	Serializer
{
private : 

public :

	Serializer(void);
	Serializer(Serializer const &src);
	~Serializer(void);

	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);

	Serializer	&operator=(Serializer const &src);
};

#endif
