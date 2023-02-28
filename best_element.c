/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:42:53 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/14 13:28:52 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*best_element(t_stack *b)
{
	t_stack	*s;
	int		smallest_sum;
	int		sum;

	if (b == NULL)
		return (NULL);
	smallest_sum = ft_abs(b->index_a) + ft_abs(b->index_b);
	s = b;
	b = b->next;
	while (b)
	{
		sum = ft_abs(b->index_a) + ft_abs(b->index_b);
		if (smallest_sum >= sum)
		{
			smallest_sum = sum;
			s = b;
		}
		b = b->next;
	}
	return (s);
}

void	put_smallest_on_top(t_stack **temp)
{
	t_stack	*s;
	int		size;
	int		smallest;
	int		counter;

	smallest = get_smallest(*temp);
	size = ft_lstsize(*temp);
	s = *temp;
	counter = 0;
	while (s)
	{
		if (s->n == smallest)
			break ;
		counter++;
		s = s->next;
	}
	if (counter <= size / 2)
		rs_machine(temp, counter, rt);
	else
	{
		counter = size - counter;
		rrs_machine(temp, counter, rrt);
	}
}

void	put_smallest_on_top_a(t_stack **a)
{
	t_stack	*s;
	int		size;
	int		smallest;
	int		counter;

	smallest = get_smallest(*a);
	size = ft_lstsize(*a);
	s = *a;
	counter = 0;
	while (s)
	{
		if (s->n == smallest)
			break ;
		counter++;
		s = s->next;
	}
	if (counter < size / 2)
		rs_machine(a, counter, ra);
	else
	{
		counter = size - counter;
		rrs_machine(a, counter, rra);
	}
}
