/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectormain.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:54:12 by agirona           #+#    #+#             */
/*   Updated: 2022/10/31 19:45:39 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID
	# include <vector>
	# include <utility>
	# include <iostream>
	namespace ft = std;
#else
	# include "../vector.tpp"

#endif

int		main(void)
{
	std::cout << "VECTOR TESTS"	<< std::endl;
	ft::vector<int>					test(10, 5);
	ft::vector<int>::iterator		it;
	ft::vector<int>::iterator		ite;

	it = test.begin();
	ite = test.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
}

