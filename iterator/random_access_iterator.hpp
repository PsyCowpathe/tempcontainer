/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:29:39 by agirona           #+#    #+#             */
/*   Updated: 2022/12/05 20:39:07 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef     RANDOM_ACCESS_ITERATOR_HPP
# define    RANDOM_ACCESS_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace   ft
{
    template <class T>
    class   random_access_iterator
    {
        public :
            typedef T                       							value_type;
            typedef T                       							*pointer;
            typedef T                       							&reference;
            typedef ptrdiff_t               							difference_type;
            typedef iterator_traits<T>  								iterator_category;
			typedef	random_access_iterator<const T>						const_it;

            //CONSTRUCTOR
            random_access_iterator(); //
            random_access_iterator(pointer ptr); //
            random_access_iterator(const random_access_iterator &copy); //
            ~random_access_iterator();

			operator	const_it() const { return const_it(_it); }

            bool             operator!=(const const_it &lhs) const;//
            bool             operator==(const const_it &lhs) const;//
            bool             operator<(const const_it &lhs) const;//
            bool             operator<=(const const_it &lhs) const;//
            bool             operator>(const const_it &lhs) const;//
            bool             operator>=(const const_it &lhs) const;//

			template <class c>
			friend random_access_iterator	operator+(const difference_type n, const random_access_iterator it);
			template <class c>
			friend random_access_iterator	operator-(const difference_type n, const random_access_iterator it);

            pointer                 operator->() const;//
            reference               operator*() const;//
            random_access_iterator  &operator=(const random_access_iterator &copy);//
            random_access_iterator  &operator++();//
            random_access_iterator  operator++(int);//
            random_access_iterator  &operator--();//
            random_access_iterator  operator--(int);//
            random_access_iterator  operator+(const difference_type n) const;//
            random_access_iterator  operator-(const difference_type n) const;//
            difference_type         operator+(random_access_iterator it) const;
            difference_type         operator-(const const_it it) const;
            random_access_iterator  &operator+= (difference_type n);//
            random_access_iterator  &operator-= (difference_type n);//
            reference               operator[](difference_type n) const;//

        private :
            pointer                         _it;

    };
};

#endif
