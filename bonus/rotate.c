/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:04:28 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/09 12:46:36 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack **a)
{
	t_stack	*first;

	if (*a == NULL)
		return ;
	first = *a;
	ft_lstlast(*a)->next = first;
	*a = first->next;
	first->next = NULL;
}

void	rb(t_stack **b)
{
	t_stack	*first;

	if (*b == NULL)
		return ;
	first = *b;
	ft_lstlast(*b)->next = first;
	*b = first->next;
	first->next = NULL;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
