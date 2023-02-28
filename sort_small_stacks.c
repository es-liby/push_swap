/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:44:39 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/19 09:18:39 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_stack **a)
{
	if (a_is_sorted(*a))
		return ;
	if (ft_lstsize(*a) == 2)
	{
		sa(*a);
		return ;
	}
	if ((*a)->n > (*a)->next->n && (*a)->n > (*a)->next->next->n)
	{
		if ((*a)->next->n < (*a)->next->next->n)
			rra(a);
		else
			sa(*a);
		sort_three_a(a);
	}
	if ((*a)->n > (*a)->next->n && (*a)->n < (*a)->next->next->n)
		sa(*a);
	if ((*a)->n > (*a)->next->n && (*a)->next->n < (*a)->next->next->n)
		rra(a);
	if ((*a)->n < (*a)->next->n && (*a)->next->n > (*a)->next->next->n)
	{
		rra(a);
		sort_three_a(a);
	}
}

void	push_min(t_stack **a)
{
	t_stack	*s;
	int		size;
	int		smallest;
	int		counter;

	smallest = get_smallest(*a);
	size = ft_lstsize(*a);
	counter = 0;
	s = *a;
	while (s)
	{
		if (s->n == smallest)
			break ;
		s = s->next;
		++counter;
	}
	if (counter == 0)
		return ;
	if (counter <= ft_lstsize(*a) / 2)
		rs_machine(a, counter, ra);
	else
		rrs_machine(a, size - counter, rra);
}

void	sort_five(t_stack **a, t_stack **b)
{
	push_min(a);
	pb(b, a);
	push_min(a);
	pb(b, a);
	sort_three_a(a);
	pa(a, b);
	pa(a, b);
}
