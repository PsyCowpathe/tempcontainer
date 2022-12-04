/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectormain.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:54:12 by agirona           #+#    #+#             */
/*   Updated: 2022/12/04 12:21:51 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID
	# include <vector>
	# include <utility>
	# include <iostream>
	namespace gg = std;
#else
	# include "../vector.tpp"
	namespace gg = ft;
#endif

#include <unistd.h>
#include <list>
#include "foo.hpp"

void	print(gg::vector<foo<int> > container)
{
	gg::vector<foo<int> >::iterator		it;
	gg::vector<foo<int> >::iterator		ite;

	it = container.begin();
	ite = container.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << std::endl << std::endl;
}

int		main(void)
{
	const int size = 5;
	gg::vector<foo<int> > vct(size);
	gg::vector<foo<int> >::iterator it(vct.begin());
	gg::vector<foo<int> >::const_iterator ite(vct.end());

	for (int i = 1; it != ite; ++i)
		*it++ = i;
	print(vct);

	it = vct.begin();
	ite = vct.begin();

	std::cout << *(++ite) << std::endl;
	std::cout << *(ite++) << std::endl;
	std::cout << *ite++ << std::endl;
	std::cout << *++ite << std::endl;

	it->m();
	ite->m();

	std::cout << *(++it) << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *it++ << std::endl;
	std::cout << *++it << std::endl;

	std::cout << *(--ite) << std::endl;
	std::cout << *(ite--) << std::endl;
	std::cout << *--ite << std::endl;
	std::cout << *ite-- << std::endl;

	(*it).m();
	(*ite).m();

	std::cout << *(--it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *it-- << std::endl;
	std::cout << *--it << std::endl;

	return (0);
}
