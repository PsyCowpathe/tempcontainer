/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:00:47 by agirona           #+#    #+#             */
/*   Updated: 2022/12/22 13:23:40 by agirona          ###   ########lyon.fr   */
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
			pair_type	*get_pair();
			elem		*next();
			elem		*prev();
			

		private :
			pair_type	_pair;
			elem		*_parent;
			elem		*_left;
			elem		*_right;
	};
}

#endif