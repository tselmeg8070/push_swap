/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadiyamu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:10:38 by tadiyamu          #+#    #+#             */
/*   Updated: 2023/01/23 14:10:40 by tadiyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	ft_check_val(char *str, int val)
{
	int	dig;

	dig = 0;
	if (val < 0)
		dig++;
	if (val == 0 && ft_strncmp(str, "0", 1) != 0)
		return (0);
	if (val == 0)
		dig = 1;
	while (val != 0)
	{
		dig++;
		val /= 10;
	}
	if (dig == (int) ft_strlen(str))
		return (1);
	return (0);
}

int	ft_check_duplicates(t_stack *a, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	i = 0;
	while (a)
	{
		arr[i++] = a->val;
		a = a->tail;
	}
	ft_quick_sort(arr, 0, size - 1);
	i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[i + 1])
		{
			free(arr);
			return (0);
		}
		i++;
	}
	free(arr);
	return (1);
}

int	ft_init_stack(t_stack **a, int argc, char **argv)
{
	t_stack	*temp;
	int		i;
	int		val;

	i = 0;
	while (i < argc)
	{
		temp = 0;
		val = ft_atoi(argv[argc - i - 1]);
		if (ft_check_val(argv[argc - i - 1], val))
			temp = st_create_node(val);
		if (!temp)
		{
			st_clear(a);
			return (0);
		}
		st_push(a, temp);
		i++;
	}
	return (ft_check_duplicates(*a, st_len(*a)));
}

int	ft_arg_to_arr(char *arg, char ***res)
{
	int		i;

	i = 0;
	*res = ft_split(arg, ' ');
	while ((*res) && (*res)[i] != 0)
		i++;
	return (i);
}

int	ft_arg_split_stack(t_stack **a, int argc, char **argv)
{
	int		i;
	int		size;
	char	**strs;

	i = 0;
	while (i < argc)
	{
		size = ft_arg_to_arr(argv[argc - i], &strs);
		if (size == 0 || !ft_init_stack(a, size, strs))
		{
			ft_split_free(&strs);
			return (0);
		}
		ft_split_free(&strs);
		i++;
	}
	return (1);
}
