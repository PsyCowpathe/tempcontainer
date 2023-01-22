/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:54:40 by agirona           #+#    #+#             */
/*   Updated: 2023/01/22 16:57:57 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <list>
#include <iostream>
#include "common.hpp"

#define T1 int
#define T2 std::string
typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;
typedef TESTED_NAMESPACE::map<T1, T2>::iterator iterator;

static int iter = 0;

template <typename MAP, typename U>
void	ft_insert(MAP &mp, U param)
{
	_pair<iterator, bool> tmp;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(param);
	std::cout << "insert return: " << printPair(tmp.first);
	std::cout << "Created new node: " << tmp.second << std::endl;
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_insert(MAP &mp, U param, V param2)
{
	iterator tmp;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(param, param2);
	std::cout << "insert return: " << printPair(tmp);
	printSize(mp);
}

int		main(void)
{
	TESTED_NAMESPACE::map<T1, T2> mp, mp2;

	ft_insert(mp, T3(42, "lol"));
	ft_insert(mp, T3(42, "mdr"));

	ft_insert(mp, T3(50, "mdr"));
	ft_insert(mp, T3(35, "funny"));

	ft_insert(mp, T3(45, "bunny"));
	ft_insert(mp, T3(21, "fizz"));
	ft_insert(mp, T3(38, "buzz"));

	ft_insert(mp, mp.begin(), T3(55, "fuzzy"));

	ft_insert(mp2, mp2.begin(), T3(1337, "beauty"));
	ft_insert(mp2, mp2.end(), T3(1000, "Hello"));
	ft_insert(mp2, mp2.end(), T3(1500, "World"));

	return (0);
}

/*#ifndef VALID
	# include <map>
	# include <utility>
	# include <iostream>
	namespace gg = std;
#else
	# include "map.tpp"
	namespace gg = ft;
#endif

int		main(void)
{

	gg::map<int, int>				test;
	gg::map<int, int>				swp;
	gg::map<int, int>::iterator		ret;
	gg::map<int, int>::iterator		it;
	gg::map<int, int>::iterator		ite;
	gg::pair<gg::map<int, int>::iterator, bool>	blbl;
	

	test.insert(gg::make_pair<int, int>(0, 10));
	test.insert(gg::make_pair<int, int>(123, 10));
	test.insert(gg::make_pair<int, int>(1234, 10));
	test.insert(gg::make_pair<int, int>(4567, 10));
	test.insert(gg::make_pair<int, int>(1, 10));
	test.insert(gg::make_pair<int, int>(0, 10));
	test.insert(gg::make_pair<int, int>(0, 10));
	test.insert(gg::make_pair<int, int>(2, 10));
	test.insert(gg::make_pair<int, int>(5, 10));
	test.insert(gg::make_pair<int, int>(10, 10));
	test.insert(gg::make_pair<int, int>(15, 10));
	test.insert(gg::make_pair<int, int>(20, 10));
	blbl = test.insert(gg::make_pair<int, int>(14, 10));
	blbl = test.insert(gg::make_pair<int, int>(14, 100));

	test.insert(test.end(), gg::make_pair<int, int>(-42, 10));
	test.insert(test.begin(), test.end());

	test[14] = 1000;

	ret = test.find(14);
	std::cout << "find = " << blbl.first->first << std::endl;
	std::cout << "mm = " << ret->first << std::endl;

	std::cout << "erase = " << test.erase(20) << std::endl;

	test.erase(test.begin());
	
	swp.lower_bound(42);

	swp.swap(test);
	std::cout << "count = " << swp.count(-14) << std::endl;
	std::cout << "START OF PRINT" << std::endl;
	it = swp.begin();
	ite = swp.end();
	while (it != ite)
	{
		std::cout << "it = " << it->first << std::endl;
		it++;
	}
	return (0);
}

int		main(void)
{
	ft::map<int, int>	test;
	ft::map<int, int>	neww;
	ft::map<int, int>::iterator	it;
	ft::map<int, int>::iterator	ite;
	ft::map<int, int>::reverse_iterator	rite;

	test.insert(ft::make_pair<int, int>(0, 10));
	test.insert(ft::make_pair<int, int>(123, 10));
	test.insert(ft::make_pair<int, int>(1234, 10));
	test.insert(ft::make_pair<int, int>(4567, 10));
	test.insert(ft::make_pair<int, int>(1, 10));
	test.insert(ft::make_pair<int, int>(0, 10));
	test.insert(ft::make_pair<int, int>(0, 10));
	test.insert(ft::make_pair<int, int>(2, 10));
	
	test.insert(ft::make_pair<int, int>(5, 10));
	test.insert(ft::make_pair<int, int>(10, 10));
	test.insert(ft::make_pair<int, int>(15, 10));
	test.insert(ft::make_pair<int, int>(20, 10));
	test.insert(ft::make_pair<int, int>(14, 10));

	it = test.end();
	it--;
	it--;
	it--;

	test.erase(it, test.end());
	test.erase(ft::make_pair<int, int>(5, 10));

	test.insert(ft::make_pair<int, int>(28, 10));
	test.insert(ft::make_pair<int, int>(42, 10));

	test.erase(ft::make_pair<int, int>(0, 10));
	test.erase(ft::make_pair<int, int>(123, 10));
	test.erase(ft::make_pair<int, int>(2, 10));
	test.erase(ft::make_pair<int, int>(1234, 10));
	test.erase(ft::make_pair<int, int>(4567, 10));
	test.erase(ft::make_pair<int, int>(1, 10));

	it = test.begin();
	ite = test.end();
	std::cout << "start =" << it->first << std::endl;
	ite--;
	rite = test.rbegin();
	rite--;
	//++ite;
	std::cout << "la" << std::endl;
	std::cout << "laaa" << std::endl;
	while (ite != it)
	{
		std::cout << "it = " << ite->first << std::endl;
		ite--;
	}

	it = test.begin();
	ite = test.end();
	std::cout << std::endl << "START OF PRINT" << std::endl;
	while (it != ite)
	{
		std::cout << "it = " << it->first << std::endl;
		it++;
	}
	std::cout << std::endl << "END OF PRINT" << std::endl;
	neww = test;
	
	return (0);
}


int		main(void)
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
}

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
	--ite;
	while (ite != it)
	{
		std::cout << "it = " << ite->first << std::endl;
		ite--;
	}
	return (0);
}*/
