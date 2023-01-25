/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:40:51 by agirona           #+#    #+#             */
/*   Updated: 2023/01/25 19:31:43 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <iostream>
# include "../iterator/bidirectional_iterator.tpp"
# include "../other/pair.hpp"
# include "../other/make_pair.hpp"
# include "../other/lexicographical_compare.hpp"
# include "../other/equal.hpp"
# include "elem.tpp"

namespace ft
{
	template <class T, class compare = std::less<typename T::first_type>, class Alloc = std::allocator<elem<T> > >
	class	tree
	{
		public :


			typedef	elem<T>											node;
			typedef	elem<T>											*node_ptr;
			typedef	Alloc											allocator_type;
			typedef compare											cmp_type;
			typedef	T												pair_type;
			typedef	typename pair_type::first_type					key_type;
			typedef	typename pair_type::second_type					value_type;
			typedef	bidirectional_iterator<pair_type>				iterator;
			typedef const_bidirectional_iterator<const pair_type>	const_iterator;


			//====		Constructors && Destructor		====

			tree();
			~tree();

			//====				Modifiers				====

			ft::pair<iterator, bool>	insert(const pair_type &val);
			void 						erase(const key_type &val);
			void						clear();
			void						swap(tree &x);

			//====				Capacity				====

			size_t						size() const;
			size_t						max_size() const;

			//====				Operations				====
			
			iterator					find(const key_type &val) const;

			//====				Iterators				====

			iterator					begin() const;
			iterator					end() const;

		private :


			node				*_origin;
			size_t				_size;
			allocator_type		_alloc;
			cmp_type			_cmp;
			node				*_real_end; //pointer toward the empty node at the end of the tree
			node				*_max; 		//pointer toward the node with the highter value in the tree

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
			void				is_del_max(const key_type &val, node *new_one);
			void				update_height(node *current);
			void				solo_update_height(node *current);

	};

	//====				Relational Operators					====
	
	template <class T, class C, class A>
	bool	operator<(const tree<T, C, A> &lhs, const tree<T, C, A> &rhs);

	template <class T, class C, class A>
	bool	operator>(const tree<T, C, A> &lhs, const tree<T, C, A> &rhs);

	template <class T, class C, class A>
	bool	operator==(const tree<T, C, A> &lhs, const tree<T, C, A> &rhs);
};

#endif
