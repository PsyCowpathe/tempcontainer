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
	template <class T, class A, class C>
	tree<T, A, C>::tree()
	{
		_origin = NULL;
		_size = 0;
		_max = NULL;
	}

	template <class T, class A, class C>
	tree<T, A, C>::~tree()
	{

	}

	template <class T, class A, class C>
	void	tree<T, A, C>::insert(const pair_type &val)
	{
		elem<T>		*current;
		elem<T>		*prev;
		elem<T>		*new_one;
		int			direction;

		current = _origin;
		prev = NULL;
		direction = 0;
		while (current != NULL)
		{
			prev = current;
			if (cmp(val.first, current->get_key()) && (direction = 1))
				current = current->get_left();
			else if (cmp(current->get_key(), val.first) && (direction = 2))
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
		is_new_max(val, new_one);
		balancing(new_one->get_parent());
	}


	template <class T, class A,class C>
	void	tree<T, A, C>::erase(const pair_type &val)
	{
		elem<T>		*current;
		elem<T>		*parent;
		int			direction;

		current = _origin;
		direction = 0;
		while (current != NULL)
		{
			if (cmp(val.first, current->get_key()) && (direction = 1))
				current = current->get_left();
			else if (cmp(current->get_key(), val.first) && (direction = 2))
				current = current->get_right();
			else
			{
				parent = current->get_parent();
				is_del_max(val, parent);
				current = oblitarate(*current, direction);
				balancing(parent);
			}
		}
	}

	template <class T, class A, class C>
	typename tree<T, A, C>::node	*tree<T, A, C>::get_origin()
	{
		return (_origin);
	}

	template <class T, class A, class C>
	typename tree<T, A, C>::iterator	tree<T, A, C>::begin()
	{
		iterator	it(mini());

		return (it);
	}

	template <class T, class A, class C>
	typename tree<T, A, C>::iterator	tree<T, A, C>::end()
	{
		/*iterator	it(maxi());*/

		return (_real_end);
	}

	//private

	template <class T, class A,class C>
	void	tree<T, A, C>::is_new_max(const pair_type &val, node *last_add)
	{
		elem<T>		*tmp;

		if (_max == NULL)
		{
			tmp = new_node(val); 
			_max = last_add;
			last_add->set_end(tmp);
			tmp->set_parent(last_add);
			_real_end = tmp;
			_real_end->set_print(0);
		}
		else
		{
			if (cmp(_max->get_pair()->first, last_add->get_pair()->first))
			{
				_max->set_end(NULL);
				_max = last_add;
				_max->set_end(_real_end);
				_real_end->set_parent(_max);
			}
		}
		/*std::cout << "max = " << _max->get_pair()->first << std::endl;
		std::cout << "real = " << _real_end->get_parent()->get_pair()->first << std::endl << std::endl;*/
	}

	template <class T, class A,class C>
	void	tree<T, A, C>::is_del_max(const pair_type &val, node *to_delete)
	{
		if (to_delete == NULL)
			return ;
		if (cmp(_max->get_pair()->first, val.first))
			return ;
		else if (cmp(val.first, _max->get_pair()->first))
			return ;
		else
		{
			_max->set_end(NULL);
			_max = _max->get_parent();
			_max->set_end(_real_end);
			_real_end->set_parent(_max);
		}
	}

	template <class T, class A, class C>
	typename tree<T, A, C>::node	*tree<T, A, C>::mini() const
	{
		node	*current;

		current = _origin;
		while (current != NULL && current->get_left() != NULL)
			current = current->get_left();
		return (current);
	}

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
	void	tree<T, A, C>::balancing(elem<T> *current)
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

	template <class T, class A, class C>
	void	tree<T, A, C>::RR_rotate(elem<T> *grandpa, elem<T> *parent)
	{
		elem<T>	*tie;

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
	void	tree<T, A, C>::LL_rotate(elem<T> *grandpa, elem<T> *parent)
	{
		elem<T>	*tie;

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
	void	tree<T, A, C>::LR_rotate(elem<T> *grandpa, elem<T> *parent, elem<T> *child)
	{
		elem<T>	*tie;
		elem<T>	*ltmp;
		elem<T>	*rtmp;

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
	void	tree<T, A, C>::RL_rotate(elem<T> *grandpa, elem<T> *parent, elem<T> *child)
	{
		elem<T>	*tie;
		elem<T>	*ltmp;
		elem<T>	*rtmp;

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
	void	tree<T, A, C>::choose_rotate(elem<T> *current, int factor)
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
	int		tree<T, A, C>::get_sub_height(elem<T> *current)
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

	template <class T, class A, class C>
	void	tree<T, A, C>::single_oblitarate(elem<T> &to_delete)
	{
		elem<T>	*prev;
		elem<T>	*tmp;
		elem<T>	*substitute;
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
	void	tree<T, A, C>::complex_oblitarate(elem<T> &to_replace)
	{
		elem<T>	*substitute;
		elem<T>	*to_delete;
		elem<T>	*prev;
		pair_type	save;

		to_delete = &to_replace;
		prev = to_replace.get_parent();
		to_delete = to_delete->get_right();
		while (to_delete != NULL)
		{
			substitute = to_delete;
			to_delete = to_delete->get_left();
		}
		save = *substitute->get_pair();
		erase(*substitute->get_pair());
		to_replace.set_pair(save);
	}

	template <class T, class A, class C>
	elem<T>	*tree<T, A, C>::oblitarate(elem<T> &to_delete, const int &direction)
	{
		elem<T>	*prev;

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
		return (NULL);
	}

	template <class T, class A,class C>
	typename tree<T, A, C>::node	*tree<T, A, C>::new_node(const pair_type &val)
	{
		elem<T>		*new_one;

		new_one = _alloc.allocate(sizeof(node_ptr));
		_alloc.construct(new_one, val);
		return (new_one);
	}

	template <class T, class A,class C>
	void	tree<T, A, C>::clear_node(elem<T> *to_clear)
	{
		_size -= 1;
		if (_size == 0)
			_origin = NULL;
		_alloc.destroy(to_clear);
		_alloc.deallocate(to_clear, sizeof(elem<T>));
	}
	

};

#endif
