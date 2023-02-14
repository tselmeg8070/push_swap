/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quick_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadiyamu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:58:06 by tadiyamu          #+#    #+#             */
/*   Updated: 2023/01/22 15:01:38 by tadiyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	st_quick_part_b(t_stack **b, t_stack **a, int size, t_stack **insts)
{
	int	piv;
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (size <= 0)
		return (0);
	piv = ft_median(*b, size);
	if (piv == 2147483647)
		return (0);
	while (i < size)
	{
		if ((*b)->val >= piv)
			ft_push_a(b, a, insts);
		else if (st_check_part(*b, size - i, piv) && (*b)->val < piv && ++len)
			ft_rotate_b(b, insts);
		i++;
	}
	return (len);
}

int	st_find_max_three(t_stack *a)
{
	int	d;
	int	i;
	int	max;

	i = 0;
	d = -2147483648;
	while (i < 3)
	{
		if (d < a->val)
		{
			d = a->val;
			max = i;
		}
		a = a->tail;
		i++;
	}
	return (max);
}

void	st_part_small_b(t_stack **a, t_stack **b, int size, t_stack **insts)
{
	if (size == 1)
		ft_push_a(b, a, insts);
	if (size == 2)
	{
		if (!((*b)->val >= (*b)->tail->val))
			ft_swap_b(b, insts);
		ft_push_a(b, a, insts);
		ft_push_a(b, a, insts);
	}
}

void	st_part_three_b(t_stack **a, t_stack **b, int size, t_stack **insts)
{
	int	max;

	if (size == 3)
	{
		max = st_find_max_three(*b);
		if (max == 0)
			ft_push_a(b, a, insts);
		else if (max == 1)
		{
			ft_swap_b(b, insts);
			ft_push_a(b, a, insts);
		}
		else
		{
			ft_rotate_b(b, insts);
			ft_rotate_b(b, insts);
			ft_push_a(b, a, insts);
			ft_rrotate_b(b, insts);
			ft_rrotate_b(b, insts);
		}
		size -= 1;
	}
	st_part_small_b(a, b, size, insts);
}

void	st_quick_sort_b(t_stack **a, t_stack **b, int size, t_stack **insts)
{
	int	c_size;
	int	i;
	int	rot;

	if (size > 3)
	{
		i = 0;
		c_size = st_len(*a);
		rot = st_quick_part_b(b, a, size, insts);
		c_size = st_len(*a) - c_size;
		while (size - c_size != st_len(*b) && i++ < rot)
			ft_rrotate_b(b, insts);
		if (c_size > 0)
		{
			if (c_size > 3)
				st_quick_sort_a(a, b, c_size, insts);
			else
				st_sort_three_a(a, c_size, insts);
			if (size - c_size > 3)
				st_quick_sort_b(a, b, size - c_size, insts);
			else
				st_part_three_b(a, b, size - c_size, insts);
		}
	}
}
