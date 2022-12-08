/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:27:25 by agirona           #+#    #+#             */
/*   Updated: 2022/12/08 17:41:14 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TPP
# define AVL_TPP

# include "avl.hpp"

namespace ft
{
	template <class T, class V>
	elem<T, V>::elem() : _parent(NULL), _left(NULL), _right(NULL)
	{

	}

	template <class T, class V>
	elem<T, V>::elem(elem<T, V>::key_type key) : _parent(NULL), _left(NULL), _right(NULL)
	{
		
		_key = key;
		_value = 0;
	}

	template <class T, class V>
	elem<T, V>::~elem()
	{

	}

	template <class T, class V>
	void	elem<T, V>::set_parent(const elem<T, V> &parent)
	{
		_parent = parent;
	}

	template <class T, class V>
	void	elem<T, V>::set_left(const elem<T, V> &left)
	{
		_left = left;
	}

	template <class T, class V>
	void	elem<T, V>::set_right(const elem<T, V> &right)
	{
		_right = right;
	}

	template <class T, class V>
	elem<T, V>	*elem<T, V>::get_parent() const
	{
		return (_parent); 
	}

	template <class T, class V>
	elem<T, V>	*elem<T, V>::get_left() const
	{
		return (_left); 

	}

	template <class T, class V>
	elem<T, V>	*elem<T, V>::get_right() const
	{
		return (_right); 
	}
};

namespace ft
{
	template <class T, class A>
	tree<T, A>::tree()
	{
		_origin = new_node();
		_size = 0;
	}

	template <class T, class A>
	tree<T, A>::~tree()
	{

	}


	template <class T, class A>
	void	tree<T, A>::insert(const T &val)
	{
		elem<T, T>	newone;

		newone = new_node(val);
		if (_size == 0)
		{
			newone.set_parent(_origin);
		}
	}


	//private
	
	tree<T, A>::pointer		tree<T, A>::new_node()
	{
		return (_alloc.allocate(sizeof(elem<T, T>)));
	}
};

#endif
