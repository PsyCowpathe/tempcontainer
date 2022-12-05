/* **************************************************************************** */
/*                                                                              */
/*                                                         :::      ::::::::    */
/*    stack.tpp                                          :+:      :+:    :+:    */
/*                                                     +:+ +:+         +:+      */
/*    By: agirona <marvin@42.fr>                     +#+  +:+       +#+         */
/*                                                 +#+#+#+#+#+   +#+            */
/*    Created: 2022/12/05 12:15:49 by agirona           #+#    #+#              */
/*    Updated: 2022/12/05 12:15:49 by agirona          ###   ########lyon.fr    */
/*                                                                              */
/* **************************************************************************** */

# include "stack.hpp"

namespace ft
{
	template <class T, class Container>
	stack<T, Container>::stack (const container_type &cntr) : _ctnr(cntr)
	{
		return ;
	}

	template <class T, class Container>
	bool	stack<T, Container>::empty() const
	{
		return (_ctnr.empty());
	}

	template <class T, class Container>
	typename stack<T, Container>::size_type   stack<T, Container>::size() const
	{
		return (_ctnr.size());
	}

	template <class T, class Container>
	typename stack<T, Container>::value_type  &stack<T, Container>::top()
	{
		return (_ctnr.back());
	}

	template <class T, class Container>
	const typename stack<T, Container>::value_type  &stack<T, Container>::top() const
	{
		return (_ctnr.back());
	}

	template <class T, class Container>
	void    stack<T, Container>::push(const value_type &val)
	{
		_ctnr.push_back(val);
	}

	template <class T, class Container>
	void    stack<T, Container>::pop()
	{
		_ctnr.pop_back();
	}
}
