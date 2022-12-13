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
# include <stdio.h>

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
	void	elem<T, V>::set_parent(elem<T, V> *parent)
	{
		_parent = parent;
	}

	template <class T, class V>
	void	elem<T, V>::set_left(elem<T, V> *left)
	{
		_left = left;
	}

	template <class T, class V>
	void	elem<T, V>::set_right(elem<T, V> *right)
	{
		_right = right;
	}

	template <class T, class V>
	void	elem<T, V>::set_key(const T &key)
	{
		_key = key;
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

	template <class T, class V>
	typename elem<T, V>::key_type	elem<T, V>::get_key() const
	{
		return (_key); 
	}
};

namespace ft
{
	template <class T, class A, class C>
	tree<T, A, C>::tree()
	{
		_origin = NULL;
		_size = 0;
	}

	template <class T, class A, class C>
	tree<T, A, C>::~tree()
	{

	}


	template <class T, class A, class C>
	void	tree<T, A, C>::insert(const T &val)
	{
		elem<T, T>	*current;
		elem<T, T>	*prev;
		elem<T, T>	*new_one;
		int			direction;

		current = _origin;
		prev = NULL;
		direction = 0;
		while (current != NULL)
		{
			prev = current;
			if (cmp(val, current->get_key()) && (direction = 1))
				current = current->get_left();
			else if (cmp(current->get_key(), val) && (direction = 2))
				current = current->get_right();
			else
				return ;
		}
		_size += 1;
		new_one = new_node(val); 
		new_one->set_parent(prev);
		if (direction == 1)
			prev->set_left(new_one);
		else if (direction == 2)
			prev->set_right(new_one);
		else
			_origin = new_one;
		//balance
	}

	template <class T, class A,class C>
	void	tree<T, A, C>::erase(const T &val)
	{
		elem<T, T>	*current;
		int			direction;

		current = _origin;
		direction = 0;
		while (current != NULL)
		{
			if (cmp(val, current->get_key()) && (direction = 1))
				current = current->get_left();
			else if (cmp(current->get_key(), val) && (direction = 2))
				current = current->get_right();
			else
				current = oblitarate(*current, direction);
		}
	}

	template <class T, class A, class C>
	typename tree<T, A, C>::node	*tree<T, A, C>::get_origin()
	{
		return (_origin);
	}

	//private

	template <class T, class A, class C>
	void	tree<T, A, C>::single_oblitarate(elem<T, T> &to_delete)
	{
		elem<T, T>	*prev;
		elem<T, T>	*tmp;
		elem<T, T>	*substitute;
		int			direction;

		prev = to_delete.get_parent();
		tmp = &to_delete;
		substitute = to_delete.get_right();
		if (to_delete.get_left() != NULL)
			substitute = to_delete.get_left();
		if (prev == NULL)
		{
			_origin = substitute;
			substitute->set_parent(NULL);
			clear_node(&to_delete);
			return ;
		}
		direction = 2;
		if (prev->get_left()->get_key() == to_delete.get_key())
			direction = 1;
		clear_node(tmp);
		if (direction == 1)
			prev->set_left(substitute);
		else
			prev->set_right(substitute);
		substitute->set_parent(prev);
	}


	template <class T, class A, class C>
	void	tree<T, A, C>::complex_oblitarate(elem<T, T> &to_replace)
	{
		elem<T, T>	*substitute;
		elem<T, T>	*to_delete;
		elem<T, T>	*prev;
		typename elem<T, T>::value_type	save_key;

		to_delete = &to_replace;
		prev = to_replace.get_parent();
		to_delete = to_delete->get_right();
		while (to_delete != NULL)
		{
			substitute = to_delete;
			to_delete = to_delete->get_left();
		}
		save_key = substitute->get_key();
		erase(save_key);
		to_replace.set_key(save_key); //potentiel problem avec la validite des iterateurs
	}

	template <class T, class A, class C>
	elem<T, T>	*tree<T, A, C>::oblitarate(elem<T, T> &to_delete, const int &direction)
	{
		elem<T, T>	*prev;

		prev = to_delete.get_parent();
		if (to_delete.get_left() == NULL && to_delete.get_right() == NULL)
		{
			if (_size != 1)
				(direction == 1) ? prev->set_left(NULL) : prev->set_right(NULL);
			clear_node(&to_delete);

		}
		else if (to_delete.get_left() != NULL && to_delete.get_right() != NULL)
			complex_oblitarate(to_delete);
		else
			single_oblitarate(to_delete);
		return (NULL);
	}

	template <class T, class A,class C>
	typename tree<T, A, C>::node	*tree<T, A, C>::new_node(const T &val)
	{
		elem<T, T>		*new_one;

		new_one = _alloc.allocate(sizeof(elem<T, T>));
		_alloc.construct(new_one, val);
		return (new_one);
	}

	template <class T, class A,class C>
	void	tree<T, A, C>::clear_node(elem<T, T> *to_clear)
	{
		_size -= 1;
		if (_size == 0)
			_origin = NULL;
		_alloc.destroy(to_clear);
		_alloc.deallocate(to_clear, sizeof(elem<T, T>));
	}
	

};

#endif
