/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:40:51 by agirona           #+#    #+#             */
/*   Updated: 2022/12/08 20:09:50 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_HPP
# define AVL_HPP

# include <iostream>
# include "../iterator/random_access_iterator.tpp"

namespace ft
{
	template <class T, class V>
	class	elem
	{
		public :
			typedef	T									key_type;
			typedef	V									value_type;

			elem();
			elem(key_type key);
			~elem();

			void 		set_parent(const elem<T, V> &parent);
			void 		set_left(const elem<T, V> &left);
			void 		set_right(const elem<T, V> &right);
			elem<T, V>	*get_parent() const;
			elem<T, V>	*get_left() const;
			elem<T, V>	*get_right() const;

		private :
			key_type	_key;
			value_type	_value;
			elem<T, V>	*_parent;
			elem<T, V>	*_left;
			elem<T, V>	*_right;
	};


	template <class T, class Alloc = std::allocator<T> >
	class	tree
	{
		public :
			typedef	elem<T, T>							node;
			typedef	Alloc								allocator_type;
			typedef	random_access_iterator<node>		iterator; //tmp, replace by bidirectionnal

			tree();
			~tree();

			void 		insert(const T &val);

		private :
			node			_origin;
			size_t			_size;
			allocator_type	_alloc;

			pointer		new_node();

	};
};

#endif
