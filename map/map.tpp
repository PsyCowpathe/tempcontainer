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

/*explicit map (const key_compare& comp = key_compare(),              const allocator_type& alloc = allocator_type());
range (2)	
template <class InputIterator>  map (InputIterator first, InputIterator last,       const key_compare& comp = key_compare(),       const allocator_type& alloc = allocator_type());
copy (3)	
map (const map& x);*/

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::iterator	map<K, T, C, A>::begin()
	{
		return (_tree.begin());
	}

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::reverse_iterator	map<K, T, C, A>::rbegin()
	{
		return (reverse_iterator(end()));
	}

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::iterator	map<K, T, C, A>::end()
	{
		return (_tree.end());
	}

	template <class K, class T, class C, class A>
	void	map<K, T, C, A>::insert(const used_value_type &val)
	{
		_tree.insert(val);
	}

	template <class K, class T, class C, class A>
	void	map<K, T, C, A>::erase(const used_value_type &val)
	{
		_tree.erase(val);
	}

	template <class K, class T, class C, class A>
	void	map<K, T, C, A>::erase(iterator first, iterator last)
	{
		iterator	it;

		it = first;
		while (first != last)
		{
			std::cout << "je veux delete " << first->first << std::endl;
			_tree.erase(*first);
			std::cout << "j'ai delete " << std::endl;
			if (!(first != last)) //bon en gros ta pas le bon it a la sortie, cherche a comprendre, j'ai pas le fois de le faire ce soir
			{
				_tree.erase(*(--first));
				return ;
			}
		}
	}
};

#endif
