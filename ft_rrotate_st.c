/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate_st.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadiyamu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:53:16 by tadiyamu          #+#    #+#             */
/*   Updated: 2023/01/14 17:23:14 by tadiyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_rrotate_helper(t_stack *stack)
{
	while (stack->tail->tail)
		stack = stack->tail;
	return (stack);
}

void	ft_rrotate_logic(t_stack **stack)
{
	t_stack	*last;
	t_stack	*blast;

	if (st_len(*stack) > 1)
	{
		blast = ft_rrotate_helper(*stack);
		last = blast->tail;
		blast->tail = 0;
		st_push(stack, last);
	}
}

void	ft_rrotate_a(t_stack **a, t_stack **insts)
{
	ft_rrotate_logic(a);
	st_push(insts, st_create_node(40));
}

void	ft_rrotate_b(t_stack **b, t_stack **insts)
{
	ft_rrotate_logic(b);
	st_push(insts, st_create_node(41));
}

void	ft_rrotate_rrr(t_stack **a, t_stack **b, t_stack **insts)
{
	ft_rrotate_logic(a);
	ft_rrotate_logic(b);
	st_push(insts, st_create_node(42));
}
