/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:00:47 by agirona           #+#    #+#             */
/*   Updated: 2023/01/26 10:25:19 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEM_HPP
# define ELEM_HPP

# include "../other/pair.hpp"

namespace ft
{
	template <class T>
	class	elem
	{
		public :

			typedef	elem<T>						node;
			typedef	typename T::first_type		key_type;
			typedef	typename T::second_type		value_type;
			typedef	T							pair_type;

			//====		Constructors && Destructor		====

			elem();
			elem(const pair_type &pair);
			~elem();

			//====				Setters					====

			void 		set_parent(node *parent);
			void 		set_left(node *left);
			void 		set_right(node *right);
			void 		set_key(const key_type &key);
			void 		set_value(const value_type &value);
			void 		set_pair(const pair_type &pair);
			void 		set_end(node *end);
			void 		set_print(const bool printable);
			void		set_ptr_last(node *ptr);
			void		set_height(size_t height);

			//====				Getters					====

			pair_type	*get_pair(); 
			key_type	get_key() const;
			
			//====				Iterators				====

			elem		*next();
			elem		*prev();



		//private :

			pair_type	_pair;
			elem		*_parent;
			elem		*_left;
			elem		*_right;
			elem		*_end; //pointer toward real_end tree's variable
			elem		*_ptr_last;// pointer toward max tree's variable
			bool		_printable;
			size_t		_height;

			//====				Tools					====

			elem		*mini(elem *start) const;
			elem		*maxi(elem *start) const;
	};
}

#endif
