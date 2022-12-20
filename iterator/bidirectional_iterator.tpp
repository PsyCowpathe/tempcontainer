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
	bidirectional_iterator<T>::bidirectional_iterator() : _it(NULL)
	{

	}

	template <class T>
	bidirectional_iterator<T>::bidirectional_iterator(const bidirectional_iterator &copy) : _it(copy._it)
	{

	}

	template <class T>
	bidirectional_iterator<T>::~bidirectional_iterator()
	{
		
	}

	template <class T>
	bidirectional_iterator<T> &bidirectional_iterator<T>::operator=(const bidirectional_iterator<T> &copy)
	{
		_it = copy.it;
		return (*this);
	}

	template <class T>
	bool	bidirectional_iterator<T>::operator==(const const_it &rhs) const
	{
		return (_it == rhs.operator->());
	}

	template <class T>
	bool	bidirectional_iterator<T>::operator!=(const const_it &rhs) const
	{
		return (_it != rhs.operator->());
	}

	template <class T>
	typename bidirectional_iterator<T>::reference	bidirectional_iterator<T>::operator*() const
	{
		return (*_it);
	}

	template <class T>
	typename bidirectional_iterator<T>::pointer	bidirectional_iterator<T>::operator->() const
	{
		return (_it);
	}

	template <class T>
	bidirectional_iterator<T>	&bidirectional_iterator<T>::operator++() //++it
	{
		return (_it.next());
	}

	template <class T>
	bidirectional_iterator<T>	bidirectional_iterator<T>::operator++(int) //it++
	{
		bidirectional_iterator	tmp = *this;
		_it.next();
		return (tmp);
	}

	template <class T>
	bidirectional_iterator<T>	&bidirectional_iterator<T>::operator--()
	{
		return (_it.prev());
	}

	template <class T>
	bidirectional_iterator<T>	bidirectional_iterator<T>::operator--(int)
	{
		bidirectional_iterator	tmp = *this;
		_it.prev();
		return (tmp);
	}

};

#endif
