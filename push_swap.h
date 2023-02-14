/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadiyamu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:46:18 by tadiyamu          #+#    #+#             */
/*   Updated: 2023/01/14 17:32:27 by tadiyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack {
	struct s_stack	*tail;
	int				val;
}	t_stack;

int		st_len(t_stack *a);

t_stack	*st_pop(t_stack **a);

t_stack	*st_create_node(int val);

void	st_push(t_stack **stack, t_stack *node);

void	st_clear(t_stack **stack);

void	ft_swap_a(t_stack **stack, t_stack **insts);

void	ft_swap_b(t_stack **stack, t_stack **insts);

void	ft_swap_ss(t_stack **a, t_stack **b, t_stack **insts);

void	ft_push_logic(t_stack **s, t_stack **d);

void	ft_push_a(t_stack **b, t_stack **a, t_stack **insts);

void	ft_push_b(t_stack **a, t_stack **b, t_stack **insts);

void	ft_rotate_logic(t_stack **stack);

void	ft_rotate_a(t_stack **a, t_stack **insts);

void	ft_rotate_b(t_stack **b, t_stack **insts);

void	ft_rotate_rr(t_stack **a, t_stack **b, t_stack **insts);

void	ft_rrotate_logic(t_stack **stack);

void	ft_rrotate_a(t_stack **a, t_stack **insts);

void	ft_rrotate_b(t_stack **b, t_stack **insts);

void	ft_rrotate_rrr(t_stack **a, t_stack **b, t_stack **insts);

int		ft_median(t_stack *a, int size);

void	ft_quick_sort(int *arr, int l, int r);

int		ft_check_stack(t_stack *a, int size);

int		st_check_part(t_stack *st, int size, int piv);

void	st_sort_three_a(t_stack **a, int size, t_stack **insts);

int		st_find_min_three(t_stack *a);

void	st_part_three_b(t_stack **a, t_stack **b, int size, t_stack **insts);

void	st_quick_sort_a(t_stack **a, t_stack **b, int size, t_stack **insts);

void	st_quick_sort_b(t_stack **a, t_stack **b, int size, t_stack **insts);

void	ft_instruction_add(t_stack **insts);

void	ft_print_instructions(t_stack **insts);

int		ft_init_stack(t_stack **a, int argc, char **argv);

int		ft_arg_split_stack(t_stack **a, int argc, char **argv);

int		ft_arg_to_arr(char *arg, char ***res);

void	ft_split_free(char ***res);

#endif
