/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:29:39 by agirona           #+#    #+#             */
/*   Updated: 2022/12/05 10:55:31 by agirona          ###   ########lyon.fr   */
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
            typedef ft::iterator_traits<T>  							iterator_category;

            //CONSTRUCTOR
            random_access_iterator(); //
            random_access_iterator(pointer ptr); //
            random_access_iterator(const random_access_iterator &copy); //
            ~random_access_iterator();

            template <class c>
            friend bool             operator!=(const random_access_iterator<c> &lhs, const random_access_iterator<c> &rhs);//
            template <class c>
            friend bool             operator==(const random_access_iterator<c> &lhs, const random_access_iterator<c> &rhs);//
            template <class c>
            friend bool             operator<(const random_access_iterator<c> &lhs, const random_access_iterator<c> &rhs);//
            template <class c>
            friend bool             operator<=(const random_access_iterator<c> &lhs, const random_access_iterator<c> &rhs);//
            template <class c>
            friend bool             operator>(const random_access_iterator<c> &lhs, const random_access_iterator<c> &rhs);//
            template <class c>
            friend bool             operator>=(const random_access_iterator<c> &lhs, const random_access_iterator<c> &rhs);//
			template <class c>
            friend random_access_iterator<c>	operator+(const typename random_access_iterator<c>::difference_type &lhs, const random_access_iterator<c> &rhs);
			template <class c>
            friend random_access_iterator<c>	operator-(const typename random_access_iterator<c>::difference_type &lhs, const random_access_iterator<c> &rhs);


            pointer                 operator->() const;//
            reference               operator*() const;//
            random_access_iterator  &operator=(const random_access_iterator &copy);//
            random_access_iterator  &operator++();//
            random_access_iterator  operator++(int);//
            random_access_iterator  &operator--();//
            random_access_iterator  operator--(int);//
            random_access_iterator  operator+(difference_type n) const;//
            random_access_iterator  operator-(difference_type n) const;//
            difference_type         operator+(random_access_iterator it) const;
            difference_type         operator-(random_access_iterator it) const;
            random_access_iterator  &operator+= (difference_type n);//
            random_access_iterator  &operator-= (difference_type n);//
            reference               operator[](difference_type n) const;//

        private :
            pointer                         _it;

    };

};

#endif
