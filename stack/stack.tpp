# include "stack.hpp"

template <class T, class Container>
ft::stack<T, Container>::stack(const container_type &cntr) : _ctnr(cntr)
{
     return ;
}

template <class T, class Container>
bool        ft::stack<T, Container>::empty() const
{
    return (_ctnr.empty());
}

template <class T, class Container>
typename ft::stack<T, Container>::size_type   ft::stack<T, Container>::size() const
{
    return (_ctnr.size());
}

template <class T, class Container>
typename ft::stack<T, Container>::value_type  &ft::stack<T, Container>::top()
{
    return (_ctnr.back());
}

template <class T, class Container>
const typename ft::stack<T, Container>::value_type  &ft::stack<T, Container>::top() const
{
    return (_ctnr.back());
}

template <class T, class Container>
void    ft::stack<T, Container>::push(const value_type &val)
{
    _ctnr.push_back(val);
}

template <class T, class Container>
void    ft::stack<T, Container>::pop()
{
    _ctnr.pop_back();
}