/* **************************************************************************** */
/*                                                                              */
/*                                                         :::      ::::::::    */
/*    random_access_iterator.tpp                         :+:      :+:    :+:    */
/*                                                     +:+ +:+         +:+      */
/*    By: agirona <marvin@42.fr>                     +#+  +:+       +#+         */
/*                                                 +#+#+#+#+#+   +#+            */
/*    Created: 2022/11/30 20:29:53 by agirona           #+#    #+#              */
/*    Updated: 2022/11/30 20:29:58 by agirona          ###   ########lyon.fr    */
/*                                                                              */
/* **************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_TPP
# define RANDOM_ACCESS_ITERATOR_TPP
# include "random_access_iterator.hpp"

namespace   ft
{

	template <class T>
	random_access_iterator<T>::random_access_iterator() : _it(NULL)
	{

	}

	template <class T>
	random_access_iterator<T>::random_access_iterator(pointer ptr) : _it(ptr)
	{

	}

	template <class T>
	random_access_iterator<T>::random_access_iterator(const random_access_iterator &copy) : _it(copy._it)
	{

	}

	template <class T>
	random_access_iterator<T>::~random_access_iterator()
	{

	}

	template <class T>
	bool    random_access_iterator<T>::operator!=(const typename random_access_iterator<T>::const_it &rhs) const
	{
	    return (_it != rhs.operator->());
	}

	template <class T>
	bool    random_access_iterator<T>::operator==(const typename random_access_iterator<T>::const_it &rhs) const
	{
	    return (_it == rhs.operator->());
	}

	template <class T>
	bool    random_access_iterator<T>::operator<(const typename random_access_iterator<T>::const_it &rhs) const
	{
	    return (_it < rhs.operator->());
	}

	template <class T>
	bool    random_access_iterator<T>::operator<=(const typename random_access_iterator<T>::const_it &rhs) const
	{
	    return (_it <= rhs.operator->());
	}

	template <class T>
	bool    random_access_iterator<T>::operator>(const typename random_access_iterator<T>::const_it &rhs) const
	{
	    return (_it > rhs.operator->());
	}

	template <class T>
	bool    random_access_iterator<T>::operator>=(const typename random_access_iterator<T>::const_it &rhs) const
	{
	    return (_it >= rhs.operator->());
	}

	template <class T>
	random_access_iterator<T>	operator+(const typename random_access_iterator<T>::difference_type n, const random_access_iterator<T> it)
	{
		return (it + n);
	}

	template <class T>
	random_access_iterator<T>	operator-(const typename random_access_iterator<T>::difference_type n, const random_access_iterator<T> it)
	{
		return (it - n);
	}

	template <class T>
	typename random_access_iterator<T>::pointer random_access_iterator<T>::operator->() const
	{
	    return (_it);
	}

	template <class T>
	typename random_access_iterator<T>::reference               random_access_iterator<T>::operator*() const
	{
	    return (*_it);
	}

	template <class T>
	random_access_iterator<T>  &random_access_iterator<T>::operator=(const random_access_iterator<T> &copy)
	{
	    _it = copy._it;
	    return (*this);
	}

	template <class T>
	random_access_iterator<T>  &random_access_iterator<T>::operator++()
	{
	    ++_it;
 	   return (*this);
	}

	template <class T>
	random_access_iterator<T>  random_access_iterator<T>::operator++(int)
	{
 	   random_access_iterator  tmp = *this;
  	  ++_it;
  	  return (tmp);
	}

	template <class T>
	random_access_iterator<T>  &random_access_iterator<T>::operator--()
	{
   	 --_it;
   	 return (*this);
	}

	template <class T>
	random_access_iterator<T>  random_access_iterator<T>::operator--(int)
	{
	    random_access_iterator  tmp = *this;
 	   --_it;
 	   return (tmp);
	}

	template <class T>
	random_access_iterator<T>  random_access_iterator<T>::operator+(const random_access_iterator<T>::difference_type n) const
	{
	    return (random_access_iterator<value_type>(_it + n));
	}

	template <class T>
	random_access_iterator<T>  random_access_iterator<T>::operator-(const random_access_iterator<T>::difference_type n) const
	{
 	   return (random_access_iterator<value_type>(_it - n));
	}

	template <class T>
	typename random_access_iterator<T>::difference_type  random_access_iterator<T>::operator+(random_access_iterator it) const
	{
	    return (_it + it._it);
	}

	template <class T>
	typename random_access_iterator<T>::difference_type  random_access_iterator<T>::operator-(random_access_iterator<T>::const_it it) const
	{
    	return (_it - it.operator->());
	}

	template <class T>
	random_access_iterator<T>  &random_access_iterator<T>::operator+= (difference_type n)
	{
	    _it += n;
 	   return (*this);
	}

	template <class T>
	random_access_iterator<T>  &random_access_iterator<T>::operator-= (difference_type n)
	{
 	   _it -= n;
 	   return (*this);
	}

	template <class T>
	typename random_access_iterator<T>::reference   random_access_iterator<T>::operator[](difference_type n) const
	{
   	 return (_it[n]);
	}
};

#endif
