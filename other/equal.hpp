/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:00:44 by agirona           #+#    #+#             */
/*   Updated: 2022/11/07 17:00:56 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft
{
	template <class InputIterator1, class InputTterator2>
	bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != first2)
		{
			if (*first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return true;
	}

	template <class InputIterator1, class InputTterator2, class BinaryPredicate>
	bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != first2)
		{
			if (!pred(*first1 , *first2))
				return false;
			first1++;
			first2++;
		}
		return true;
	}
};

#endif
