/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:11:12 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/09/05 19:11:12 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# ifndef DEBUG
#  define DEBUG 0
# endif

class	Base
{
private : 

public :

	virtual	~Base(void);
};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
