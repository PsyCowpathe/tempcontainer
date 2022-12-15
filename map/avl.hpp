/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:40:51 by agirona           #+#    #+#             */
/*   Updated: 2022/12/15 13:55:23 by agirona          ###   ########lyon.fr   */
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

			void 		set_parent(elem *parent);
			void 		set_left(elem *left);
			void 		set_right(elem *right);
			void 		set_key(const T &key);
			elem		*get_parent() const;
			elem		*get_left() const;
			elem		*get_right() const;
			key_type	get_key() const;

		private :
			key_type	_key;
			value_type	_value;
			elem		*_parent;
			elem		*_left;
			elem		*_right;
	};


	template <class T, class Alloc = std::allocator<elem<T, T> >, class compare = std::less<T> >
	class	tree
	{
		public :
			typedef	elem<T, T>							node;
			typedef	Alloc								allocator_type;
			typedef compare								cmp_type;

			tree();
			~tree();

			void 		insert(const T &val);
			void 		erase(const T &val);
			node		*get_origin();

		private :
			node			*_origin;
			size_t			_size;
			allocator_type	_alloc;
			cmp_type		cmp;

			node		*new_node(const T &val);
			elem<T, T>	*oblitarate(elem<T, T> &to_delete, const int &direction);
			void		single_oblitarate(elem<T, T> &to_delete);
			void		complex_oblitarate(elem<T, T> &to_delete);
			void		clear_node(elem<T, T> *to_clear);
			void		balancing(elem<T, T> *new_one);
			int			get_sub_height(elem<T, T> *current);
			void		LL_rotate(elem<T, T> *grandpa, elem<T, T> *parent);
			void		RR_rotate(elem<T, T> *grandpa, elem<T, T> *parent);
			void		LR_rotate(elem<T, T> *grandpa, elem<T, T> *parent, elem<T, T> *child);
			void		RL_rotate(elem<T, T> *grandpa, elem<T, T> *parent, elem<T, T> *child);
			void		choose_rotate(elem<T, T> *current, int factor);

	};
};

#endif
