/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:54:40 by agirona           #+#    #+#             */
/*   Updated: 2022/12/22 15:51:52 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "map.tpp"
#include <map>

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
	//ite++;
	++ite;
	std::cout << "la" << std::endl;
	std::cout << "laaa" << std::endl;
	while (ite != it)
	{
		std::cout << "it = " << ite->first << std::endl;
		ite--;
	}
	return (0);
}


/*int		main(void)
{
	std::map<int, int>	test;
	std::map<int, int>::iterator	it;
	std::map<int, int>::iterator	ite;

	test.insert(std::make_pair<int, int>(10, 10));
	test.insert(std::make_pair<int, int>(15, 10));
	test.insert(std::make_pair<int, int>(18, 10));
	test.insert(std::make_pair<int, int>(2, 10));

	it = test.begin();
	ite = test.end();
	++ite;
	while (ite != it)
	{
		std::cout << "it = " << ite->first << std::endl;
		ite--;
	}
	return (0);
}*/
