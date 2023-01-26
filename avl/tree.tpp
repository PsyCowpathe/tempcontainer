/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:27:25 by agirona           #+#    #+#             */
/*   Updated: 2022/12/08 17:41:14 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_TPP
# define TREE_TPP

# include "tree.hpp"
# include <stdio.h>

namespace ft
{
	//====		Constructors && Destructor		====


	template <class T, class C, class A>
	tree<T, C, A>::tree()
	{
		_origin = NULL;
		_size = 0;
		_max = NULL;
		_real_end = new_node(ft::pair<key_type, value_type>());
	}

	template <class T, class C, class A>
	tree<T, C, A>::~tree()
	{
		clear_node(_real_end);
	}


	//====				Modifiers				====


	template <class T, class C, class A>
	ft::pair<typename tree<T, C, A>::iterator, bool>	tree<T, C, A>::insert(const pair_type &val)
	{
		node		*current;
		node		*prev;
		node		*new_one;
		int			direction;

		current = _origin;
		prev = NULL;
		direction = 0;
		while (current != NULL)
		{
			prev = current;
			if (_cmp(val.first, current->get_key()) && (direction = 1))
				current = current->_left;
			else if (_cmp(current->get_key(), val.first) && (direction = 2))
				current = current->_right;
			else
				return (ft::make_pair(iterator(current), false));
		}
		_size += 1;
		new_one = new_node(val); 
		new_one->set_parent(prev);
		if (direction == 1)
			prev->set_left(new_one);
		else if (direction == 2)
			prev->set_right(new_one);
		else
			_origin = new_one;
		is_new_max(new_one);
		update_height(new_one->_parent);
		balancing(new_one->_parent);
		return (ft::make_pair(iterator(new_one), true));
	}

	template <class T, class C, class A>
	void	tree<T, C, A>::erase(const key_type &val)
	{
		node		*current;
		node		*parent;
		int			direction;

		current = _origin;
		direction = 0;
		while (current != NULL)
		{
			if (_cmp(val, current->get_key()) && (direction = 1))
				current = current->_left;
			else if (_cmp(current->get_key(), val) && (direction = 2))
				current = current->_right;
			else
			{
				parent = current->_parent;
				is_del_max(val, parent);
				oblitarate(*current, direction);
				balancing(parent);
				return ;
			}
		}
	}

	template <class T, class C, class A>
	void	tree<T, C, A>::swap(tree<T, C, A> &x)
	{
		node			*tmp_origin;
		node			*tmp_real_end;
		node			*tmp_max;
		size_t			tmp_size;
		allocator_type	tmp_alloc;
		cmp_type		tmp_cmp;

		tmp_origin = x._origin;
		tmp_real_end = x._real_end;
		tmp_max = x._max;
		tmp_size = x._size;
		tmp_alloc = x._alloc;
		tmp_cmp = x._cmp;

		x._origin = _origin;
		x._real_end = _real_end;
		x._max = _max;
		x._size = _size;
		x._alloc = _alloc;
		x._cmp = _cmp;

		_origin = tmp_origin;
		_real_end = tmp_real_end;
		_max = tmp_max;
		_size = tmp_size;
		_alloc = tmp_alloc;
		_cmp = tmp_cmp;
	}


	//====				Operations				====


	template <class T, class C, class A>
	typename tree<T, C, A>::iterator	tree<T, C, A>::find(const key_type &val) const
	{	
		node		*current;

		current = _origin;
		while (current != NULL)
		{
			if (_cmp(val, current->get_key()))
				current = current->_left;
			else if (_cmp(current->get_key(), val))
				current = current->_right;
			else
				return (current);
		}
		return (_real_end);
	}


	//====				Iterators				====


	template <class T, class C, class A>
	typename tree<T, C, A>::iterator	tree<T, C, A>::begin() const
	{
		iterator	it(mini());

		return (it);
	}

	template <class T, class C, class A>
	typename tree<T, C, A>::iterator	tree<T, C, A>::end() const
	{
		return (_real_end);
	}



	//==========			Private functions			==========
	
	//====					Modifiers					====
	

	template <class T, class C, class A>
	void	tree<T, C, A>::single_oblitarate(node &to_delete)
	{
		node	*prev;
		node	*tmp;
		node	*substitute;
		int			direction;

		prev = to_delete._parent;
		tmp = &to_delete;
		substitute = to_delete._right;
		if (to_delete._left != NULL)
			substitute = to_delete._left;
		if (prev == NULL)
		{
			_origin = substitute;
			substitute->set_parent(NULL);
			clear_node(&to_delete);
			return ;
		}
		direction = 2;
		if (prev->_left->get_key() == to_delete.get_key())
			direction = 1;
		clear_node(tmp);
		if (direction == 1)
			prev->set_left(substitute);
		else
			prev->set_right(substitute);
		substitute->set_parent(prev);
	}

	template <class T, class C, class A>
	void	tree<T, C, A>::complex_oblitarate(node &to_replace)
	{
		node	*substitute;
		node	*to_delete;
		node	*prev;
		pair_type	save;

		to_delete = &to_replace;
		prev = to_replace._parent;
		to_delete = to_delete->_left;
		while (to_delete != NULL)
		{
			substitute = to_delete;
			to_delete = to_delete->_right;
		}
		save = *substitute->get_pair();
		erase(substitute->get_pair()->first);
		to_replace.set_pair(save);
	}

	template <class T, class C, class A>
	void	tree<T, C, A>::oblitarate(node &to_delete, const int &direction)
	{
		node	*prev;

		prev = to_delete._parent;
		if (to_delete._left == NULL && to_delete._right == NULL)
		{
			if (_size != 1)
				(direction == 1) ? prev->set_left(NULL) : prev->set_right(NULL);
			clear_node(&to_delete);

		}
		else if (to_delete._left != NULL && to_delete._right != NULL)
			complex_oblitarate(to_delete);
		else
			single_oblitarate(to_delete);
	}


	//====				Capacity				====


	template <class T, class C, class A>
	typename tree<T, C, A>::node	*tree<T, C, A>::new_node(const pair_type &val)
	{
		node		*new_one;

		new_one = _alloc.allocate(sizeof(node_ptr));
		_alloc.construct(new_one, val);
		if (_max != NULL)
			new_one->set_ptr_last(_max);
		return (new_one);
	}

	template <class T, class C, class A>
	void	tree<T, C, A>::clear_node(node *to_clear)
	{
		_size -= 1;
		if (_size == 0)
			_origin = NULL;
		_alloc.destroy(to_clear);
		_alloc.deallocate(to_clear, sizeof(node));
	}

	template <class T, class C, class A>
	void	tree<T, C, A>::clear()
	{
		iterator	it;
		iterator	ite;

		it = begin();
		ite = end();
		while (it != ite)
		{
			erase(*it);
			it++;
		}
	}

	template <class T, class C, class A>
	size_t	tree<T, C, A>::size() const
	{
		return (_size);
	}

	template <class T, class C, class A>
	size_t	tree<T, C, A>::max_size() const
	{
		return (_alloc.max_size());
	}
	

	//====				Rotators				====


	template <class T, class C, class A>
	void	tree<T, C, A>::LL_rotate(node *grandpa, node *parent)
	{
		node	*tie;

		tie = grandpa->_parent;
		grandpa->set_right(parent->_left);
		if (parent->_left != NULL)
			parent->_left->set_parent(grandpa);
		parent->set_left(grandpa);
		parent->set_parent(tie);
		grandpa->set_parent(parent);
		if (tie == NULL)
		{
			_origin = parent;
			update_height(grandpa);
			return ;
		}
		if (tie->_left == grandpa)
			tie->set_left(parent);
		else
			tie->set_right(parent);
		update_height(grandpa);
	}

	template <class T, class C, class A>
	void	tree<T, C, A>::RR_rotate(node *grandpa, node *parent)
	{
		node	*tie;

		tie = grandpa->_parent;
		grandpa->set_left(parent->_right);
		if (parent->_right != NULL)
			parent->_right->set_parent(grandpa);
		parent->set_right(grandpa);
		parent->set_parent(tie);
		grandpa->set_parent(parent);
		if (tie == NULL)
		{
			_origin = parent;
			update_height(grandpa);
			return ;
		}
		if (tie->_left == grandpa)
			tie->set_left(parent);
		else
			tie->set_right(parent);
		update_height(grandpa);
	}

	template <class T, class C, class A>
	void	tree<T, C, A>::LR_rotate(node *grandpa, node *parent, node *child)
	{
		node	*tie;
		node	*ltmp;
		node	*rtmp;

		tie = grandpa->_parent;
		ltmp = child->_left;
		rtmp = child->_right;
		child->set_left(parent);
		child->set_right(grandpa);
		parent->set_parent(child);
		parent->set_right(ltmp);
		if (ltmp)
			ltmp->set_parent(parent);
		grandpa->set_parent(child);
		grandpa->set_left(rtmp);
		if (rtmp)
			rtmp->set_parent(grandpa);
		if (tie == NULL)
		{
			_origin = child;
			child->set_parent(NULL);
			update_height(grandpa);
			solo_update_height(parent);
			return ;
		}
		if (tie->_left == grandpa)
			tie->set_left(child);
		else
			tie->set_right(child);
		child->set_parent(tie);
		update_height(grandpa);
		solo_update_height(parent);
	}

	template <class T, class C, class A>
	void	tree<T, C, A>::RL_rotate(node *grandpa, node *parent, node *child)
	{
		node	*tie;
		node	*ltmp;
		node	*rtmp;

		tie = grandpa->_parent;
		ltmp = child->_left;
		rtmp = child->_right;
		child->set_left(grandpa);
		child->set_right(parent);
		parent->set_parent(child);
		parent->set_left(rtmp);
		if (rtmp != NULL)
			rtmp->set_parent(parent);
		grandpa->set_parent(child);
		grandpa->set_right(ltmp);
		if (ltmp != NULL)
			ltmp->set_parent(grandpa);
		if (tie == NULL)
		{
			_origin = child;
			child->set_parent(NULL);
			update_height(grandpa);
			solo_update_height(parent);
			return ;
		}
		if (tie->_left == grandpa)
			tie->set_left(child);
		else
			tie->set_right(child);
		child->set_parent(tie);
		update_height(grandpa);
		solo_update_height(parent);
	}

	template <class T, class C, class A>
	void	tree<T, C, A>::choose_rotate(node *current, int factor)
	{
		int		left_height;
		int		right_height;

		left_height = 0;
		right_height = 0;
		if (factor <= -2)
		{
			if (current->_right->_left != NULL)
				RL_rotate(current, current->_right, current->_right->_left);
			else
				LL_rotate(current, current->_right);
		}
		else
		{
			if (current->_left->_right != NULL)
				LR_rotate(current, current->_left, current->_left->_right);
			else
				RR_rotate(current, current->_left);
		}
	}

	template <class T, class C, class A>
	void	tree<T, C, A>::balancing(node *current)
	{
		int			left_height;
		int			right_height;
		int			factor;

		while (current != NULL)
		{
			left_height = 0;
			right_height = 0;
			if (current->_left != NULL)
				left_height = 1 + current->_left->_height;
			if (current->_right != NULL)
				right_height = 1 + current->_right->_height;
			factor = left_height - right_height;
			if (factor <= -2 || factor >= 2)
				choose_rotate(current, factor);
			current = current->_parent;
		}
	}


	//====				Tools					====

	
	template <class T, class C, class A>
	typename tree<T, C, A>::node	*tree<T, C, A>::maxi() const
	{
		node	*current;

		current = _origin;
		while (current != NULL && current->_right != NULL)
			current = current->_right;
		return (current);
	}

	template <class T, class C, class A>
	typename tree<T, C, A>::node	*tree<T, C, A>::mini() const
	{
		node	*current;

		current = _origin;
		if (_size == 0)
			return (_real_end);
		while (current != NULL && current->_left != NULL)
			current = current->_left;
		return (current);
	}

	template <class T, class C, class A>
  	void tree<T, C, A>::change_max()
    {
		node_ptr tmp = mini();
		while (tmp != _max)
		{
			tmp->set_end(_real_end);
			tmp->set_ptr_last(_max);
			tmp = tmp->next();
		}
		_max->set_ptr_last(_max);
     }

	template <class T, class C, class A>
	void	tree<T, C, A>::is_new_max(node *last_add)
	{
		if (_max == NULL)
		{
			_max = last_add;
			last_add->set_end(_real_end);
			_real_end->set_parent(last_add);
			_real_end->set_print(0);
			last_add->set_ptr_last(_max);
		}
		else
		{
			if (_cmp(_max->get_pair()->first, last_add->get_pair()->first))
			{
				_max->set_end(NULL);
				_max = last_add;
				_max->set_end(_real_end);
				_real_end->set_parent(_max);
				last_add->_parent->set_ptr_last(NULL);
				_max->set_ptr_last(_max);
				//change_max();
			}
		}
	}
	
	template <class T, class C, class A>
	void	tree<T, C, A>::is_del_max(const key_type &val, node *to_delete)
	{
		if (_max == _origin)
		{
			_max->set_end(NULL);
			if (_size == 1)
			{
				_max = NULL;
				return ;
			}
			_max = _origin->_left;
			_max->set_end(_real_end);
			_real_end->set_parent(_max);
			_max->set_ptr_last(_max);
			//change_max();
		}
		if (to_delete == NULL)
			return ;
		if (_cmp(_max->get_pair()->first, val))
			return ;
		else if (_cmp(val, _max->get_pair()->first))
			return ;
		else
		{
			_max->set_end(NULL);
			if (_max->_left == NULL)
				_max = _max->_parent;
			else
				_max = _max->_left;
			_max->set_end(_real_end);
			_real_end->set_parent(_max);
			if (to_delete->_parent)
				to_delete->_parent->set_ptr_last(NULL);
			_max->set_ptr_last(_max);
		}
	}

	template <class T, class C, class A>
	inline void	tree<T, C, A>::update_height(node *current)
	{
		if (current == NULL)
			return;
		while (current != NULL)
		{
			if (current->_left != NULL && current->_right != NULL)
				current->_height = 1 + std::max(current->_left->_height, current->_right->_height);
			else if (current->_left)
				current->_height = 1 + current->_left->_height;
			else if (current->_right)
				current->_height = 1 + current->_right->_height;
			else
				current->_height = 0;
			current = current->_parent;
		}
	}

	template <class T, class C, class A>
	inline void	tree<T, C, A>::solo_update_height(node *current)
	{
		if (current == NULL)
			return;
		if (current->_left != NULL && current->_right != NULL)
				current->_height = 1 + std::max(current->_left->_height, current->_right->_height);
		else if (current->_left)
			current->_height = 1 + current->_left->_height;
		else if (current->_right)
			current->_height = 1 + current->_right->_height;
		else
			current->_height = 0;
	}



	//====			Relational Operators		====
	
	template <class T, class C, class A>
	bool	operator<(const tree<T, C, A> &lhs, const tree<T, C, A> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class T, class C, class A>
	bool	operator>(const tree<T, C, A> &lhs, const tree<T, C, A> &rhs)
	{
		return (lhs < rhs);
	}

	template <class T, class C, class A>
	bool	operator==(const tree<T, C, A> &lhs, const tree<T, C, A> &rhs)
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}	
};

#endif
