/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:40:51 by agirona           #+#    #+#             */
/*   Updated: 2023/01/20 17:40:06 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <iostream>
# include "../iterator/bidirectional_iterator.tpp"
# include "../other/pair.hpp"
# include "../other/make_pair.hpp"
# include "elem.tpp"

namespace ft
{
	template <class T, class compare = std::less<typename T::first_type>, class Alloc = std::allocator<elem<T> > >
	class	tree
	{
		public :

			typedef	elem<T>									node;
			typedef	elem<T>									*node_ptr;
			typedef	Alloc									allocator_type;
			typedef compare									cmp_type;
			typedef	T										pair_type;
			typedef	bidirectional_iterator<pair_type>		iterator;
			typedef const_bidirectional_iterator<const pair_type>					const_iterator;

			//====		Constructors && Destructor		====

			tree();
			~tree();

			//====				Modifiers				====

			void 				insert(const pair_type &val);
			void 				erase(const pair_type &val);
			void				clear();

			//====				Iterators				====

			iterator			begin() const;
			iterator			end() const;


			node				*_origin; //private !!

		private :

			size_t				_size;
			allocator_type		_alloc;
			cmp_type			cmp;
			node				*_real_end; //pointer on an empty node at the end of the tree
			node				*_max; 		//pointer on a node with the highter value in the tree

			//====				Modifiers				====

			void				single_oblitarate(elem<T> &to_delete);
			void				complex_oblitarate(elem<T> &to_delete);
			void				oblitarate(elem<T> &to_delete, const int &direction);

			//====				Capacity				====

			node				*new_node(const pair_type &val);
			void				clear_node(elem<T> *to_clear);

			//====				Rotators				====

			void				LL_rotate(elem<T> *grandpa, elem<T> *parent);
			void				RR_rotate(elem<T> *grandpa, elem<T> *parent);
			void				LR_rotate(elem<T> *grandpa, elem<T> *parent, elem<T> *child);
			void				RL_rotate(elem<T> *grandpa, elem<T> *parent, elem<T> *child);
			void				choose_rotate(elem<T> *current, int factor);
			void				balancing(elem<T> *current);

			//====				Tools					====

			node				*maxi() const;
			node				*mini() const;
			void				change_max();
			void				is_new_max(node *new_one);
			void				is_del_max(const pair_type &val, node *new_one);
			int					get_sub_height(elem<T> *current);

	};
};

#endif
