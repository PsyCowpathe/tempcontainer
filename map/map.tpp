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
	//====		Constructors && Destructor		====
	
	template <class K, class T, class C, class A>
	map<K, T, C, A>::map(const key_compare &comp, const allocator_type &alloc) : _alloc(alloc), _comp(comp)
	{

	}

	template <class K, class T, class C, class A>
	template <class InputIterator>
	map<K, T, C, A>::map(InputIterator first, InputIterator last, const key_compare &comp, const allocator_type &alloc) :
	_alloc(alloc), _comp(comp)
	{
		insert(first, last);
	}

	template <class K, class T, class C, class A>
	map<K, T, C, A>::map(const map &x)
	{
		insert(x.begin(), x.end());
	}

	template <class K, class T, class C, class A>
	map<K, T, C, A>::~map()
	{
		clear();
	}

	//====				Operators				====
	

	template <class K, class T, class C, class A>
	map<K, T, C, A>		&map<K, T, C, A>::operator=(const map &x)
	{
		clear();
		insert(x.begin(), x.end());
		return (*this);
	}
	

	//====				Iterators				====


	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::iterator	map<K, T, C, A>::begin()
	{
		return (_tree.begin());
	}

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::const_iterator	map<K, T, C, A>::begin() const
	{
		return (const_iterator(_tree.begin()));
	}
	
	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::iterator	map<K, T, C, A>::end()
	{
		return (_tree.end());
	}

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::const_iterator	map<K, T, C, A>::end() const
	{
		return (const_iterator(_tree.end()));
	}

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::reverse_iterator	map<K, T, C, A>::rbegin()
	{
		return (reverse_iterator(end()));
	}


	//====				Modifiers				====

	template <class K, class T, class C, class A>
	void	map<K, T, C, A>::insert(const value_type &val)
	{
		_tree.insert(val);
	}

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::iterator	map<K, T, C, A>::insert(iterator position, const value_type &val)
	{
		(void)position;
		_tree.insert(val);
	}

	template <class K, class T, class C, class A>
	template <class InputIterator>
	void	map<K, T, C, A>::insert(InputIterator first, InputIterator last)
	{
		while (first != last)
		{
			_tree.insert(*first);
			first++;
		}
	}

	template <class K, class T, class C, class A>
	void	map<K, T, C, A>::erase(const value_type &val)
	{
		_tree.erase(val);
	}

	template <class K, class T, class C, class A>
	void	map<K, T, C, A>::erase(iterator first, iterator last)
	{
		while (first != last)
			_tree.erase(*(first++));
	}

	template <class K, class T, class C, class A>
	void	map<K, T, C, A>::clear()
	{
		erase(begin(), end());
	}

};

#endif
