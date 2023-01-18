/* **************************************************************************** */
/*                                                                              */
/*                                                         :::      ::::::::    */
/*    elem.tpp                                           :+:      :+:    :+:    */
/*                                                     +:+ +:+         +:+      */
/*    By: agirona <marvin@42.fr>                     +#+  +:+       +#+         */
/*                                                 +#+#+#+#+#+   +#+            */
/*    Created: 2022/12/22 12:01:59 by agirona           #+#    #+#              */
/*    Updated: 2022/12/22 12:01:59 by agirona          ###   ########lyon.fr    */
/*                                                                              */
/* **************************************************************************** */

#ifndef ELEM_TPP
# define ELEM_TPP

# include "elem.hpp"


namespace ft
{
	template <class T>
	elem<T>::elem() : _pair(), _parent(NULL), _left(NULL), _right(NULL), _end(NULL), _ptr_last(NULL), _printable(1)
	{

	}

	template <class T>
	elem<T>::elem(const pair_type &pair) : _pair(pair), _parent(NULL), _left(NULL), _right(NULL), _end(NULL), _ptr_last(NULL), _printable(1)
	{

	}

	template <class T>
	elem<T>::~elem()
	{

	}

	template <class T>
	void	elem<T>::set_parent(elem<T> *parent)
	{
		_parent = parent;
	}

	template <class T>
	void	elem<T>::set_left(elem<T> *left)
	{
		_left = left;
	}

	template <class T>
	void	elem<T>::set_right(elem<T> *right)
	{
		_right = right;
	}


	template <class T>
	void	elem<T>::set_key(const key_type &key)
	{
		_pair.first = key;
	}

	template <class T>
	void	elem<T>::set_value(const value_type &value)
	{
		_pair.second = value;
	}

	template <class T>
	void	elem<T>::set_pair(const pair_type &pair)
	{
		_pair.first = pair.first;
		_pair.second = pair.second;
	}

	template <class T>
	void	elem<T>::set_end(elem *end)
	{
		_end = end;
	}

	template <class T>
	void	elem<T>::set_print(const bool printable)
	{
		_printable = printable;
	}

	template <class T>
	void	elem<T>::set_ptr_last(elem<T> *ptr)
	{
		_ptr_last = ptr;
	}

	template <class T>
	elem<T>	*elem<T>::get_parent() const
	{
		return (_parent); 
	}

	template <class T>
	elem<T>	*elem<T>::get_left() const
	{
		return (_left); 
	}

	template <class T>
	elem<T>	*elem<T>::get_right() const
	{
		return (_right); 
	}

	template <class T>
	typename elem<T>::key_type	elem<T>::get_key() const
	{
		return (_pair.first); 
	}

	template <class T>
	typename elem<T>::value_type	elem<T>::get_value() const
	{
		return (_pair.second); 
	}

	template <class T>
	typename elem<T>::pair_type	*elem<T>::get_pair()
	{
		if (get_print() == 1)
			return (&_pair); 
		else
			return (NULL);
	}

	template <class T>
	elem<T>	*elem<T>::get_end() const
	{
		return (_end);
	}

	template <class T>
	bool	elem<T>::get_print() const
	{
		return (_printable);
	}

	template <class T>
	elem<T>	*elem<T>::get_ptr_last() const
	{
		return (_ptr_last);
	}

	template <class T>
	elem<T>	*elem<T>::next()
	{
		elem<T>		*current;

		current = this;
		if (current == _ptr_last)
			return (_end);
		if (current->get_right() == NULL)
		{
			current = current->get_parent();
			if (current->get_right() == this)
			{
				current = current->get_parent();
				while (current && current->get_right() == NULL)
					current = current->get_parent();
				if (current && current->get_parent() == NULL)
					return (NULL);
			}
			return (current);
		}
		else
		{
			current = current->get_right();
			while (current->get_left() != NULL)
				current = current->get_left();
			return (current);
		}
	}

	template <class T>
	elem<T>	*elem<T>::prev()
	{
		elem<T>		*current;
		elem<T>		*previous;

		current = this;
		if (current->get_left() == NULL)
		{
			current = current->get_parent();
			if (current->get_left() == this)
			{
				previous = current;
				current = current->get_parent();
				while (current->get_left() == NULL ||
						(current->get_left() != NULL && current->get_left() == previous))
				{
					if (current->get_parent() == NULL)
						return (NULL);
					previous = current;
					current = current->get_parent();
				}
			}
			return (current);
		}
		else
		{
			current = current->get_left();
			while (current->get_right() != NULL)
				current = current->get_right();
			return (current);
		}
	}
};

#endif
