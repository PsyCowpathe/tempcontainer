/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:34:10 by agirona           #+#    #+#             */
/*   Updated: 2022/12/20 17:49:03 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef     REVERSE_ITERATOR_HPP
# define    REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{

	template<class Iterator>
	class HeapReverseIterator
	{
		public:
    		typedef Iterator iterator_type;

    		template<class IteratorType>
    		bool operator==(const HeapReverseIterator<IteratorType> &rhs) const
			{
        		return it == rhs.it;
    		}

    		template<class HeapReverseIteratorIterator>
   	 		friend class HeapReverseIterator;

		private:
    		iterator_type it;
    		iterator_type prev_it;
};

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

			template <class Iter>
            reverse_iterator(const reverse_iterator<Iter> &rev_it);//

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
			
			
    };
			//STD OFFICIAL PATCH for const vs no const operation --> https://cplusplus.github.io/LWG/issue280#23.5.1.2

   			template <class Iterator1, class Iterator2>
            bool        operator!=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs);//

   			template <class Iterator1, class Iterator2>
            bool        operator<(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs);//

   			template <class Iterator1, class Iterator2>
            bool        operator<=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs);//

   			template <class Iterator1, class Iterator2>
            bool        operator==(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs);//

   			template <class Iterator1, class Iterator2>
            bool        operator>(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs);//

   			template <class Iterator1, class Iterator2>
            bool		operator>=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs);//

			template <class it>
            reverse_iterator<it>                              operator+(typename reverse_iterator<it>::difference_type n,
                                                                                const reverse_iterator<it> &rev_it);

   			template <class Iterator1, class Iterator2>
            typename reverse_iterator<Iterator1>::difference_type    operator-(const reverse_iterator<Iterator1>& lhs,
                                                                                const reverse_iterator<Iterator2>& rhs);

};

#endif
