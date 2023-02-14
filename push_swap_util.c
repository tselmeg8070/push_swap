/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadiyamu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:03:33 by tadiyamu          #+#    #+#             */
/*   Updated: 2023/01/15 17:02:44 by tadiyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_quick_part(int *arr, int l, int r)
{
	int	piv;
	int	i;
	int	j;
	int	tmp;

	i = l - 1;
	j = l;
	piv = arr[r];
	while (j <= r - 1)
	{
		if (arr[j] < piv)
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
		j++;
	}
	tmp = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = tmp;
	return (i + 1);
}

void	ft_quick_sort(int *arr, int l, int r)
{
	int	piv;

	if (l >= r)
		return ;
	piv = ft_quick_part(arr, l, r);
	ft_quick_sort(arr, l, piv - 1);
	ft_quick_sort(arr, piv + 1, r);
}

int	ft_median(t_stack *a, int size)
{
	int	*arr;
	int	median;
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (2147483647);
	while (a != 0 && size > 0 && i < size)
	{
		arr[i] = a->val;
		i++;
		a = a->tail;
	}
	ft_quick_sort(arr, 0, size - 1);
	median = arr[size / 2];
	free(arr);
	return (median);
}

int	ft_check_stack(t_stack *a, int size)
{
	int	c;
	int	i;

	i = 0;
	c = -2147483648;
	while (a && i < size)
	{
		if (c > a->val)
			return (0);
		c = a->val;
		a = a->tail;
		i++;
	}
	return (1);
}

void	ft_split_free(char ***res)
{
	int	i;

	i = 0;
	while ((*res) && (*res)[i] != 0)
	{
		free((*res)[i]);
		i++;
	}
	free(*res);
}
