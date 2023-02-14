/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadiyamu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:03:33 by tadiyamu          #+#    #+#             */
/*   Updated: 2023/01/25 20:41:34 by tadiyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "./libft/libft.h"
#include "get_next_line_bonus.h"

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

int	ft_get_instructions(t_stack **a, t_stack **b)
{
	char	*line;
	int		res;

	line = "";
	while (line)
	{
		line = get_next_line(0);
		if (line)
			res = ft_excute_inst(a, b, line);
		free(line);
		if (!res)
			return (0);
	}
	return (1);
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
		if (!ft_get_instructions(&a, &b))
			return (ft_arg_error(&a, &b, &insts));
		if (ft_check_stack(a, st_len(a)) && st_len(b) == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_arg_to_arr_free(&a, &b, &insts);
	}
	return (0);
}
