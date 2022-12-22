/* **************************************************************************** */
/*                                                                              */
/*                                                         :::      ::::::::    */
/*    map.tpp                                            :+:      :+:    :+:    */
/*                                                     +:+ +:+         +:+      */
/*    By: agirona <marvin@42.fr>                     +#+  +:+       +#+         */
/*                                                 +#+#+#+#+#+   +#+            */
/*    Created: 2022/12/21 11:28:40 by agirona           #+#    #+#              */
/*    Updated: 2022/12/21 11:28:40 by agirona          ###   ########lyon.fr    */
/*                                                                              */
/* **************************************************************************** */

#ifndef MAP_TPP
# define MAP_TPP

# include "map.hpp"

namespace ft
{
	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::iterator	map<K, T, C, A>::begin()
	{
		return (_tree.begin());
	}

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::iterator	map<K, T, C, A>::end()
	{
		return (_tree.end());
	}

	template <class K, class T, class C, class A>
	void	map<K, T, C, A>::insert(const value_type &val)
	{
		_tree.insert(val);
	}
};

#endif
