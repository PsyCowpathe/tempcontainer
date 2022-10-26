#ifndef     RANDOM_ACCESS_ITERATOR_HPP
# define    RANDOM_ACCESS_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace   ft
{
    template <class T>
    class   random_access_iterator
    {
        public :
            typedef T                       value_type;
            typedef T                       *pointer;
            typedef T                       &reference;
            typedef ptrdiff_t               difference_type;
            typedef ft::iterator_traits<T>  iterator_category;

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

            pointer                 operator->() const;//
            reference               operator*() const;//
            random_access_iterator  &operator=(const random_access_iterator &copy);//
            random_access_iterator  &operator++();//
            random_access_iterator  operator++(int);//
            random_access_iterator  &operator--();//
            random_access_iterator  operator--(int);//
            random_access_iterator  operator+(difference_type n) const;//
            random_access_iterator  operator-(difference_type n) const;//
            difference_type         operator+(const random_access_iterator it);
            difference_type         operator-(const random_access_iterator it);
            random_access_iterator  &operator+= (difference_type n);//
            random_access_iterator  &operator-= (difference_type n);//
            reference               operator[](difference_type n) const;//

        private :
            pointer                         _it;

    };

};

#endif