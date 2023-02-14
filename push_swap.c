/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadiyamu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:03:33 by tadiyamu          #+#    #+#             */
/*   Updated: 2023/01/15 13:28:34 by tadiyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

// void	print_stack_visual(t_stack *a, t_stack *b)
// {
// 	// int	i;

// 	// while (a || b)
// 	// {
// 	// 	// i = 0;
// 	// 	// if (a)
// 	// 	// printf("%.3d", a->val);
// 	// 	// else
// 	// 	// 	printf("   ");
// 	// 	// while (i < 30)
// 	// 	// {
// 	// 	// 	printf(" ");
// 	// 	// 	i++;
// 	// 	// }
// 	// 	// if (b)
// 	// 	// 	printf("%.3d", b->val);
// 	// 	// else
// 	// 	// 	printf("   ");
// 	// 	// printf("\n");
// 		if (a)
// 			a = a->tail;
// 		if (b)
// 			b = b->tail;
// 	// }
// }

void	ft_arg_to_arr_free(t_stack **a, t_stack **b, t_stack **c)
{
	st_clear(a);
	st_clear(b);
	st_clear(c);
}

int	ft_arg_error(t_stack **a, t_stack **b, t_stack **c)
{
	ft_arg_to_arr_free(a, b, c);
	write(2, "Error\n", 6);
	return (0);
}

void	ft_sort_three(t_stack **a, t_stack **insts)
{
	int	i;

	i = st_find_min_three(*a);
	if (i == 0)
	{
		ft_rotate_a(a, insts);
		ft_swap_a(a, insts);
		ft_rrotate_a(a, insts);
	}
	else if (i == 1)
	{
		if ((*a)->val > (*a)->tail->tail->val)
			ft_rotate_a(a, insts);
		else
			ft_swap_a(a, insts);
	}
	else
	{
		if ((*a)->val > (*a)->tail->val)
			ft_swap_a(a, insts);
		ft_rrotate_a(a, insts);
	}
}

void	ft_call_sort(t_stack **a, t_stack **b, int size, t_stack **insts)
{
	if (!ft_check_stack(*a, size))
	{
		if (size == 3)
			ft_sort_three(a, insts);
		else if (size < 3)
			st_sort_three_a(a, size, insts);
		else
			st_quick_sort_a(a, b, size, insts);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*insts;
	int		fargc;

	if (argc > 1)
	{
		a = 0;
		b = 0;
		insts = 0;
		fargc = ft_arg_split_stack(&a, argc - 1, argv);
		if (fargc == 0)
			return (ft_arg_error(&a, &b, &insts));
		ft_call_sort(&a, &b, st_len(a), &insts);
		ft_instruction_add(&insts);
		ft_print_instructions(&insts);
		ft_arg_to_arr_free(&a, &b, &insts);
	}
	return (0);
}
