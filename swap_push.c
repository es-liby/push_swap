/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:32:21 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/14 09:03:20 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*top;

	top = *b;
	*b = top->next;
	if (*b != NULL)
		(*b)->prev = NULL;
	ft_lstadd_front(a, top);
	ft_fprintf(1, "pa\n");
}

void	pb(t_stack **b, t_stack **a)
{
	t_stack	*top;

	top = *a;
	*a = top->next;
	if (*a != NULL)
		(*a)->prev = NULL;
	ft_lstadd_front(b, top);
	ft_fprintf(1, "pb\n");
}

void	sa(t_stack *a)
{
	int	temp;

	if (ft_lstsize(a) <= 1)
		return ;
	temp = a->n;
	a->n = a->next->n;
	a->next->n = temp;
	ft_fprintf(1, "sa\n");
}

void	sb(t_stack *b)
{
	int	temp;

	if (ft_lstsize(b) <= 1)
		return ;
	temp = b->n;
	b->n = b->next->n;
	b->next->n = temp;
	ft_fprintf(1, "sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp;

	if (ft_lstsize(a) > 1)
	{
		temp = a->n;
		a->n = a->next->n;
		a->next->n = temp;
	}
	if (ft_lstsize(b) > 1)
	{
		temp = b->n;
		b->n = b->next->n;
		b->next->n = temp;
	}
	ft_fprintf(1, "ss\n");
}
