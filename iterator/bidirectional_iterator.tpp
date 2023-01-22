/* **************************************************************************** */
/*                                                                              */
/*                                                         :::      ::::::::    */
/*    bidirectional_iterator.tpp                         :+:      :+:    :+:    */
/*                                                     +:+ +:+         +:+      */
/*    By: agirona <marvin@42.fr>                     +#+  +:+       +#+         */
/*                                                 +#+#+#+#+#+   +#+            */
/*    Created: 2022/12/20 12:16:11 by agirona           #+#    #+#              */
/*    Updated: 2022/12/20 12:16:11 by agirona          ###   ########lyon.fr    */
/*                                                                              */
/* **************************************************************************** */

#ifndef	BIDIRECTIONAL_ITERATOR_TPP
# define BIDIRECTIONAL_ITERATOR_TPP
# include "bidirectional_iterator.hpp"

namespace ft
{
	template <class T>
	bidirectional_iterator<T>::bidirectional_iterator() : _it(), _pair()
	{

	}

	template <class T>
	bidirectional_iterator<T>::bidirectional_iterator(const bidirectional_iterator &copy) : _it(copy._it), _pair(copy._pair)
	{

	}

	template <class T>
	bidirectional_iterator<T>::bidirectional_iterator(elem_type *copy)
	{
		_it = copy;
		_pair = copy->get_pair();

	}

	template <class T>
	bidirectional_iterator<T>::~bidirectional_iterator()
	{
		
	}

	template <class T>
	bidirectional_iterator<T> &bidirectional_iterator<T>::operator=(const bidirectional_iterator<T> &copy)
	{
		_it = copy._it;
		_pair = copy._pair;
		return (*this);
	}

	template <class T>
	bool	bidirectional_iterator<T>::operator==(const bidirectional_iterator &rhs) const
	{
		return (_pair == rhs.operator->());
	}

	template <class T>
	bool	bidirectional_iterator<T>::operator!=(const bidirectional_iterator &rhs) const
	{
		return (_it != rhs._it);
	}

	template <class T>
	typename bidirectional_iterator<T>::reference	bidirectional_iterator<T>::operator*() const
	{
		return (*_pair);
	}

	template <class T>
	typename bidirectional_iterator<T>::pointer	bidirectional_iterator<T>::operator->() const
	{
		return (_it->get_pair());
	}

	template <class T>
	bidirectional_iterator<T>	&bidirectional_iterator<T>::operator++()
	{
		_it = _it->next();
		_pair = _it->get_pair();
		return (*this);
	}

	template <class T>
	bidirectional_iterator<T>	bidirectional_iterator<T>::operator++(int)
	{
		bidirectional_iterator	tmp = *this;
		_it = _it->next();
		_pair = _it->get_pair();
		return (tmp);
	}

	template <class T>
	bidirectional_iterator<T>	&bidirectional_iterator<T>::operator--() //nop
	{
		_it = _it->prev();
		_pair = _it->get_pair();
		return (*this);
	}

	template <class T>
	bidirectional_iterator<T>	bidirectional_iterator<T>::operator--(int) //nop
	{
		bidirectional_iterator	tmp = *this;
		_it = _it->prev();
		_pair = _it->get_pair();
		return (tmp);
	}
};

//const_bidirectional_iterator

namespace ft
{
	template <class T>
	const_bidirectional_iterator<T>::const_bidirectional_iterator() : _it(), _pair()
	{

	}

	template <class T>
	const_bidirectional_iterator<T>::const_bidirectional_iterator(const const_bidirectional_iterator &copy) : _it(copy._it), _pair(copy._pair)
	{

	}

	template <class T>
	const_bidirectional_iterator<T>::const_bidirectional_iterator(const bidirectional_iterator<T> &copy) : _it(copy._it), _pair(copy._pair)
	{

	}

	template <class T>
	const_bidirectional_iterator<T>::const_bidirectional_iterator(elem_type *copy) : _it(copy), _pair(copy->get_pair())
	{

	}

	template <class T>
	const_bidirectional_iterator<T>::~const_bidirectional_iterator()
	{
		
	}

	template <class T>
	const_bidirectional_iterator<T> &const_bidirectional_iterator<T>::operator=(const const_bidirectional_iterator<T> &copy)
	{
		_it = copy._it;
		_pair = copy._pair;
		return (*this);
	}

	template <class T>
	bool	const_bidirectional_iterator<T>::operator==(const const_bidirectional_iterator &rhs) const
	{
		return (_pair == rhs.operator->());
	}

	template <class T>
	bool	const_bidirectional_iterator<T>::operator!=(const const_bidirectional_iterator &rhs) const
	{
		return (_it != rhs._it);
	}

	template <class T>
	typename const_bidirectional_iterator<T>::reference	const_bidirectional_iterator<T>::operator*() const
	{
		return (*_pair);
	}

	template <class T>
	typename const_bidirectional_iterator<T>::pointer const_bidirectional_iterator<T>::operator->() const
	{
		return (_it->get_pair());
	}

	template <class T>
	const_bidirectional_iterator<T>	&const_bidirectional_iterator<T>::operator++()
	{
		_it = _it->next();
		_pair = _it->get_pair();
		return (*this);
	}

	template <class T>
	const_bidirectional_iterator<T>	const_bidirectional_iterator<T>::operator++(int)
	{
		const_bidirectional_iterator	tmp = *this;
		_it = _it->next();
		_pair = _it->get_pair();
		return (tmp);
	}

	template <class T>
	const_bidirectional_iterator<T>	&const_bidirectional_iterator<T>::operator--() //nop
	{
		_it = _it->prev();
		_pair = _it->get_pair();
		return (*this);
	}

	template <class T>
	const_bidirectional_iterator<T>	const_bidirectional_iterator<T>::operator--(int) //nop
	{
		const_bidirectional_iterator	tmp = *this;
		_it = _it->prev();
		_pair = _it->get_pair();
		return (tmp);
	}
};

#endif
