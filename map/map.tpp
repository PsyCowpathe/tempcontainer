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

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::mapped_type	&map<K, T, C, A>::operator[](const key_type &k)
	{
		insert(begin(), value_type(k, mapped_type()));
		return (find(k)->second);
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

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::const_reverse_iterator	map<K, T, C, A>::rbegin() const
	{
		return (const_reverse_iterator(end()));
	}

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::reverse_iterator	map<K, T, C, A>::rend()
	{
		return (reverse_iterator(begin()));
	}

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::const_reverse_iterator	map<K, T, C, A>::rend() const
	{
		return (const_reverse_iterator(begin()));
	}


	//====				Capacity				====
	

	template <class K, class T, class C, class A>
	bool	map<K, T, C, A>::empty() const
	{
		if (size() == 0)
			return (true);
		return (false);
	}

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::size_type map<K, T, C, A>::size() const
	{
		return (_tree.size());
	}

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::size_type map<K, T, C, A>::max_size() const
	{
		return (_tree.max_size());
	}


	//====				Modifiers				====
	

	template <class K, class T, class C, class A>
	pair<typename map<K, T, C, A>::iterator, bool>	map<K, T, C, A>::insert(const value_type &val)
	{
		bool		wich;
		iterator	ret;

		wich = false;
		ret = find(val.first);
		if (ret == end())
		{
			wich = true;
			ret = insert(begin(), val);
		}
		return (ft::make_pair<iterator, bool>(ret, wich));
	}

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::iterator	map<K, T, C, A>::insert(iterator, const value_type &val)
	{
		_tree.insert(val);
		return (find(val.first));
	}

	template <class K, class T, class C, class A>
	template <class InputIterator>
	typename enable_if<!is_integral<InputIterator>::value, void>::type
	map<K, T, C, A>::insert(InputIterator first, InputIterator last)
	{
		while (first != last)
		{
			_tree.insert(*first);
			first++;
		}
	}

	template <class K, class T, class C, class A>
	void	map<K, T, C, A>::erase(iterator position)
	{
		_tree.erase(position->first);
	}

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::size_type	map<K, T, C, A>::erase(const key_type &val)
	{
		size_t	count;

		count = 0;
		if (find(val) != end())
			count++;
		_tree.erase(val);
		return (count);
	}

	template <class K, class T, class C, class A>
	void	map<K, T, C, A>::erase(iterator first, iterator last)
	{
		while (first != last)
			_tree.erase((first++)->first);
	}

	template <class K, class T, class C, class A>
	void	map<K, T, C, A>::swap(map &x)
	{
		_tree.swap(x._tree);
	}

	template <class K, class T, class C, class A>
	void	map<K, T, C, A>::clear()
	{
		erase(begin(), end());
	}


	//====				Observers				====
	

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::key_compare map<K, T, C, A>::key_comp() const
	{
		return (key_compare());
	}

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::value_compare map<K, T, C, A>::value_comp() const
	{
		return (value_compare(key_compare()));
	}


	//====				Operations				====
	

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::iterator map<K, T, C, A>::find(const key_type &k)
	{
		return (_tree.find(k));
	}

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::const_iterator map<K, T, C, A>::find(const key_type &k) const
	{
		iterator	ret;

		ret = _tree.find(k);
		return (const_iterator(ret));
	}

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::size_type map<K, T, C, A>::count(const key_type &k) const
	{
		if (_tree.find(k) != end())
			return (1);
		return (0);
	}

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::iterator map<K, T, C, A>::lower_bound(const key_type &k)
	{
		iterator	it;
		iterator	ite;

		it = begin(); 
		ite = end();
		while (it != ite)
		{
			if (_comp((*it).first, k) == false)
				return (it);
			it++;
		}
		return (end());
	}

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::const_iterator map<K, T, C, A>::lower_bound(const key_type &k) const
	{
		const_iterator	it;
		const_iterator	ite;

		it = begin(); 
		ite = end();
		while (it != ite)
		{
			if (_comp((*it).first, k) == false)
				return (it);
			it++;
		}
		return(end());
	}

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::iterator map<K, T, C, A>::upper_bound(const key_type &k)
	{
		iterator	it;
		iterator	ite;

		it = begin(); 
		ite = end();
		while (it != ite)
		{
			if (_comp(k, (*it).first))
				return (it);
			it++;
		}
		return (end());
	}

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::const_iterator map<K, T, C, A>::upper_bound(const key_type &k) const
	{
		const_iterator	it;
		const_iterator	ite;

		it = begin(); 
		ite = end();
		while (it != ite)
		{
			if (_comp(k, (*it).first))
				return (it);
			it++;
		}
		return (end());
	}

	template <class K, class T, class C, class A>
	pair<typename map<K, T, C, A>::const_iterator, typename map<K, T, C, A>::const_iterator> map<K, T, C, A>::equal_range(const key_type &k) const
	{ 
		const_iterator	low;
		const_iterator	up;

		low = lower_bound(k);
		up = upper_bound(k);
		return (make_pair<const_iterator, const_iterator>(low, up)); 
	}

	template <class K, class T, class C, class A>
	pair<typename map<K, T, C, A>::iterator, typename map<K, T, C, A>::iterator> map<K, T, C, A>::equal_range(const key_type &k)
	{ 
		iterator	low;
		iterator	up;

		low = lower_bound(k);
		up = upper_bound(k);
		return (make_pair<iterator, iterator>(low, up)); 
	}


	//====				Allocator				====
	

	template <class K, class T, class C, class A>
	typename map<K, T, C, A>::allocator_type	map<K, T, C, A>::get_allocator() const
	{
		return (_alloc);
	}


	//====			Relational Operators		====
	
	
	template <class Key, class T, class Compare, class Alloc>
	bool	operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (lhs._tree == rhs._tree);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
  	bool	operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (lhs._tree < rhs._tree);
	}

	template <class Key, class T, class Compare, class Alloc>
  	bool	operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs > rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
  	bool	operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
  	bool	operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}
};

#endif
