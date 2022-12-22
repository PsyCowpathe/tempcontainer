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
	elem<T>::elem() : _pair(), _parent(NULL), _left(NULL), _right(NULL)
	{

	}

	template <class T>
	elem<T>::elem(const pair_type &pair) : _pair(pair), _parent(NULL), _left(NULL), _right(NULL)
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
		return (&_pair); 
	}

	template <class T>
	elem<T>	*elem<T>::next()
	{
		elem<T>		*current;

		current = this;
		if (current->get_right() == NULL)
		{
			current = current->get_parent();
			if (current->get_right() == this)
			{
				current = current->get_parent();
				while (current->get_right() == NULL)
					current = current->get_parent();
				if (current->get_parent() == NULL)
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



	/*template <class T>
		elem<T>    *elem<T>::mini1(elem<T> *search)
        {
            if (search->_left == NULL)
                return (search);
            while (search->_left)
                search = search->_left;
            return (search);
        }

	template <class T>
        elem<T>    *elem<T>::maxi1(elem<T> *search)
        {
            if (search->_right == NULL)
                return (search);
            while (search->_right)
                search = search->_right;
                
            return (search);
        }

		template <class T>
        elem<T> *elem<T>::next()
        {
            elem<T> *tmp = this;
            if (tmp->_right)
                return mini1(tmp->_right);

            elem<T>* tmpdaddy = tmp->_parent;

            while (tmpdaddy && tmp == tmpdaddy->_right)
            {
                tmp = tmpdaddy;
                tmpdaddy = tmpdaddy->_parent;
            }
            return tmpdaddy;
        }

		template <class T>
        elem<T> *elem<T>::prev(void)
        {
            elem<T> *tmp = this;

            if (tmp->_left)
                return maxi1(tmp->_left);

            elem<T>* p = tmp->_parent;
            while (p && tmp == p->_left)
            {
                tmp = p;
                p = p->_parent;
            }
            return p;
        }*/

};

#endif
