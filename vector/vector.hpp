/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:54:26 by agirona           #+#    #+#             */
/*   Updated: 2022/11/02 20:15:42 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "../iterator/reverse_iterator.tpp"
# include "../iterator/random_access_iterator.tpp"

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
        public :
            typedef T                                                   	    value_type;
            typedef Alloc                                           	       	allocator_type;
            typedef typename allocator_type::reference          	            reference;
            typedef typename allocator_type::const_reference					const_reference;
            typedef typename allocator_type::pointer                    	  	pointer;
            typedef typename allocator_type::const_pointer          	        const_pointer;
            typedef ft::random_access_iterator<value_type>     	           		iterator;
            typedef ft::random_access_iterator<value_type> 	           			const_iterator;
            typedef ft::reverse_iterator<iterator>                     	   		reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>           				const_reverse_iterator;
            typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
            typedef size_t                                                  	size_type;

            //CONSTRUCTOR
            explicit    vector(const allocator_type &alloc = allocator_type());
            explicit    vector(size_type n, const value_type &val = value_type(),
								const allocator_type &alloc = allocator_type());
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
			typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = 0);
			vector(const vector &x);

            //Member function
            void        		assign(size_type n, const value_type &val);
            size_type   		capacity() const;
            size_type   		size() const;
            void        		push_back(const value_type &val);
            iterator    		begin();
            iterator    		end();
			reverse_iterator	rend();
			reverse_iterator	rbegin();

		private :

           	allocator_type      _alloc;
           	pointer             _start;
           	pointer             _end;
            pointer             _storage_end;

           // pointer           allocate_memory(size_type size);
           // void              deallocate_memory(const pointer start, const pointer end);
           	pointer            	set_range(const pointer &start, const pointer &end, const value_type &val);
           	pointer             set_storage_end(const pointer start, const size_t size);
			template <class InputIterator>
			pointer				cpy_range(InputIterator start, InputIterator end);
    };
};

#endif
