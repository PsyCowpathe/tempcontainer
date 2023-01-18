/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:16:10 by agirona           #+#    #+#             */
/*   Updated: 2023/01/18 17:14:22 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BIDIRECTIONAL_ITERATOR_HPP
# define 	BIDIRECTIONAL_ITERATOR_HPP

# include "../avl/elem.tpp"
# include "../iterator/iterator_traits.hpp"

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
			bidirectional_iterator(elem_type *copy);
			~bidirectional_iterator();

			bidirectional_iterator	&operator=(const bidirectional_iterator &copy); // avoir si le dereferencement est gerer

			bool	operator==(const const_it &rhs) const;
			bool	operator!=(const bidirectional_iterator &rhs) const;

			reference	operator*() const;
			pointer		operator->() const;
			bidirectional_iterator	&operator++();
			bidirectional_iterator	operator++(int);

			bidirectional_iterator	&operator--();
			bidirectional_iterator	operator--(int);

		private :

			elem_type	*_it;
			pointer		_pair;
	};
};

#endif
