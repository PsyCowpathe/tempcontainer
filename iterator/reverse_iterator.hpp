/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:34:10 by agirona           #+#    #+#             */
/*   Updated: 2022/12/05 20:39:06 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef     REVERSE_ITERATOR_HPP
# define    REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
            private :
                Iterator                                                            _current;
            public : 
                typedef Iterator                                                iterator_type;
                typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
                typedef typename iterator_traits<Iterator>::value_type	        value_type;
                typedef typename iterator_traits<Iterator>::difference_type	    difference_type;
                typedef typename iterator_traits<Iterator>::pointer	            pointer;
                typedef typename iterator_traits<Iterator>::reference	        reference;

            //Member function
            reverse_iterator(); //
            explicit reverse_iterator (iterator_type it);//
            reverse_iterator(const reverse_iterator &rev_it);//

            iterator_type       base() const;

            reference           operator*() const;//
            reverse_iterator    operator+(difference_type n) const;//
            reverse_iterator    &operator++();//
            reverse_iterator    operator++(int);//
            reverse_iterator    &operator+= (difference_type n);//
            reverse_iterator    operator-(difference_type n) const;//
            reverse_iterator    &operator--();//
            reverse_iterator    operator--(int);//
            reverse_iterator    &operator-=(difference_type n);//
            pointer             operator->() const;//
            reference           operator[](difference_type n) const;//
			
			template <class it>
            friend bool        	operator!=(const reverse_iterator<it> &lhs, const reverse_iterator<it> &rhs);//
			template <class it>
            friend bool         operator<(const reverse_iterator<it> &lhs, const reverse_iterator<it> &rhs);//
			template <class it>
            friend bool         operator<=(const reverse_iterator<it> &lhs, const reverse_iterator<it> &rhs);//
			template <class it>
            friend bool         operator==(const reverse_iterator<it> &lhs, const reverse_iterator<it> &rhs);//
			template <class it>
            friend bool         operator>(const reverse_iterator<it> &lhs, const reverse_iterator<it> &rhs);//
			template <class it>
            friend bool        	operator>=(const reverse_iterator<it> &lhs, const reverse_iterator<it> &rhs);//

			template <class it>
            friend reverse_iterator<it>                              operator+(typename reverse_iterator<it>::difference_type n, //pas sur pour le friend
                                                                                const reverse_iterator<it> &rev_it);

			template <class it>
            friend typename reverse_iterator<it>::difference_type    operator-(const reverse_iterator<it>& lhs, //pas sur pour le friend
                                                                                const reverse_iterator<it>& rhs);

    };
};

#endif
