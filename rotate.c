/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:04:28 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/12 19:18:14 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (ft_lstsize(*a) <= 1)
		return ;
	first = *a;
	last = ft_lstlast(*a);
	last->next = first;
	first->prev = last;
	*a = first->next;
	(*a)->prev = NULL;
	first->next = NULL;
	ft_fprintf(1, "ra\n");
}

void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (ft_lstsize(*b) <= 1)
		return ;
	first = *b;
	last = ft_lstlast(*b);
	last->next = first;
	first->prev = last;
	*b = first->next;
	(*b)->prev = NULL;
	first->next = NULL;
	ft_fprintf(1, "rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (ft_lstsize(*a) > 1)
	{
		first = *a;
		last = ft_lstlast(*a);
		last->next = first;
		first->prev = last;
		*a = first->next;
		(*a)->prev = NULL;
		first->next = NULL;
	}
	if (ft_lstsize(*b) > 1)
	{
		first = *b;
		last = ft_lstlast(*b);
		last->next = first;
		first->prev = last;
		*b = first->next;
		(*b)->prev = NULL;
		first->next = NULL;
	}
	ft_fprintf(1, "rr\n");
}
