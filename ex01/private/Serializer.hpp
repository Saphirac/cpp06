/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:54:21 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/09/02 21:05:30 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

struct	Data
{
	
};

class	Serializer
{
private : 

public :

	Serializer(void);
	Serializer(Serializer const &src);
	~Serializer(void);

	uintptr_t	serialize(Data* ptr);
	Data		*deserialize(uintptr_t raw);

	Serializer	&operator=(Serializer const &src);
};

#endif
