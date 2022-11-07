/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectormain.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:54:12 by agirona           #+#    #+#             */
/*   Updated: 2022/11/07 19:40:21 by agirona          ###   ########lyon.fr   */
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
	//gg::vector<int>					test(10);
	gg::vector<int>					test1;
	//gg::vector<int>				range(test.begin(), test.end() - 2);
	//gg::vector<int>				cpy(test);
	gg::vector<int>::iterator		it;
	gg::vector<int>::iterator		ite;
	gg::vector<int>::iterator		ret;

	/*test.push_back(4);
	test.push_back(4);
	test.push_back(4);
	test.push_back(4);
	test.push_back(4);
	test.push_back(4);
	test1.push_back(1);
	test1.push_back(1);
	test1.push_back(1);
	test1.push_back(1);
	test1.push_back(1);
	test1.push_back(1);*/
	test1.insert(test1.begin(), 5, 3);
	//test1.insert(test1.begin(), 5, 8);
	/*test1.push_back(1);
	test1.push_back(2);
	test1.push_back(3);
	test1.push_back(4);
	test1.push_back(5);*/
	std::cout << "begin = " << *test1.begin() << std::endl;
	it = test1.begin();
	ite = test1.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
}


