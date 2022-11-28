/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:54:26 by agirona           #+#    #+#             */
/*   Updated: 2022/11/28 23:37:52 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "../iterator/reverse_iterator.tpp"
# include "../iterator/random_access_iterator.tpp"
# include "../other/enable_if.hpp"
# include "../other/is_integral.hpp"

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

            
            //-------------		Public Method		-------------
			//====		Constructors, Destructor && operator	====
			
			explicit    vector(const allocator_type &alloc = allocator_type());
            explicit    vector(size_type n, const value_type &val = value_type(),
								const allocator_type &alloc = allocator_type());
			vector(const vector &x);
			~vector();

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());
			vector	&operator=(const vector &x);

			//====				Iterators				====
			
			iterator    			begin();
			const_iterator 			begin() const;
            iterator    			end();
			const_iterator 			end() const;
			reverse_iterator		rbegin();
			const_reverse_iterator 	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator 	rend() const;

			//====				Capacity				====
			
            size_type   		size() const;
			size_type			max_size() const;
			void				resize(size_type n, value_type val = value_type());
            size_type   		capacity() const;
			bool				empty() const;
			void    			reserve(size_type n);

			//====			  Element Access			====

			reference 			operator[](size_type n);
			const_reference 	operator[] (size_type n) const;
			reference 			at(size_type n);
			const_reference 	at(size_type n) const;
			reference 			front();
			const_reference 	front() const;
			reference 			back();
			const_reference 	back() const;

			//====				Modifiers				====
			

			template <class InputIterator>
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
								assign(InputIterator first, InputIterator last);
            void        		assign(size_type n, const value_type &val);
            void        		push_back(const value_type &val);
			void				pop_back();
			iterator 			insert(iterator position, const value_type &val);
			void				insert(iterator position, size_type n, const value_type &val);

			template <class InputIterator>
			typename 	enable_if<!is_integral<InputIterator>::value, void>::type
								insert(iterator position, InputIterator first, InputIterator last);
			iterator 			erase(iterator position);
			iterator 			erase(iterator first, iterator last);
			void 				swap(vector &x);
			void 				clear();
			//====				Allocator				====

			allocator_type 		get_allocator() const;

			
		private :

           	allocator_type      _alloc;
           	pointer             _start;
           	pointer             _end;
            pointer             _storage_end;

           	void				allocate_memory(size_type size);
           // void              deallocate_memory(const pointer start, const pointer end);
           	pointer	        	set_range(const pointer &start, const pointer &end, const value_type &val);
           	pointer             set_storage_end(const pointer &start, const size_t &size);
			template <class InputIterator>
			void				cpy_range(InputIterator start, InputIterator end);
			iterator			alloc_insert_values(const iterator pos, iterator new_start, iterator new_end);
			iterator			insert_values(const iterator pos, iterator new_start, iterator new_end);
			void				clear_block(const pointer start, const pointer end, const difference_type size);
			iterator			remove_values(iterator first, iterator last);
    };
};

#endif
