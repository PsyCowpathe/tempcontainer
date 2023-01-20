/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:48:16 by agirona           #+#    #+#             */
/*   Updated: 2023/01/20 17:40:04 by agirona          ###   ########lyon.fr   */
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
			typedef Key													key_type;
			typedef T													mapped_type;
			typedef pair<const Key, mapped_type>						value_type;
			typedef pair<Key, mapped_type>								used_value_type; //for bidirectional template
			typedef Compare												key_compare;
			typedef	Alloc												allocator_type;
			typedef	typename allocator_type::reference					reference;
			typedef	typename allocator_type::const_reference			const_reference;
			typedef	typename allocator_type::pointer					pointer;
			typedef	typename allocator_type::const_pointer				const_pointer;
			typedef	bidirectional_iterator<used_value_type>				iterator;
			typedef	const_bidirectional_iterator<used_value_type>		const_iterator;
			typedef	reverse_iterator<iterator>							reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>				const_reverse_iterator; //pq le ft::?
			typedef	ptrdiff_t											difference_type;
			typedef	size_t												size_type;

			class value_compare
            {
				friend class map<key_type, mapped_type, key_compare, Alloc>;
                protected:
                      key_compare comp;
                      value_compare (Compare c) : comp(c) {}
                public:

                      bool operator() (const value_type& x, const value_type& y) const
                      {
						  return comp(x.first, y.first);
                      }
            };

			//====		Constructors && Destructor		====
			
			explicit map (const key_compare &comp = key_compare(), const allocator_type& alloc = allocator_type());

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
			map (const map &x);
			~map();

			//====				Operators				====

			map					&operator=(const map &x);

			//====				Iterators				====

			iterator			begin();
			const_iterator 		begin() const;
			iterator			end();
			const_iterator		end() const;
			reverse_iterator	rbegin();

			//====				Modifiers				====
			
			void				insert(const value_type &val);
			iterator 			insert(iterator position, const value_type& val);

			template <class InputIterator>
			void 				insert(InputIterator first, InputIterator last);
			void				erase(const value_type &val);
			void				erase(iterator first, iterator last);
			void 				clear();

		private :

			tree<used_value_type, key_compare>		_tree;
			allocator_type							_alloc;
			key_compare								_comp;
	};
};


#endif
