/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:32:21 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/09 12:47:06 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*top;

	if (*b == NULL)
		return ;
	top = *b;
	*b = top->next;
	ft_lstadd_front(a, top);
}

void	pb(t_stack **b, t_stack **a)
{
	t_stack	*top;

	if (*a == NULL)
		return ;
	top = *a;
	*a = top->next;
	ft_lstadd_front(b, top);
}

void	sa(t_stack *a)
{
	int	temp;

	if (ft_lstsize(a) <= 1)
		return ;
	temp = a->n;
	a->n = a->next->n;
	a->next->n = temp;
}

void	sb(t_stack *b)
{
	int	temp;

	if (ft_lstsize(b) <= 1)
		return ;
	temp = b->n;
	b->n = b->next->n;
	b->next->n = temp;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
