/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_ops_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadiyamu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:20:19 by tadiyamu          #+#    #+#             */
/*   Updated: 2023/01/25 20:16:02 by tadiyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	st_len(t_stack *stack)
{
	int	c;

	c = 0;
	while (stack)
	{
		stack = stack->tail;
		c++;
	}
	return (c);
}

t_stack	*st_pop(t_stack **stack)
{
	t_stack	*top;

	top = 0;
	if (stack && *stack)
	{
		top = *stack;
		*stack = (*stack)->tail;
	}
	return (top);
}

t_stack	*st_create_node(int val)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node)
	{
		node->val = val;
		node->tail = 0;
	}
	return (node);
}

void	st_push(t_stack **stack, t_stack *node)
{
	if (stack && node)
	{
		node->tail = *stack;
		*stack = node;
	}
}

void	st_clear(t_stack **stack)
{
	t_stack	*next;

	if (stack && *stack)
	{
		next = (*stack)->tail;
		free(*stack);
		*stack = next;
		st_clear(stack);
	}
}
