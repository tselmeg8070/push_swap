/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadiyamu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:59:31 by tadiyamu          #+#    #+#             */
/*   Updated: 2023/01/22 19:59:32 by tadiyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ins_rem(t_stack **stack, t_stack **list, t_stack **res)
{
	while (*list)
	{
		ft_rrotate_logic(list);
		st_push(res, st_pop(list));
	}
	while (*stack)
	{
		ft_rrotate_logic(stack);
		st_push(res, st_pop(stack));
	}
}

void	ft_coll(t_stack **stack, t_stack **list, t_stack **res, t_stack *node)
{
	t_stack	*temp;

	if ((*stack) && (*stack)->val / 10 == node->val / 10)
	{
		if ((*stack)->val == node->val)
			st_push(stack, node);
		else
		{
			temp = st_create_node((*stack)->val + 2 - (*stack)->val % 10);
			st_push(list, temp);
			free(node);
			free(st_pop(stack));
		}
	}
	else
	{
		ft_ins_rem(stack, list, res);
		st_push(stack, node);
	}
}

void	ft_instruction_add(t_stack **insts)
{
	t_stack	*list;
	t_stack	*stack;
	t_stack	*node;
	t_stack	*res;

	list = 0;
	stack = 0;
	res = 0;
	while ((*insts))
	{
		node = st_pop(insts);
		if (node->val >= 20 && node->val < 30)
		{
			ft_ins_rem(&stack, &list, &res);
			st_push(&res, node);
		}
		else
			ft_coll(&stack, &list, &res, node);
	}
	ft_ins_rem(&stack, &list, &res);
	*insts = res;
}

void	ft_print_instruction(t_stack *node)
{
	if (node->val == 10)
		write(1, "sa\n", 3);
	if (node->val == 11)
		write(1, "sb\n", 3);
	if (node->val == 12)
		write(1, "ss\n", 3);
	if (node->val == 20)
		write(1, "pa\n", 3);
	if (node->val == 21)
		write(1, "pb\n", 3);
	if (node->val == 30)
		write(1, "ra\n", 3);
	if (node->val == 31)
		write(1, "rb\n", 3);
	if (node->val == 32)
		write(1, "rr\n", 3);
	if (node->val == 40)
		write(1, "rra\n", 4);
	if (node->val == 41)
		write(1, "rrb\n", 4);
	if (node->val == 42)
		write(1, "rrr\n", 4);
}

void	ft_print_instructions(t_stack **insts)
{
	t_stack	*node;

	while (insts && *insts)
	{
		node = st_pop(insts);
		ft_print_instruction(node);
		free(node);
	}
}
