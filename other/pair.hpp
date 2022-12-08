/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:12:49 by agirona           #+#    #+#             */
/*   Updated: 2022/06/28 18:25:08 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace	ft
{
	template <class T1, class T2>
	struct pair
	{
		typedef typename T1 first_type;
		typedef typename T2 second_type;
		first_type			first;
		second_type			second;

		//constructors
		pair() : first(), second()
		{

		}

		template<class U, class V>
		pair(const pair<U, V> &ptr) : first(ptr.first), second(ptr.second)
		{

		}

		pair (const first_type &a, const second_type &b) : first(a), second(b)
		{

		}

		//surcharge
		pair	&operator=(const pair &pr)
		{
			this.first = pr.first;
			this.second = pr.second;
			return (*this);
		}

		template <class T1, class T2>
  		bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{
			return lhs.first==rhs.first && lhs.second==rhs.second;
		}

		template <class T1, class T2>
  		bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{
			return !(lhs==rhs);
		}

		template <class T1, class T2>
  		bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{
			return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
		}

		template <class T1, class T2>
  		bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{
			return !(rhs<lhs);
		}

		template <class T1, class T2>
  		bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{
			return rhs<lhs;
		}

		template <class T1, class T2>
  		bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{
			return !(lhs<rhs);
		}
	};
}

#endif
