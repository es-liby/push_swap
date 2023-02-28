/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:41:33 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/13 11:47:56 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_largest(t_stack *a)
{
	int	largest;

	largest = a->n;
	a = a->next;
	while (a)
	{
		if (largest <= a->n)
			largest = a->n;
		a = a->next;
	}
	return (largest);
}

int	get_smallest(t_stack *s)
{
	int	smallest;

	smallest = s->n;
	s = s->next;
	while (s)
	{
		if (s->n < smallest)
			smallest = s->n;
		s = s->next;
	}
	return (smallest);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}
