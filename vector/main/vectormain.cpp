/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectormain.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:54:12 by agirona           #+#    #+#             */
/*   Updated: 2022/11/02 20:15:44 by agirona          ###   ########lyon.fr   */
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

int		main(void)
{
	std::cout << "VECTOR TESTS"	<< std::endl;
	gg::vector<int>					test(10, 5);
	gg::vector<int>					range(test.begin(), test.end() - 2);
	gg::vector<int>					cpy(range);
	gg::vector<int>::iterator		it;
	gg::vector<int>::iterator		ite;

	it = cpy.begin();
	ite = cpy.end();
	range.push_back(3);
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
}


