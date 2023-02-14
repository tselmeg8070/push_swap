/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_excute_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadiyamu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:03:33 by tadiyamu          #+#    #+#             */
/*   Updated: 2023/01/25 20:40:36 by tadiyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "./libft/libft.h"

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

int	ft_excute_inst2(t_stack **a, t_stack **b, char *inst)
{
	if (!ft_strncmp(inst, "ra\n", 3))
		ft_rotate_logic(a);
	else if (!ft_strncmp(inst, "rb\n", 3))
		ft_rotate_logic(b);
	else if (!ft_strncmp(inst, "rr\n", 3))
	{
		ft_rotate_logic(a);
		ft_rotate_logic(b);
	}
	else if (!ft_strncmp(inst, "rra\n", 4))
		ft_rrotate_logic(a);
	else if (!ft_strncmp(inst, "rrb\n", 4))
		ft_rrotate_logic(b);
	else if (!ft_strncmp(inst, "rrr\n", 4))
	{
		ft_rrotate_logic(a);
		ft_rrotate_logic(b);
	}
	else
		return (0);
	return (1);
}

int	ft_excute_inst(t_stack **a, t_stack **b, char *inst)
{
	if (!ft_strncmp(inst, "sa\n", 3))
		ft_swap_logic(a);
	else if (!ft_strncmp(inst, "sb\n", 3))
		ft_swap_logic(b);
	else if (!ft_strncmp(inst, "ss\n", 3))
	{
		ft_swap_logic(a);
		ft_swap_logic(b);
	}
	else if (!ft_strncmp(inst, "pa\n", 3))
		ft_push_logic(b, a);
	else if (!ft_strncmp(inst, "pb\n", 3))
		ft_push_logic(a, b);
	else
		return (ft_excute_inst2(a, b, inst));
	return (1);
}
