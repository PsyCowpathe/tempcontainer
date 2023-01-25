/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:48:16 by agirona           #+#    #+#             */
/*   Updated: 2023/01/25 19:31:43 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "../other/pair.hpp"
# include "../avl/tree.tpp"
# include "../iterator/bidirectional_iterator.tpp"
# include "../iterator/reverse_iterator.tpp"
# include "../other/enable_if.hpp"
# include "../other/is_integral.hpp"

#include <math.h>

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
			typedef	ft::reverse_iterator<const_iterator>				const_reverse_iterator;
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

			map										&operator=(const map &x);
			mapped_type								&operator[](const key_type &k);

			//====				Iterators				====

			iterator								begin();
			const_iterator 							begin() const;
			iterator								end();
			const_iterator							end() const;
			reverse_iterator						rbegin();
			const_reverse_iterator					rbegin() const;
			reverse_iterator 						rend();
			const_reverse_iterator				 	rend() const;

			//====				Capacity				====

			bool 									empty() const;
			size_type 								size() const;
			size_type 								max_size() const;

			//====				Modifiers				====
			
			pair<iterator, bool>					insert(const value_type &val);
			iterator 								insert(iterator position, const value_type& val);

			template <class InputIterator>
			typename enable_if<!is_integral<InputIterator>::value, void>::type
													insert(InputIterator first, InputIterator last);
			void 									erase(iterator position);	
			size_type								erase(const key_type &k);
			void									erase(iterator first, iterator last);
			void									swap(map &x);
			void 									clear();


			//====				Observers				====

			key_compare								key_comp() const;
			value_compare							value_comp() const;

			//====				Operations				====


			iterator 								find(const key_type &k);
			const_iterator 							find(const key_type &k) const;
			size_type 								count(const key_type &k) const;
			iterator 								lower_bound(const key_type &k);
			const_iterator 							lower_bound(const key_type &k) const;
			iterator 								upper_bound(const key_type &k);
			const_iterator 							upper_bound(const key_type &k) const;
			pair<const_iterator, const_iterator>	equal_range(const key_type &k) const;
			pair<iterator,iterator>					equal_range(const key_type &k);


			//====				Allocator				====

			allocator_type							get_allocator() const;

			//====				Friend					====

			template <class K, class V, class C, class A>
			friend bool	operator==(const map<K, V, C, A> &lhs, const map<K, V, C, A> &rhs);

			template <class K, class V, class C, class A>
  			friend bool	operator<(const map<K, V, C, A> &lhs, const map<K, V, C, A> &rhs);

		private :

			tree<used_value_type, key_compare>		_tree;
			allocator_type							_alloc;
			key_compare								_comp;
	};

	//====			Relational Operators				====

	
	template <class Key, class T, class Compare, class Alloc>
	bool	operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
  	bool	operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
  	bool	operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
  	bool	operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs);


	//====			 		Other						====


	template <class Key, class T, class Compare, class Alloc>
	void	swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y);
};


#endif
