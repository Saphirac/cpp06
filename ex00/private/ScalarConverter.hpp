/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 01:15:16 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/08/24 01:15:16 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

# ifndef DEBUG
#  define DEBUG 0
# endif

class	ScalarConverter
{
private : 

public :

	ScalarConverter(void);
	ScalarConverter(ScalarConverter const &src);
	~ScalarConverter(void);

	static void	convert(std::string const &literal);

	ScalarConverter	&operator=(ScalarConverter const &src);
};

#endif
