/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_st.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadiyamu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:17:21 by tadiyamu          #+#    #+#             */
/*   Updated: 2023/01/14 17:15:01 by tadiyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_logic(t_stack **s, t_stack **d)
{
	t_stack	*top;

	top = st_pop(s);
	if (top)
		st_push(d, top);
}

void	ft_push_a(t_stack **b, t_stack **a, t_stack **insts)
{
	ft_push_logic(b, a);
	st_push(insts, st_create_node(20));
}

void	ft_push_b(t_stack **a, t_stack **b, t_stack **insts)
{
	ft_push_logic(a, b);
	st_push(insts, st_create_node(21));
}
