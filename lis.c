/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:43:29 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/23 09:08:00 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

static t_lis	*get_lis(int *arr, int *sub, int *l, int size);
static void		handle(int *arr, int *sub, int *l, int size);
static int		get_largest_lis(int *l, int size, int *indx);
t_lis			*ft_alloc(int *arr, int *sub, int *l);
void			free_lis(t_lis *lis, int *arr, int *sub, int *l);
int				check_helper(int *arr, int *sub, int *l);

t_lis	*find_lis(int *arr, int size)
{
	t_lis	*lis;
	int		*l;
	int		*sub;
	int		i;

	l = malloc(size * sizeof(int));
	sub = malloc(size * sizeof(int));
	if (check_helper(arr, sub, l) == 0)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		l[i] = 1;
		sub[i] = -1;
	}
	handle(arr, sub, l, size);
	lis = get_lis(arr, sub, l, size);
	free(arr);
	free(sub);
	free(l);
	return (lis);
}

static t_lis	*get_lis(int *arr, int *sub, int *l, int size)
{
	t_lis	*lis;
	int		indx;
	int		len;

	lis = ft_alloc(arr, sub, l);
	if (lis == NULL)
		return (NULL);
	lis->len = get_largest_lis(l, size, &indx);
	len = lis->len;
	lis->arr = malloc(lis->len * sizeof(int));
	if (lis->arr == NULL)
	{
		free_lis(lis, arr, sub, l);
		return (NULL);
	}
	(lis->arr)[--len] = arr[indx];
	indx = sub[indx];
	while (--len >= 0)
	{
		(lis->arr)[len] = arr[indx];
		indx = sub[indx];
	}
	return (lis);
}

static void	handle(int *arr, int *sub, int *l, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && l[j] + 1 >= l[i])
			{
				l[i] = l[j] + 1;
				sub[i] = j;
			}
			j++;
		}
		i++;
	}
}

static int	get_largest_lis(int *l, int size, int *indx)
{
	int	largest;

	largest = l[--size];
	*indx = size;
	while (--size >= 0)
	{
		if (largest < l[size])
		{
			largest = l[size];
			*indx = size;
		}
	}
	return (largest);
}
