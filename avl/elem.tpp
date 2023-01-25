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
	//====		Constructors && Destructor		====
	

	template <class T>
	elem<T>::elem() : _pair(NULL), _parent(NULL), _left(NULL), _right(NULL), _end(NULL), _ptr_last(NULL), _printable(1), _height(0)
	{

	}

	template <class T>
	elem<T>::elem(const pair_type &pair) : _pair(pair), _parent(NULL), _left(NULL), _right(NULL), _end(NULL), _ptr_last(NULL), _printable(1), _height(0)
	{

	}

	template <class T>
	elem<T>::~elem()
	{

	}


	//====				Setters					====


	template <class T>
	void	elem<T>::set_parent(node *parent)
	{
		_parent = parent;
	}

	template <class T>
	void	elem<T>::set_left(node *left)
	{
		_left = left;
	}

	template <class T>
	void	elem<T>::set_right(node *right)
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
	void	elem<T>::set_end(node *end)
	{
		_end = end;
	}

	template <class T>
	void	elem<T>::set_print(const bool printable)
	{
		_printable = printable;
	}

	template <class T>
	void	elem<T>::set_ptr_last(node *ptr)
	{
		_ptr_last = ptr;
	}

	template <class T>
	void	elem<T>::set_height(size_t height)
	{
		_height = height;
	}


	//====				Getters					====


	template <class T>
	typename elem<T>::key_type	elem<T>::get_key() const
	{
		return (_pair.first); 
	}

	template <class T>
	typename elem<T>::pair_type	*elem<T>::get_pair()
	{
		if (_printable == 1)
			return (&_pair); 
		else
			return (NULL);
	}


	//====				Iterators				====

	
	template <class T>
	elem<T>	*elem<T>::next()
	{
		 elem<T>	*current;
		 elem<T>	*prev;

		 prev = this;
         if (prev == _ptr_last)
			 return (_end);
         if (prev->_right)
             return (mini(prev->_right));
         current = prev->_parent;
         while (current && prev == current->_right)
         {
			 prev = current;
             current = current->_parent;
         }
         return (current);
	}

	template <class T>
	elem<T> *elem<T>::prev()
	{
		elem<T>		*prev;
		elem<T>		*current;

		prev = this;
        if (prev->_left != NULL)
			return (maxi(prev->_left));
		current = prev->_parent;
        while (current && prev == current->_left)
       	{
			prev = current;
            current = current->_parent;
        }
        return (current);
    }


	//==========			Private functions			==========

	//====						Tools					====


	template <class T>
	elem<T>    *elem<T>::mini(node *current) const
    {
		if (current->_left == NULL)
			return (current);
		while (current->_left)
			current = current->_left;
		return (current);
	}

	template <class T>
	elem<T>		*elem<T>::maxi(node *current) const
    {
		if (current->_right == NULL)
			return (current);
        while (current->_right)
            current = current->_right;
        return (current);
    }

};

#endif
