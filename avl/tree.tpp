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


	template <class T, class A, class C>
	tree<T, A, C>::tree()
	{
		_origin = NULL;
		_size = 0;
		_max = NULL;
		_real_end = new_node(ft::pair<key_type, value_type>());
	}

	template <class T, class A, class C>
	tree<T, A, C>::~tree()
	{

	}


	//====				Modifiers				====


	template <class T, class A, class C>
	void	tree<T, A, C>::insert(const pair_type &val)
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
				current = current->get_left();
			else if (_cmp(current->get_key(), val.first) && (direction = 2))
				current = current->get_right();
			else
				return ;
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
		balancing(new_one->get_parent());
	}

	template <class T, class A, class C>
	void	tree<T, A, C>::erase(const key_type &val)
	{
		node		*current;
		node		*parent;
		int			direction;

		current = _origin;
		direction = 0;
		while (current != NULL)
		{
			if (_cmp(val, current->get_key()) && (direction = 1))
				current = current->get_left();
			else if (_cmp(current->get_key(), val) && (direction = 2))
				current = current->get_right();
			else
			{
				parent = current->get_parent();
				is_del_max(val, parent);
				oblitarate(*current, direction);
				balancing(parent);
				return ;
			}
		}
	}

	template <class T, class A, class C>
	void	tree<T, A, C>::swap(tree<T, A, C> &x)
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


	template <class T, class A, class C>
	typename tree<T, A, C>::iterator	tree<T, A, C>::find(const key_type &val) const
	{	
		node		*current;

		current = _origin;
		while (current != NULL)
		{
			if (_cmp(val, current->get_key()))
				current = current->get_left();
			else if (_cmp(current->get_key(), val))
				current = current->get_right();
			else
				return (current);
		}
		return (_real_end);
	}


	//====				Iterators				====


	template <class T, class A, class C>
	typename tree<T, A, C>::iterator	tree<T, A, C>::begin() const
	{
		iterator	it(mini());

		return (it);
	}

	template <class T, class A, class C>
	typename tree<T, A, C>::iterator	tree<T, A, C>::end() const
	{
		return (_real_end);
	}



	//==========			Private functions			==========
	
	//====					Modifiers					====
	

	template <class T, class A, class C>
	void	tree<T, A, C>::single_oblitarate(node &to_delete)
	{
		node	*prev;
		node	*tmp;
		node	*substitute;
		int			direction;

		prev = to_delete.get_parent();
		tmp = &to_delete;
		substitute = to_delete.get_right();
		if (to_delete.get_left() != NULL)
			substitute = to_delete.get_left();
		if (prev == NULL)
		{
			_origin = substitute;
			substitute->set_parent(NULL);
			clear_node(&to_delete);
			return ;
		}
		direction = 2;
		if (prev->get_left()->get_key() == to_delete.get_key())
			direction = 1;
		clear_node(tmp);
		if (direction == 1)
			prev->set_left(substitute);
		else
			prev->set_right(substitute);
		substitute->set_parent(prev);
	}

	template <class T, class A, class C>
	void	tree<T, A, C>::complex_oblitarate(node &to_replace)
	{
		node	*substitute;
		node	*to_delete;
		node	*prev;
		pair_type	save;

		to_delete = &to_replace;
		prev = to_replace.get_parent();
		to_delete = to_delete->get_left();
		while (to_delete != NULL)
		{
			substitute = to_delete;
			to_delete = to_delete->get_right();
		}
		save = *substitute->get_pair();
		erase(substitute->get_pair()->first);
		to_replace.set_pair(save);
	}

	template <class T, class A, class C>
	void	tree<T, A, C>::oblitarate(node &to_delete, const int &direction)
	{
		node	*prev;

		prev = to_delete.get_parent();
		if (to_delete.get_left() == NULL && to_delete.get_right() == NULL)
		{
			if (_size != 1)
				(direction == 1) ? prev->set_left(NULL) : prev->set_right(NULL);
			clear_node(&to_delete);

		}
		else if (to_delete.get_left() != NULL && to_delete.get_right() != NULL)
			complex_oblitarate(to_delete);
		else
			single_oblitarate(to_delete);
	}


	//====				Capacity				====


	template <class T, class A, class C>
	typename tree<T, A, C>::node	*tree<T, A, C>::new_node(const pair_type &val)
	{
		node		*new_one;

		new_one = _alloc.allocate(sizeof(node_ptr));
		_alloc.construct(new_one, val);
		if (_max != NULL)
			new_one->set_ptr_last(_max);
		return (new_one);
	}

	template <class T, class A, class C>
	void	tree<T, A, C>::clear_node(node *to_clear)
	{
		_size -= 1;
		if (_size == 0)
			_origin = NULL;
		_alloc.destroy(to_clear);
		_alloc.deallocate(to_clear, sizeof(node));
	}

	template <class T, class A, class C>
	void	tree<T, A, C>::clear()
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

	template <class T, class A, class C>
	size_t	tree<T, A, C>::size() const
	{
		return (_size);
	}

	template <class T, class A, class C>
	size_t	tree<T, A, C>::max_size() const
	{
		return (_alloc.max_size());
	}
	

	//====				Rotators				====


	template <class T, class A, class C>
	void	tree<T, A, C>::LL_rotate(node *grandpa, node *parent)
	{
		node	*tie;

		tie = grandpa->get_parent();
		grandpa->set_right(parent->get_left());
		if (parent->get_left() != NULL)
			parent->get_left()->set_parent(grandpa);
		parent->set_left(grandpa);
		parent->set_parent(tie);
		grandpa->set_parent(parent);
		if (tie == NULL)
		{
			_origin = parent;
			return ;
		}
		if (tie->get_left() == grandpa)
			tie->set_left(parent);
		else
			tie->set_right(parent);
	}

	template <class T, class A, class C>
	void	tree<T, A, C>::RR_rotate(node *grandpa, node *parent)
	{
		node	*tie;

		tie = grandpa->get_parent();
		grandpa->set_left(parent->get_right());
		if (parent->get_right() != NULL)
			parent->get_right()->set_parent(grandpa);
		parent->set_right(grandpa);
		parent->set_parent(tie);
		grandpa->set_parent(parent);
		if (tie == NULL)
		{
			_origin = parent;
			return ;
		}
		if (tie->get_left() == grandpa)
			tie->set_left(parent);
		else
			tie->set_right(parent);
	}

	template <class T, class A, class C>
	void	tree<T, A, C>::LR_rotate(node *grandpa, node *parent, node *child)
	{
		node	*tie;
		node	*ltmp;
		node	*rtmp;

		tie = grandpa->get_parent();
		ltmp = child->get_left();
		rtmp = child->get_right();
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
			return ;
		}
		if (tie->get_left() == grandpa)
			tie->set_left(child);
		else
			tie->set_right(child);
		child->set_parent(tie);
	}

	template <class T, class A, class C>
	void	tree<T, A, C>::RL_rotate(node *grandpa, node *parent, node *child)
	{
		node	*tie;
		node	*ltmp;
		node	*rtmp;

		tie = grandpa->get_parent();
		ltmp = child->get_left();
		rtmp = child->get_right();
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
			return ;
		}
		if (tie->get_left() == grandpa)
			tie->set_left(child);
		else
			tie->set_right(child);
		child->set_parent(tie);
	}

	template <class T, class A, class C>
	void	tree<T, A, C>::choose_rotate(node *current, int factor)
	{
		int		left_height;
		int		right_height;

		left_height = 0;
		right_height = 0;
		if (factor > 1)
		{
			if (current->get_left()->get_left() != NULL)
				left_height = 1 + get_sub_height(current->get_left()->get_left());
			if (current->get_left()->get_right() != NULL)
				right_height = 1 + get_sub_height(current->get_left()->get_right());
			factor = left_height - right_height;
			if (factor > 0)
				RR_rotate(current, current->get_left());
			else
				LR_rotate(current, current->get_left(), current->get_left()->get_right());
		}
		else
		{
			if (current->get_right()->get_left() != NULL)
				left_height = 1 + get_sub_height(current->get_right()->get_left());
			if (current->get_right()->get_right() != NULL)
				right_height = 1 + get_sub_height(current->get_right()->get_right());
			factor = left_height - right_height;
			if (factor > 0)
				RL_rotate(current, current->get_right(), current->get_right()->get_left());
			else
				LL_rotate(current, current->get_right());
		}
	}

	template <class T, class A, class C>
	void	tree<T, A, C>::balancing(node *current)
	{
		int			left_height;
		int			right_height;
		int			factor;

		while (current != NULL)
		{
			left_height = 0;
			right_height = 0;
			if (current->get_left() != NULL)
				left_height = 1 + get_sub_height(current->get_left());
			if (current->get_right() != NULL)
				right_height = 1 + get_sub_height(current->get_right());
			factor = left_height - right_height;
			if (factor > 1 || factor < -1)
				choose_rotate(current, factor);
			current = current->get_parent();
		}
	}

	//====				Tools					====

	
	template <class T, class A, class C>
	typename tree<T, A, C>::node	*tree<T, A, C>::maxi() const
	{
		node	*current;

		current = _origin;
		while (current != NULL && current->get_right() != NULL)
			current = current->get_right();
		return (current);
	}

	template <class T, class A, class C>
	typename tree<T, A, C>::node	*tree<T, A, C>::mini() const
	{
		node	*current;

		current = _origin;
		if (_size == 0)
			return (_real_end);
		while (current != NULL && current->get_left() != NULL)
			current = current->get_left();
		return (current);
	}

	template <class T, class A, class C>
  	void tree<T, A, C>::change_max()
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

	template <class T, class A,class C>
	void	tree<T, A, C>::is_new_max(node *last_add)
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
				change_max();
			}
		}
	}
	
	template <class T, class A,class C>
	void	tree<T, A, C>::is_del_max(const key_type &val, node *to_delete)
	{
		if (_max == _origin)
		{
			_max->set_end(NULL);
			if (_size == 1)
			{
				_max = NULL;
				return ;
			}
			_max = _origin->get_left();
			_max->set_end(_real_end);
			_real_end->set_parent(_max);
			change_max();
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
			_max = _max->get_parent();
			_max->set_end(_real_end);
			_real_end->set_parent(_max);
			change_max();
		}
	}

	template <class T, class A, class C>
	int		tree<T, A, C>::get_sub_height(node *current)
	{
		int		left_height;
		int		right_height;

		left_height = 0;
		right_height = 0;
		if (current == NULL)
			return (0);
		if (current->get_right() != NULL)
			++right_height += get_sub_height(current->get_right());
		if (current->get_left() != NULL)
			++left_height += get_sub_height(current->get_left());
		if (left_height > right_height)
			return (left_height);
		return (right_height);
	}
};

#endif
