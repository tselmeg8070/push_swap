/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadiyamu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:49:31 by tadiyamu          #+#    #+#             */
/*   Updated: 2023/01/14 17:33:06 by tadiyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_logic(t_stack **stack)
{
	t_stack	*top;

	if (st_len(*stack) > 1)
	{
		top = st_pop(stack);
		top->tail = (*stack)->tail;
		(*stack)->tail = top;
	}
}

void	ft_swap_a(t_stack **stack, t_stack **insts)
{
	ft_swap_logic(stack);
	st_push(insts, st_create_node(10));
}

void	ft_swap_b(t_stack **stack, t_stack **insts)
{
	ft_swap_logic(stack);
	st_push(insts, st_create_node(11));
}

void	ft_swap_ss(t_stack **a, t_stack **b, t_stack **insts)
{
	ft_swap_logic(a);
	ft_swap_logic(b);
	st_push(insts, st_create_node(12));
}
