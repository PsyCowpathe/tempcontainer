/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:48:16 by agirona           #+#    #+#             */
/*   Updated: 2023/01/18 17:14:23 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "../other/pair.hpp"
# include "../avl/tree.tpp"
# include "../iterator/bidirectional_iterator.tpp"
# include "../iterator/reverse_iterator.tpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
	class map
	{
		public :
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef pair<const Key, mapped_type>					value_type;
			typedef pair<Key, mapped_type>							used_value_type; //for bidirectional template
			typedef Compare											key_compare;
			//typedef value_comp									value_compare;
			typedef	Alloc											allocator_type;
			typedef	typename allocator_type::reference				reference;
			typedef	typename allocator_type::const_reference		const_reference;
			typedef	typename allocator_type::pointer				pointer;
			typedef	typename allocator_type::const_pointer			const_pointer;
			typedef	bidirectional_iterator<used_value_type>			iterator;
			typedef	bidirectional_iterator<const used_value_type>	const_iterator;
			typedef	reverse_iterator<iterator>						reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>			const_reverse_iterator; //pq le ft::?
			typedef	ptrdiff_t										difference_type;
			typedef	size_t											size_type;

			iterator			begin();
			reverse_iterator	rbegin();
			iterator			end();
			void				insert(const used_value_type &val);
			void				erase(const used_value_type &val);
			//value_compare value_comp() const;
			
		private :

			tree<used_value_type, key_compare>		_tree;
	};
};


#endif
