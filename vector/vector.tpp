/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:54:26 by agirona           #+#    #+#             */
/*   Updated: 2022/10/31 18:54:28 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
# define VECTOR_TPP
# include "vector.hpp"

namespace ft
{
    //-------------		Public Method		-------------

	//====		Constructors, Destructor &&	operator	====
	
    template <class T, class A>
    vector<T, A>::vector(const typename vector<T, A>::allocator_type &alloc) :  _alloc(alloc),
	_start(NULL), _end(NULL), _storage_end(NULL)
    {

    }

    template <class T, class A>
    vector<T,A>::vector(typename vector<T, A>::size_type n, const typename vector<T, A>::value_type &val,
							const typename vector<T, A>::allocator_type &alloc) : _alloc(alloc)
    {
		allocate_memory(n);
		std::cout << "const start = " << _start << std::endl;
		std::cout << "const storage = " << _storage_end << std::endl;
		std::cout << "const diff = " << _storage_end - _start << std::endl;
		_end = set_range(_start, _storage_end, val);
		/*size_t	i;

		i = 0;
		while (i < n)
		{
			push_back(val);
			i++;
		}*/
    }

	template <class T, class A>
	template <class InputIterator>
	vector<T,A>::vector(InputIterator first, InputIterator last,
						const vector<T, A>::allocator_type &alloc) : _alloc(alloc)
	{
		assign(first, last);
	}

    template <class T, class A>
	vector<T, A>	&vector<T, A>::operator=(const vector<T, A> &x)
	{
		assign(x.begin(), x.end());
		return (*this);
	}

	template <class T, class A>
	vector<T, A>::vector(const vector<T, A> &x) : _alloc(x._alloc)
	{
		*this = x;
	}

    template <class T, class A>
	vector<T, A>::~vector()
	{
		clear_block(_start, _end, capacity());
	}


	//====		Iterators		====
	
    template <class T, class A>
    typename vector<T, A>::iterator			vector<T, A>::begin()
    {
        return (_start);
    }

	template <class T, class A>
    typename vector<T, A>::const_iterator	vector<T, A>::begin() const
    {
        return (_start);
    }

    template <class T, class A>
    typename vector<T, A>::iterator			vector<T, A>::end()
    {
        return (_end);
    }

	template <class T, class A>
    typename vector<T, A>::const_iterator	vector<T, A>::end() const
    {
        return (_end);
    }

    template <class T, class A>
    typename vector<T, A>::reverse_iterator	vector<T, A>::rbegin()
	{
		return (reverse_iterator(end()));
	}

    template <class T, class A>
    typename vector<T, A>::const_reverse_iterator	vector<T, A>::rbegin() const
	{
		return (reverse_iterator(end()));
	}

    template <class T, class A>
    typename vector<T, A>::reverse_iterator	vector<T, A>::rend()
	{
		return (reverse_iterator(begin()));
	}

    template <class T, class A>
    typename vector<T, A>::const_reverse_iterator	vector<T, A>::rend() const
	{
		return (reverse_iterator(begin()));
	}


	//====		Capacity 			====
	
	template <class T, class A>
    typename vector<T, A>::size_type   vector<T, A>::size() const
    {
        return static_cast<size_type>(_end - _start);
    }

	template <class T, class A>
    typename vector<T, A>::size_type   vector<T, A>::max_size() const
    {
		return std::numeric_limits<size_type>::max() / sizeof(T);
    }

	template <class T, class A>
	void	vector<T, A>::resize(vector<T, A>::size_type n, vector<T, A>::value_type val)
	{
		vector<T, A>::pointer	save_start;
		vector<T, A>::pointer	save_end;
		size_t					save_storage;

		if (n > capacity())
		{
			save_start = _start;
			save_end = _end;
			save_storage = capacity();
			vector<T, A>	tmp(n - size(), val);
			alloc_insert_values(end(), tmp.begin(), tmp.end());
			clear_block(save_start, save_end, save_storage);
		}
		else
			remove_values(begin() + n, end());
	}

    template <class T, class A>
    typename vector<T, A>::size_type	vector<T, A>::capacity() const
    {
        return static_cast<size_type>(_storage_end - _start);
    }

    template <class T, class A>
	bool 	vector<T, A>::empty() const
	{
		if (size() == 0)
			return (1);
		return (0);
	}

    template <class T, class A>
	void	vector<T, A>::reserve(vector<T, A>::size_type n)
	{
		vector<T, A>::pointer	save_start;
		vector<T, A>::pointer	save_end;
		size_t					save_storage;

		if (n > capacity())
		{
			save_start = _start;
			save_end = _end;
			save_storage = capacity();
			allocate_memory(n + size());
			insert_values(begin(), save_start, save_end);
			clear_block(save_start, save_end, save_storage);
		}
	}


	//====		Element Access 		====

    template <class T, class A>
	typename vector<T, A>::reference		vector<T, A>::operator[](vector<T, A>::size_type n)
	{
		return (_start[n]);
	}

	template <class T, class A>
	typename vector<T, A>::const_reference	vector<T, A>::operator[](vector<T, A>::size_type n) const
	{
		return (_start[n]);
	}

	template <class T, class A>
	typename vector<T, A>::reference		vector<T, A>::at(vector<T, A>::size_type n)
	{
		return (_start[n]);
	}
	
	template <class T, class A>
	typename vector<T, A>::const_reference	vector<T, A>::at(vector<T, A>::size_type n) const
	{
		return (_start[n]);
	}

	template <class T, class A>
	typename vector<T, A>::reference		vector<T, A>::front()
	{
		return (*begin());
	}
	
	template <class T, class A>
	typename vector<T, A>::const_reference	vector<T, A>::front() const
	{
		return (*begin());
	}

	template <class T, class A>
	typename vector<T, A>::reference		vector<T, A>::back()
	{
		return (*(end() - 1));
	}
	
	template <class T, class A>
	typename vector<T, A>::const_reference	vector<T, A>::back() const
	{
		return (*(end() - 1));
	}


	//====		Modifiers 			====

    template <class T, class A>
	template <class InputIterator>
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
	vector<T, A>::assign (InputIterator first, InputIterator last)
	{
		vector<T, A>::pointer	save_start;
		vector<T, A>::pointer	save_end;
		size_t					save_storage;
		size_t					size;

		size = last - first;
		if (size > capacity())
		{
			save_start = _start;
			save_end = _end;
			save_storage = capacity();
			allocate_memory(size * 2);
			insert_values(begin(), first, last);
			clear_block(save_start, save_end, save_storage);
		}
		else
		{
			remove_values(begin(), end());
			insert_values(begin(), first, last);
		}
	}

    template <class T, class A>
    void    vector<T, A>::assign(vector<T, A>::size_type n, const vector<T, A>::value_type &val)
	{
		vector<T, A>::pointer	save_start;
		vector<T, A>::pointer	save_end;
		vector<T, A>			tmp(n, val);
		size_t					save_storage;

		if (n > capacity())
		{
			save_start = _start;
			save_end = _end;
			save_storage = capacity();
			allocate_memory(n * 2);
			insert_values(begin(), tmp.begin(), tmp.end());
			clear_block(save_start, save_end, save_storage);
		}
		else
		{
			remove_values(begin(), end());
			insert_values(begin(), tmp.begin(), tmp.end());
		}
	}

    template <class T, class A>
    void    vector<T, A>::push_back(const typename vector<T, A>::value_type &val)
    {
		vector<T, A>::pointer	save_start;
		vector<T, A>::pointer	save_end;
		size_t					save_storage;

		if (capacity() == 0)
		{
			allocate_memory(capacity() + 1);
			push_back(val);
		}
		else if (_end == _storage_end)
		{
			save_start = _start;
			save_end = _end;
			save_storage = capacity();
			allocate_memory(capacity() * 2);
			cpy_range(save_start, save_end);
			push_back(val);
			clear_block(save_start, save_end, save_storage);
		}
		else
		{
        	_alloc.construct(_end, val);
        	_end++;
		}
    }

	template <class T, class A>
	void	vector<T, A>::pop_back()
	{
		_alloc.destroy(_end);
		_end -= 1;
	}

	template <class T, class A>
	template <class InputIterator>
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
	vector<T, A>::insert(typename vector<T, A>::iterator position, InputIterator first, InputIterator last)
	{
		vector<T, A>::pointer	save_start;
		vector<T, A>::pointer	save_end;
		size_t					save_storage;

		if (last - first + size() > capacity())
		{
			save_start = _start;
			save_end = _end;
			save_storage = capacity();
			alloc_insert_values(position, first, last);
			clear_block(save_start, save_end, save_storage);
		}
		else
			insert_values(position, first, last);
	}

    template <class T, class A>
	void	vector<T, A>::insert(typename vector<T, A>::iterator position, typename vector<T, A>::size_type n,
									const typename vector<T, A>::value_type &val)
	{
		vector<T, A>						tmp;
		typename vector<T,A>::size_type		count;
		vector<T, A>::pointer				save_start;
		vector<T, A>::pointer				save_end;
		size_t								save_storage;

		count = 0;
		while (count < n)
		{
			tmp.push_back(val);
			count++;
		}
		if (size() + n > capacity())
		{
			save_start = _start;
			save_end = _end;
			save_storage = capacity();
			alloc_insert_values(position, tmp.begin(), tmp.end());
			clear_block(save_start, save_end, save_storage);
		}
		else
			insert_values(position, tmp.begin(), tmp.end());			
	}

    template <class T, class A>
	typename vector<T, A>::iterator		vector<T, A>::insert(typename vector<T, A>::iterator position,
																const typename vector<T, A>::value_type &val)
	{
		vector<T, A>			tmp;
		vector<T, A>::pointer	save_start;
		vector<T, A>::pointer	save_end;
		vector<T, A>::iterator	ret;
		size_t					save_storage;

		tmp.push_back(val);
		if (size() + 1 > capacity())
		{
			save_start = _start;
			save_end = _end;
			save_storage = capacity();
			ret = alloc_insert_values(position, tmp.begin(), tmp.end());
			clear_block(save_start, save_end, save_storage);
		}
		else
			ret = insert_values(position, tmp.begin(), tmp.end());			
		return (ret);
	}

	template <class T, class A>
	typename vector<T, A>::iterator	vector<T, A>::erase(typename vector<T, A>::iterator position)
	{
		return (remove_values(position, position + 1));
	}

    template <class T, class A>
	typename vector<T,A>::iterator	vector<T, A>::erase(typename vector<T, A>::iterator first,
											typename vector<T, A>::iterator last)
	{
		return (remove_values(first, last));
	}

    template <class T, class A>
	void	vector<T, A>::swap(vector<T, A>	&x)
	{
		vector<T, A>::allocator_type	tmp_alloc;
		vector<T, A>::pointer			tmp_start;
		vector<T, A>::pointer			tmp_end;
		vector<T, A>::pointer			tmp_storage_end;

		tmp_alloc = _alloc;
		tmp_start = _start;
		tmp_end = _end;
		tmp_storage_end = _storage_end;
		_alloc = x._alloc;
		_start = x._start;
		_end = x._end;
		_storage_end = x._storage_end;
		x._alloc = tmp_alloc;
		x._start = tmp_start;
		x._end = tmp_end;
		x._storage_end = tmp_storage_end;
	}

    template <class T, class A>
	void	vector<T, A>::clear()
	{
		clear_block(_start, _end, capacity());
		_start = NULL;
		_end = _start;
		_storage_end = _end;
	}


	//====		Allocator 			====
	
    template <class T, class A>
	typename vector<T, A>::allocator_type	vector<T, A>::get_allocator() const
	{
		return (_alloc);
	}


    //-------------		Private Function		-------------
	

    template <class T, class A>
	void	vector<T, A>::clear_block(const typename vector<T, A>::pointer start,
										const typename vector<T, A>::pointer end,
										const vector<T, A>::difference_type size)
	{
		vector<T, A>::iterator	it;
		vector<T, A>::iterator	ite;

		it = start;
		ite = end;
		if (size == 0)
			return;
		while (it != ite)
		{
			_alloc.destroy(&(*it));
			it++;
		}
		if (capacity() != 0)
			_alloc.deallocate(start, size);

	}

    template <class T, class A>
    void	vector<T, A>::allocate_memory(typename vector<T, A>::size_type size)
    {
		dprintf(1, "here4\n");
		_start = _alloc.allocate(size);
		dprintf(1, "here5\n");
		_storage_end = set_storage_end(_start, size);
		dprintf(1, "here6\n");
		_end = _start;
		dprintf(1, "here7\n");
    }

	template <class T, class A>
	template <class InputIterator>
	void	vector<T, A>::cpy_range(InputIterator start, InputIterator end)
	{
		while (start != end)
		{
        	_alloc.construct(_end, *start);
			_end++;
			start++;
		}
	}

	template <class T, class A>
    typename vector<T, A>::pointer  vector<T, A>::set_storage_end(const typename vector<T, A>::pointer &start,
                                                                            const size_t &size)
    {
        vector<T, A>::pointer     it;
        size_t      i;

        it = start;
        i = 0;
        while (i < size)
        {
            i++;
            it++;
        }
        return (it);
    }

    template <class T, class A>
	typename vector<T, A>::pointer	vector<T, A>::set_range(const vector<T, A>::pointer &start,
															const vector<T, A>::pointer &end,
															const vector<T, A>::value_type &val)
	{
		vector<T, A>::iterator	it;
		vector<T, A>::iterator	ite;

		it = start;
		ite = end;
		while (it != ite)
		{
			*it = val;
			it++;
		}
		return (&(*it));
	}

    template <class T, class A>
	typename vector<T, A>::iterator	vector<T, A>::alloc_insert_values(const vector<T, A>::iterator pos,
																		typename vector<T, A>::iterator new_start,
																		typename vector<T, A>::iterator new_end)
	{
		vector<T, A>::iterator	origin_start;
		vector<T, A>::iterator	origin_end;
		vector<T, A>::iterator	first_insert;
		size_t					size;

		origin_start = _start;
		origin_end = _end;
		size = ((new_end - new_start) + (origin_end - pos)) * 2;
		allocate_memory(size);
		while (origin_start != pos)
		{
			*_end = *origin_start;
			origin_start++;
			_end++;
		}
		first_insert = _end;
		while (new_start != new_end)
		{
			*_end = *new_start;
			new_start++;
			_end++;
		}
		while (origin_start != origin_end)
		{
			*_end = *origin_start;
			origin_start++;
			_end++;
		}
		return (first_insert);
	}

	template <class T, class A>
	typename vector<T, A>::iterator	vector<T, A>::insert_values(const vector<T, A>::iterator pos,
																typename vector<T, A>::iterator new_start,
																typename vector<T, A>::iterator new_end)
	{
		vector<T, A>::iterator	it;
		vector<T, A>::iterator	first_insert;
		size_t					shift;

		it = end();
		if (_end != _start)
			it = (end() - 1);
		shift = new_end - new_start;
		while (it != pos)
		{
			if (size() != 0)
				*(it + shift) = *it;
			it--;
		}
		*(it + shift) = *it;
		first_insert = it;
		while (new_start != new_end)
		{
			*it = *new_start;
			new_start++;
			it++;
		}
		_end = _end + shift;
		return (first_insert);
	}

	template <class T, class A>
	typename vector<T, A>::iterator	vector<T, A>::remove_values(typename vector<T, A>::iterator first,
																typename vector<T, A>::iterator last)
	{
		vector<T, A>::iterator	it;
		vector<T, A>::iterator	ite;
		vector<T, A>::iterator	first_shift;
		size_t					shift;

		it = begin();
		ite = end();
		shift = last - first;
		while (it != last)
			it++;
		first_shift = it - shift;
		while (it != ite)
		{
			*(it - shift) = *it;
			_alloc.destroy(&(*it));
			it++;
		}
		_end = _end - shift;
		return (first_shift); 
	}
};

#endif
