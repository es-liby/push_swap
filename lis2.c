/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:43:18 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/23 09:22:12 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lis	*ft_alloc(int *arr, int *sub, int *l)
{
	t_lis	*lis;

	lis = malloc(sizeof(t_lis));
	if (lis == NULL)
	{
		free(arr);
		arr = NULL;
		free(sub);
		sub = NULL;
		free(l);
		l = NULL;
		return (NULL);
	}
	return (lis);
}

void	free_lis(t_lis *lis, int *arr, int *sub, int *l)
{
	free(lis);
	lis = NULL;
	free(arr);
	arr = NULL;
	free(sub);
	sub = NULL;
	free(l);
	l = NULL;
}

int	check_helper(int *arr, int *sub, int *l)
{
	if (l == NULL)
	{
		free(arr);
		arr = NULL;
		free(sub);
		sub = NULL;
	}
	if (sub == NULL)
	{
		free(arr);
		arr = NULL;
		free(l);
		l = NULL;
	}
	if (l == NULL || sub == NULL)
		return (0);
	return (1);
}
