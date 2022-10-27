#ifndef VECTOR_TPP
# define VECTOR_TPP
# include "vector.hpp"

namespace ft
{

    template <class T, class A>
    vector<T, A>::vector(const typename vector<T, A>::allocator_type &alloc) :  _alloc(alloc), _start(NULL), _end(NULL), _storage_end(NULL)
    {
        _start = _alloc.allocate(10); //A CHANGER
        _end = _start;
        _storage_end = set_storage_end(_start, 10); //a remove
        //_storage_end = _start;
    }

    /*template <class T, class A>
    vector<T,A>::vector(typename vector<T, A>::size_type n,
                            const typename vector<T, A>::value_type &val,
                            const typename vector<T, A>::allocator_type &alloc)
    {

    }*/

    //Public Method

    template <class T, class A>
    typename vector<T, A>::size_type   vector<T, A>::size() const
    {
        return static_cast<size_type>(_end - _start);
    }

    template <class T, class A>
    typename vector<T, A>::size_type   vector<T, A>::capacity() const
    {
        return static_cast<size_type>(_storage_end - _start);
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
    typename vector<T, A>::pointer    vector<T, A>::allocate_memory(typename vector<T, A>::size_type size)
    {
        return (_alloc.allocate(size));
    }

    template <class T, class A>
    void        vector<T, A>::deallocate_memory(const typename vector<T, A>::pointer start,
                                                    const typename vector<T, A>::pointer end)
    {
		(void)end;
        vector<T, A>::iterator    it(start);
        
        /*while (it != end)
        {
            //_alloc.destroy(it);
            it++;
        }*/
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
    void    vector<T, A>::push_back(const typename vector<T, A>::value_type& val)
    {
        _alloc.construct(_end, val);
        _end++;
    }

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
    typename vector<T,A>::reverse_iterator  vector<T, A>::rend()
	{
		return (reverse_iterator(begin()));
	}

    template <class T, class A>
    typename vector<T,A>::reverse_iterator  vector<T, A>::rbegin()
	{
		return (reverse_iterator(end()));
	}

//template <class InputIterator>
//void assign(InputIterator first, InputIterator last);
};

#endif
