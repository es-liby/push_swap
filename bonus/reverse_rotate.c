/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:45:31 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/14 10:45:32 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*temp;
	int		size;

	if (*a == NULL)
		return ;
	last = ft_lstlast(*a);
	size = ft_lstsize(*a) - 1;
	temp = *a;
	while (--size > 0)
		temp = temp->next;
	last->next = *a;
	*a = last;
	temp->next = NULL;
}

void	rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*temp;
	int		size;

	if (*b == NULL)
		return ;
	last = ft_lstlast(*b);
	size = ft_lstsize(*b) - 1;
	temp = *b;
	while (--size > 0)
		temp = temp->next;
	last->next = *b;
	*b = last;
	temp->next = NULL;
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
