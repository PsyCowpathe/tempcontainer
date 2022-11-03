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
	//Constructors
	
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
		_end = set_range(_start, _storage_end, val);
    }

	/*template <class T, class A>
	template <class InputIterator>
	vector<T,A>::vector(InputIterator first, InputIterator last,
						const vector<T, A>::allocator_type &alloc) : _alloc(alloc)
	{
		_end = cpy_range(first, last);
	}*/

	template <class T, class A>
	vector<T, A>::vector(const vector<T, A> &x) : _alloc(x._alloc)
	{
		*this = x;
	}

	//Private Function
	
    template <class T, class A>
    void	vector<T, A>::allocate_memory(typename vector<T, A>::size_type size)
    {
		_start = _alloc.allocate(size);
		_storage_end = set_storage_end(_start, size);
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
    typename vector<T, A>::pointer  vector<T, A>::set_storage_end(const typename vector<T, A>::pointer start,
                                                                            const size_t size)
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
	void	vector<T, A>::insert_values(const vector<T, A>::iterator pos, typename vector<T, A>::iterator start,
											typename vector<T, A>::iterator end)
	{
		vector<T, A>::iterator	save_start;
		vector<T, A>::iterator	save_end;
		size_t					size;

		save_start = _start;
		save_end = _end;
		size = capacity() + (end - start);
		allocate_memory(size);
		_end = _start;
		while (save_start != pos)
		{
			*_end = *save_start;
			save_start++;
			_end++;
		}
		while (start != end)
		{
			*_end = *start;
			start++;
			_end++;
		}
		while (save_start != save_end)
		{
			*_end = *save_start;
			save_start++;
			_end++;
		}
	}

    //Public Method

    template <class T, class A>
    typename vector<T,A>::iterator  vector<T, A>::begin()
    {
        return (_start);
    }

    template <class T, class A>
    typename vector<T,A>::iterator  vector<T, A>::end()
    {
        return (_end);
    }

    template <class T, class A>
    void    vector<T, A>::push_back(const typename vector<T, A>::value_type &val)
    {
		vector<T, A>::pointer	save_start;
		vector<T, A>::pointer	save_end;

		if (capacity() == 0)
		{
			allocate_memory(capacity() + 1);
			_end = _start;
			push_back(val);
		}
		else if (_end == _storage_end)
		{
			save_start = _start;
			save_end = _end;
			allocate_memory(capacity() + 1);
			_end = _start;
			cpy_range(save_start, save_end);
			push_back(val);
		}
		else
		{
        	_alloc.construct(_end, val);
        	_end++;
		}
    }

	template <class T, class A>
	template <class InputIterator>
	void 	vector<T, A>::insert(typename vector<T, A>::iterator position, InputIterator first, InputIterator last)
	{
		insert_values(position, first, last);
	}

    template <class T, class A>
	void	vector<T, A>::insert(typename vector<T, A>::iterator position, typename vector<T, A>::size_type n,
									const typename vector<T, A>::value_type &val)
	{
		vector<T, A>						tmp;
		typename vector<T,A>::size_type		count;

		count = 0;
		if (capacity() == 0) // avoir flemme ce soir
		{
			allocate_memory(capacity() + n);
			_end = _start;
			while (count < n)
			{
				push_back(val);
				count++;
			}
		}
		else
		{
			while (count < n)
			{
				tmp.push_back(val);
				count++;
			}
			insert_values(position, tmp.begin(), tmp.end());
		}
	}

    template <class T, class A>
	typename vector<T, A>::iterator		vector<T, A>::insert(typename vector<T, A>::iterator position,
																const typename vector<T, A>::value_type &val)
	{
		vector<T, A>	tmp;

		if (capacity() == 0) //a voir flemme ce soir
		{
			allocate_memory(capacity() + 1);
			_end = _start;
			push_back(val);
		}
		else
		{
			tmp.push_back(val);
			insert_values(position, tmp.begin(), tmp.end());
		}
		// (_end != _storage_end && position == end()))
		return (_end);
	}

    template <class T, class A>
    typename vector<T, A>::size_type	vector<T, A>::capacity() const
    {
        return static_cast<size_type>(_storage_end - _start);
    }

    /*template <class T, class A>
    typename vector<T, A>::size_type   vector<T, A>::size() const
    {
        return static_cast<size_type>(_end - _start);
    }


    template <class T, class A>
    void    vector<T, A>::assign(vector<T, A>::size_type n,
                                        const vector<T, A>::value_type &val)
    {
		(void)val;
        if (n == 0)
            return ;
        if (n > capacity())
        {
            std::cout << "manque de capacité" << std::endl; //delete
            deallocate_memory(_start, _end);
            _start = allocate_memory(n * 2);
            //_end = set_range(_start, n, val);
            _storage_end = set_storage_end(_start, n * 2);
        }
        else
        {
            std::cout << "bonne capacité, j'assigne !" << std::endl; //delete
            //_end = set_range(0, n, val);
        }
    }

    //Private Method

    
    template <class T, class A>
    void        vector<T, A>::deallocate_memory(const typename vector<T, A>::pointer start,
                                                    const typename vector<T, A>::pointer end)
    {
		(void)end;
        vector<T, A>::iterator    it(start);
        
       // while (it != end)
       // {
            //_alloc.destroy(it);
        //    it++;
       // }
        _alloc.deallocate(start, size());
    }

    template <class T, class A>
    typename vector<T, A>::iterator     vector<T, A>::set_range(const typename vector<T, A>::iterator start,
                                                                        const typename vector<T, A>::value_type &val,
                                                                        size_t end)
    {
        int         i;
        vector<T, A>::iterator    it;

        i = 0;
        it = start;
        while (i < end)
        {
            *it = val;
            i++;
            it++;
        }
        return (it);
    }


    template <class T, class A>
    typename vector<T,A>::reverse_iterator  vector<T, A>::rend()
	{
		return (reverse_iterator(begin()));
	}

    template <class T, class A>
    typename vector<T,A>::reverse_iterator  vector<T, A>::rbegin()
	{
		return (reverse_iterator(end()));
	}*/

};

#endif
