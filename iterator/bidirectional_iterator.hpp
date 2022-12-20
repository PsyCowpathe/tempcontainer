/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:16:10 by agirona           #+#    #+#             */
/*   Updated: 2022/12/20 17:49:01 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BIDIRECTIONAL_ITERATOR_HPP
# define 	BIDIRECTIONAL_ITERATOR_HPP

# include "../avl/avl.tpp"

namespace ft
{
	template <class T>
	class bidirectional_iterator
	{
		public :
			typedef	T								value_type;
			typedef	T								*pointer;
			typedef	T								&reference;
			typedef	ptrdiff_t						difference_type;
			typedef	iterator_traits<T>				iterator_category;
			typedef bidirectional_iterator<const T>	const_it;
			typedef	elem<T>							elem_type;

			//CONSTRUCTORS
			bidirectional_iterator();
			bidirectional_iterator(const bidirectional_iterator &copy);
			~bidirectional_iterator();

			bidirectional_iterator	&operator=(const bidirectional_iterator &copy); // avoir si le dereferencement est gerer

			bool	operator==(const const_it &rhs) const;
			bool	operator!=(const const_it &rhs) const;

			reference	operator*() const;
			pointer		operator->() const;
			bidirectional_iterator	&operator++();
			bidirectional_iterator	operator++(int);

			bidirectional_iterator	&operator--();
			bidirectional_iterator	operator--(int);

		private :

			//pointer		_it;
			elem_type	_it;
	};
};

#endif
