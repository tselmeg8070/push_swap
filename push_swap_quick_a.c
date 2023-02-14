/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quick_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadiyamu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:53:20 by tadiyamu          #+#    #+#             */
/*   Updated: 2023/01/22 14:57:35 by tadiyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	st_check_part(t_stack *st, int size, int piv)
{
	int	i;

	i = 0;
	while (i < size && st)
	{
		if (st->val < piv)
			return (1);
		st = st->tail;
		i++;
	}
	return (0);
}

int	st_quick_part_a(t_stack **a, t_stack **b, int size, t_stack **insts)
{
	int	piv;
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (size <= 0)
		return (0);
	piv = ft_median(*a, size);
	if (piv == 2147483647)
		return (0);
	while (i < size)
	{
		if ((*a)->val < piv)
			ft_push_b(a, b, insts);
		else if (st_check_part(*a, size - i, piv) && (*a)->val >= piv && ++len)
			ft_rotate_a(a, insts);
		i++;
	}
	return (len);
}

int	st_find_min_three(t_stack *a)
{
	int	d;
	int	i;
	int	max;

	i = 0;
	d = 2147483647;
	while (i < 3)
	{
		if (d > a->val)
		{
			d = a->val;
			max = i;
		}
		a = a->tail;
		i++;
	}
	return (max);
}

void	st_sort_three_a(t_stack **a, int size, t_stack **insts)
{
	int	max;

	if (size == 3 && !ft_check_stack(*a, size))
	{
		max = st_find_min_three(*a);
		if (max == 0)
			ft_rotate_a(a, insts);
		else if (max == 1)
		{
			ft_swap_a(a, insts);
			ft_rotate_a(a, insts);
		}
		else
		{
			if (size - 1 == 2 && !((*a)->val <= (*a)->tail->val))
				ft_swap_a(a, insts);
			ft_rotate_a(a, insts);
		}
		if (size - 1 == 2 && !((*a)->val <= (*a)->tail->val))
			ft_swap_a(a, insts);
		ft_rrotate_a(a, insts);
		size -= 1;
	}
	if (size == 2 && !((*a)->val <= (*a)->tail->val))
		ft_swap_a(a, insts);
}

void	st_quick_sort_a(t_stack **a, t_stack **b, int size, t_stack **insts)
{
	int	c_size;
	int	i;
	int	rot;

	if (size > 3)
	{
		i = 0;
		c_size = st_len(*b);
		rot = st_quick_part_a(a, b, size, insts);
		c_size = st_len(*b) - c_size;
		while (size - c_size != st_len(*a) && i++ < rot)
			ft_rrotate_a(a, insts);
		if (c_size > 0)
		{
			if (size - c_size > 3)
				st_quick_sort_a(a, b, size - c_size, insts);
			else
				st_sort_three_a(a, size - c_size, insts);
			if (c_size > 3)
				st_quick_sort_b(a, b, c_size, insts);
			else
				st_part_three_b(a, b, c_size, insts);
		}
	}
}
