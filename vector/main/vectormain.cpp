/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectormain.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:54:12 by agirona           #+#    #+#             */
/*   Updated: 2022/11/29 00:50:02 by agirona          ###   ########lyon.fr   */
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
	gg::vector<int>		test(7);
	gg::vector<int>		test2(test);
	gg::vector<int>::size_type	ret;

	ret = test2.at(3);
	
	std::cout << ret << std::endl;
	return (1);
}


