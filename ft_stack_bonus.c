/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadiyamu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:20:19 by tadiyamu          #+#    #+#             */
/*   Updated: 2023/01/25 20:42:29 by tadiyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	ft_push_logic(t_stack **s, t_stack **d)
{
	t_stack	*top;

	top = st_pop(s);
	if (top)
		st_push(d, top);
}

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
