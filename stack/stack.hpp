#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <deque> //degage

namespace ft
{
    template <class T, class Container = std::deque<T> > //"deque" ça dégagera remplacer par container 
    class stack
    {
        public :

            typedef     T                                   value_type;
            typedef     Container                           container_type;
            typedef     typename container_type::size_type  size_type;

            explicit            stack(const container_type &ctnr = container_type());
            bool                empty() const;
            size_type           size() const;
            value_type          &top();
            const value_type    &top() const;
            void                push(const value_type &val);
            void                pop();

            template <class T1, class C1>
            friend bool operator==(const stack<T1,C1> &lhs, const stack<T1,C1> &rhs);

            template <class T1, class C1>
            friend bool operator!=(const stack<T1,C1> &lhs, const stack<T1,C1> &rhs);

            template <class T1, class C1>
            friend bool operator< (const stack<T1,C1> &lhs, const stack<T1,C1> &rhs);

            template <class T1, class C1>
            friend bool operator<=(const stack<T1,C1> &lhs, const stack<T1,C1> &rhs);

            template <class T1, class C1>
            friend bool operator> (const stack<T1,C1> &lhs, const stack<T1,C1> &rhs);

            template <class T1, class C1>
            friend bool operator>=(const stack<T1,C1> &lhs, const stack<T1,C1> &rhs);

        private :
            container_type  _ctnr;
    };

    template <class T1, class C1>
    bool operator==(const stack<T1, C1> &lhs, const stack<T1, C1> &rhs)
    {
        return (lhs._ctnr == rhs._ctnr);
    }

    template <class T1, class C1>
    bool operator!=(const stack<T1, C1> &lhs, const stack<T1, C1> &rhs)
    {
        return (lhs._ctnr != rhs._ctnr);
    }

    template <class T1, class C1>
    bool operator< (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs)
    {
        return (lhs._ctnr < rhs._ctnr);
    }

    template <class T1, class C1>
    bool operator<=(const stack<T1, C1> &lhs, const stack<T1, C1> &rhs)
    {
        return (lhs._ctnr <= rhs._ctnr);
    }

    template <class T1, class C1>
    bool operator> (const stack<T1, C1> &lhs, const stack<T1, C1> &rhs)
    {
        return (lhs._ctnr > rhs._ctnr);
    }

    template <class T1, class C1>
    bool operator>=(const stack<T1, C1> &lhs, const stack<T1, C1> &rhs)
    {
    return (lhs._ctnr >= rhs._ctnr);
    }

};

#endif