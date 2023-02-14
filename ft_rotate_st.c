/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_st.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadiyamu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:52:26 by tadiyamu          #+#    #+#             */
/*   Updated: 2023/01/14 17:21:16 by tadiyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_rotate_helper(t_stack *stack)
{
	while (stack->tail)
		stack = stack->tail;
	return (stack);
}

void	ft_rotate_logic(t_stack **stack)
{
	t_stack	*top;
	t_stack	*tail;

	if (st_len(*stack) > 1)
	{
		top = st_pop(stack);
		tail = ft_rotate_helper(*stack);
		tail->tail = top;
		top->tail = 0;
	}
}

void	ft_rotate_a(t_stack **a, t_stack **insts)
{
	ft_rotate_logic(a);
	st_push(insts, st_create_node(30));
}

void	ft_rotate_b(t_stack **b, t_stack **insts)
{
	ft_rotate_logic(b);
	st_push(insts, st_create_node(31));
}

void	ft_rotate_rr(t_stack **a, t_stack **b, t_stack **insts)
{
	ft_rotate_logic(a);
	ft_rotate_logic(b);
	st_push(insts, st_create_node(32));
}
