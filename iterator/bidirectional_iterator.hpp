/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:16:10 by agirona           #+#    #+#             */
/*   Updated: 2023/01/25 17:38:11 by agirona          ###   ########lyon.fr   */
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
			//typedef	iterator_traits<T>				iterator_category;
			typedef	std::bidirectional_iterator_tag				iterator_category;
			typedef	elem<T>							elem_type;

			//CONSTRUCTORS
			bidirectional_iterator();
			bidirectional_iterator(const bidirectional_iterator &copy);
			bidirectional_iterator(elem_type *copy);
			~bidirectional_iterator();

			bidirectional_iterator	&operator=(const bidirectional_iterator &copy);

			bool	operator==(const bidirectional_iterator &rhs) const;
			bool	operator!=(const bidirectional_iterator &rhs) const;

			reference	operator*() const;
			pointer		operator->() const;
			bidirectional_iterator	&operator++();
			bidirectional_iterator	operator++(int);

			bidirectional_iterator	&operator--();
			bidirectional_iterator	operator--(int);

			elem_type	*_it;
			pointer		_pair;
	};

	template <class T>
	class const_bidirectional_iterator
	{
		public :
			typedef	T								value_type;
			typedef	const T							*pointer;
			typedef	const T							&reference;
			typedef	ptrdiff_t						difference_type;
			//typedef	iterator_traits<T>				iterator_category;
			typedef	std::bidirectional_iterator_tag				iterator_category;
			typedef	elem<T>							elem_type;

			//CONSTRUCTORS
			const_bidirectional_iterator();
			const_bidirectional_iterator(const const_bidirectional_iterator &copy);
			const_bidirectional_iterator(const bidirectional_iterator<T> &copy);
			const_bidirectional_iterator(elem_type *copy);
			~const_bidirectional_iterator();

			const_bidirectional_iterator	&operator=(const const_bidirectional_iterator &copy);

			bool	operator==(const const_bidirectional_iterator &rhs) const;
			bool	operator!=(const const_bidirectional_iterator &rhs) const;

			reference	operator*() const;
			pointer		operator->() const;
			const_bidirectional_iterator	&operator++();
			const_bidirectional_iterator	operator++(int);

			const_bidirectional_iterator	&operator--();
			const_bidirectional_iterator	operator--(int);
			friend bool	operator==(const bidirectional_iterator<T> &lhs, const const_bidirectional_iterator &rhs)
			{
				return (lhs.operator->() == rhs.operator->());
			}

			friend bool	operator!=(const bidirectional_iterator<T> &lhs, const const_bidirectional_iterator &rhs)
			{
				return (lhs._it != rhs._it);
			}

			elem_type	*_it;
			pointer		_pair;
	};
};

#endif
