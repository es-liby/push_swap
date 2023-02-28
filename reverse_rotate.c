/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:44:15 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/14 10:44:16 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*last;

	if (ft_lstsize(*a) <= 1)
		return ;
	last = ft_lstlast(*a);
	last->next = *a;
	(*a)->prev = last;
	last->prev->next = NULL;
	last->prev = NULL;
	*a = last;
	ft_fprintf(1, "rra\n");
}

void	rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*temp;

	if (ft_lstsize(*b) <= 1)
		return ;
	last = ft_lstlast(*b);
	temp = last->prev;
	last->next = *b;
	(*b)->prev = last;
	temp->next = NULL;
	last->prev = NULL;
	*b = last;
	ft_fprintf(1, "rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*last;

	if (ft_lstsize(*a) > 1)
	{
		last = ft_lstlast(*a);
		last->next = *a;
		(*a)->prev = last;
		last->prev->next = NULL;
		last->prev = NULL;
		*a = last;
	}
	if (ft_lstsize(*b) > 1)
	{
		last = ft_lstlast(*b);
		last->next = *b;
		(*b)->prev = last;
		last->prev->next = NULL;
		last->prev = NULL;
		*b = last;
	}
	ft_fprintf(1, "rrr\n");
}
