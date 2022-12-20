/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:40:51 by agirona           #+#    #+#             */
/*   Updated: 2022/12/20 17:48:57 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_HPP
# define AVL_HPP

# include <iostream>
# include "../iterator/random_access_iterator.tpp"
# include "../other/pair.hpp"
#include "../other/make_pair.hpp"

namespace ft
{
	template <class T>
	class	elem
	{
		public :
			typedef	typename T::first_type		key_type;
			typedef	typename T::second_type		value_type;
			typedef	T							pair_type;

			elem();
			elem(const pair_type &pair);
			~elem();

			void 		set_parent(elem *parent);
			void 		set_left(elem *left);
			void 		set_right(elem *right);
			void 		set_key(const key_type &key);
			void 		set_value(const value_type &value);
			void 		set_pair(const pair_type &pair);
			elem		*get_parent() const;
			elem		*get_left() const;
			elem		*get_right() const;
			key_type	get_key() const;
			value_type	get_value() const;
			pair_type	get_pair() const;
			elem		*next();
			

		private :
			pair_type	_pair;
			elem		*_parent;
			elem		*_left;
			elem		*_right;
	};


	template <class T, class Alloc = std::allocator<elem<T> >, class compare = std::less<typename T::first_type> >
	class	tree
	{
		public :
			typedef	elem<T>								node;
			typedef	elem<T>								*node_ptr;
			typedef	Alloc								allocator_type;
			typedef compare								cmp_type;
			typedef	T									pair_type;

			tree();
			~tree();

			void 		insert(const pair_type &val);
			void 		erase(const pair_type &val);
			node		*get_origin();

		private :
			node			*_origin;
			size_t			_size;
			allocator_type	_alloc;
			cmp_type		cmp;

			node		*new_node(const pair_type &val);
			elem<T>		*oblitarate(elem<T> &to_delete, const int &direction);
			void		single_oblitarate(elem<T> &to_delete);
			void		complex_oblitarate(elem<T> &to_delete);
			void		clear_node(elem<T> *to_clear);
			void		balancing(elem<T> *current);
			int			get_sub_height(elem<T> *current);
			void		LL_rotate(elem<T> *grandpa, elem<T> *parent);
			void		RR_rotate(elem<T> *grandpa, elem<T> *parent);
			void		LR_rotate(elem<T> *grandpa, elem<T> *parent, elem<T> *child);
			void		RL_rotate(elem<T> *grandpa, elem<T> *parent, elem<T> *child);
			void		choose_rotate(elem<T> *current, int factor);

	};
};

#endif
