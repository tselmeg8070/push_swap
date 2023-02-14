/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadiyamu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:46:18 by tadiyamu          #+#    #+#             */
/*   Updated: 2023/01/25 20:41:40 by tadiyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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

void	ft_swap_logic(t_stack **stack);

void	ft_push_logic(t_stack **s, t_stack **d);

void	ft_rotate_logic(t_stack **stack);

void	ft_rrotate_logic(t_stack **stack);

int		ft_check_stack(t_stack *a, int size);

void	ft_quick_sort(int *arr, int l, int r);

int		ft_init_stack(t_stack **a, int argc, char **argv);

int		ft_arg_split_stack(t_stack **a, int argc, char **argv);

int		ft_arg_to_arr(char *arg, char ***res);

void	ft_split_free(char ***res);

int		ft_excute_inst(t_stack **a, t_stack **b, char *inst);

#endif
