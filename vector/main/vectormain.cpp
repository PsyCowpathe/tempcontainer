/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectormain.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:54:12 by agirona           #+#    #+#             */
/*   Updated: 2022/11/28 23:37:54 by agirona          ###   ########lyon.fr   */
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

int		main(void)
{
	std::cout << "VECTOR TESTS"	<< std::endl;
	gg::vector<int>::iterator	it;
	gg::vector<int>::iterator	ite;
	std::cout << "debut" << std::endl;
	gg::vector<int>		test1(7, 100);
	write(1, "salut", 5);
	dprintf(1, "fin\n");
	printf("fiiiiin\n");
	std::cout << "mais wtf" << std::endl;
	//gg::vector<int>		test2(test1.begin() + 1, test1.end() - 1);
	//gg::vector<int>		test3;

	it = test1.begin();
	ite = test1.end();
	while (it != ite)
	{
		printf("tt");
		std::cout << "fk" << std::endl;
		std::cout << *it << std::endl;
		it++;
	}
}


