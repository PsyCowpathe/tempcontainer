/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:54:40 by agirona           #+#    #+#             */
/*   Updated: 2022/12/22 13:23:46 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "map.tpp"

int		main(void)
{
	ft::map<int, int>	test;
	ft::map<int, int>::iterator	it;
	ft::map<int, int>::iterator	ite;

	test.insert(ft::make_pair<int, int>(10, 10));
	test.insert(ft::make_pair<int, int>(15, 10));
	test.insert(ft::make_pair<int, int>(18, 10));
	test.insert(ft::make_pair<int, int>(2, 10));

	it = test.begin();
	ite = test.end();
	while (it != ite)
	{
		std::cout << "it = " << it->first << std::endl;
		it++;
	}
	return (0);
}
