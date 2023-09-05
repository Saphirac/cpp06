/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:50:28 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/09/05 18:50:28 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <cstdlib>

int	main(int ac, char **av)
{
	(void)ac;
	uintptr_t	test;
	Data		*ptr_test;
	uintptr_t	result;

	test = static_cast<uintptr_t>(atoi(av[1]));
	ptr_test = Serializer::deserialize(test);
	result = Serializer::serialize(ptr_test);
	std::cout << "uintptr_t test : " << test << '\n'
	<< "uintptr_t test hex value : " << std::hex << "0x" << test << '\n'
	<< "deserialize test ; ptr_test : " << ptr_test << '\n'
	<< "serialize test ; result hex value : " << "0x" << result << '\n'
	<< "serialize test ; result : " << std::dec << result << '\n';
}
