/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:00:12 by agirona           #+#    #+#             */
/*   Updated: 2022/11/18 16:07:38 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace	ft
{
	template <bool, typename T = void>
	struct enable_if
	{

	};

	template <typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
};

#endif
