#ifndef REVERSE_ITERATOR_TPP
# define REVERSE_ITERATOR_TPP
# include "reverse_iterator.hpp"

namespace ft
{

template <class I>
reverse_iterator<I>::reverse_iterator() : _current()
{

}

template <class I>
reverse_iterator<I>::reverse_iterator(iterator_type it) : _current(it)
{

}

template <class I> // pas sur
reverse_iterator<I>::reverse_iterator(const reverse_iterator<I> &rev_it) :
                                            _current(rev_it._current)
{

}

template <class I>
typename reverse_iterator<I>::iterator_type       reverse_iterator<I>::base() const
{
    return (_current);
}

template <class Iterator>
typename reverse_iterator<Iterator>::reference           reverse_iterator<Iterator>::operator*() const
{
    Iterator    tmp;

    tmp = _current;
    return (*--tmp);
}

template <class I>
reverse_iterator<I>    reverse_iterator<I>::operator+(difference_type n) const
{
    return (reverse_iterator(_current - n));
}

template <class I>
reverse_iterator<I>    &reverse_iterator<I>::operator++()
{
    --_current; 
    return (*this);
}

template <class I>
reverse_iterator<I>    reverse_iterator<I>::operator++(int)
{
    reverse_iterator    tmp = *this;
    --_current; 
    return (tmp);
}

template <class I>
reverse_iterator<I>    &reverse_iterator<I>::operator+=(difference_type n)
{
    _current -= n;
    return (*this);
}

template <class I>
reverse_iterator<I>    reverse_iterator<I>::operator-(difference_type n) const
{
    return (reverse_iterator(_current + n));
}

template <class I>
reverse_iterator<I>    &reverse_iterator<I>::operator--()
{
    ++_current;
    return (*this);
}

template <class I>
reverse_iterator<I>    reverse_iterator<I>::operator--(int)
{
    reverse_iterator    tmp = *this;
    ++_current;
    return (tmp);
}

template <class I>
reverse_iterator<I>   &reverse_iterator<I>::operator-=(difference_type n)
{
    _current += n;
    return (*this);
}

template <class I>
typename reverse_iterator<I>::pointer             reverse_iterator<I>::operator->() const
{
    return (&(operator*()));
}

template <class I>
typename reverse_iterator<I>::reference           reverse_iterator<I>::operator[](difference_type n) const
{
    return (*(*this + n));
}

template <class I>
bool                operator!=(const reverse_iterator<I> &lhs, const reverse_iterator<I> &rhs)
{
    return (lhs.base() != rhs.base());
}

template <class I>
bool                operator<(const reverse_iterator<I> &lhs, const reverse_iterator<I> &rhs)
{
    return (lhs.base() > rhs.base());
}

template <class I>
bool                operator<=(const reverse_iterator<I> &lhs, const reverse_iterator<I> &rhs)
{
    return (lhs.base() >= rhs.base());
}

template <class I>
bool                operator==(const reverse_iterator<I> &lhs, const reverse_iterator<I> &rhs)
{
    return (lhs.base() == rhs.base());
}

template <class I>
bool                operator>(const reverse_iterator<I> &lhs, const reverse_iterator<I> &rhs)
{
    return (lhs.base() < rhs.base());
}

template <class I>
bool                operator>=(const reverse_iterator<I> &lhs, const reverse_iterator<I> &rhs)
{
    return (lhs.base() <= rhs.base());
}

template <class I>
reverse_iterator<I>    operator+(typename reverse_iterator<I>::difference_type n,
                                                        const reverse_iterator<I> &rev_it)
{
    return (reverse_iterator<I>(rev_it.base() - n));
}

template <class I>
typename reverse_iterator<I>::difference_type    operator-(const reverse_iterator<I> &lhs,
                                                                    const reverse_iterator<I> &rhs)
{
    return (rhs.base() - lhs.base());
}

};

#endif